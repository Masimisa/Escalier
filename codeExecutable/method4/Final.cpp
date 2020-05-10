/**
 * Sum of appearing lines.
 *
 * We are evaluating the number of steps through multiple images detection functions. 
 * The cumulative steps are displayed in the UI.
 *
 * @author : Chansuk
 * @Date : 05/07/2020
 */


#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

Mat img, src, dst, gray, edges, bw, result, img_o, ctrl;

const char* source = "Source";

/**
*
* Pre processing parameters:
*
* @param: operator : Opening - 1: Closing - 2: Gradient - 3: Top Hat - 4: Black Hat | from the morphological transformation
* @param: element: Cross - Rect - Ellipse | modify the shape of the kernel 
* @param: kernel size: | self explanatory
*/
int morph_operator = 4;
int morph_elem = 1;
int morph_size = 10;
int hori=0;
int const max_operator = 4;
int const max_elem = 2;
int const max_kernel_size = 21;
int const max_hori = 1;
const char* morph = "Morph";
void Morphology_Operations(int, void*);

/**
*
* Hough transform parameters:
*
* @param: length : minimal length of the line (in pixel)
* @param: gap : maximum gap between each line (in pixel)
* @param: thresh: threshold from the houghP function (pixel value)
*/
int length = 50;
int gap = 5;
int thresh = 170;
const int max_length = 200;
const int max_gap = 200;
const int max_thresh = 255;
const char* standard_name = "Hough Lines";
void Hough(int, void*);

int main(int argc, char** argv) {
	
	//Loading image from folder
	img = imread("./images/i.jpg");
	if (img.empty()) {
		std::cout << "Could not open or find the image!\n" << std::endl;
		return EXIT_FAILURE;
	}

	//If any glare shows up, convert it to Lab color.
	cvtColor(img, src, COLOR_RGB2Lab);

	//If not pursue with the (Mat) img variable

	//processing
	namedWindow(morph, WINDOW_FREERATIO); 
	//imshow(source, img);
	

	// Trackbar for the morphological operations
	createTrackbar("Operator:\n 0: Opening - 1: Closing  \n 2: Gradient - 3: Top Hat \n 4: Black Hat", morph,
		&morph_operator, max_operator,
		Morphology_Operations);

	createTrackbar("Element:\n 0: Rect - 1: Cross - 2: Ellipse", morph,
		&morph_elem, max_elem, 
		Morphology_Operations);

	createTrackbar("Kernel size:\n 2n +1", morph,
		&morph_size, max_kernel_size,
		Morphology_Operations);

	createTrackbar("0: gray 1: hori", morph,
		&hori, max_hori,
		Morphology_Operations);
	
	Morphology_Operations(0, 0);

	waitKey(0);
	
	return 0;
}


// Morphological operations with parameters explained above
void Morphology_Operations(int, void*)
{

	// Since MORPH_X : 2,3,4,5 and 6
	int operation = morph_operator + 2;
	Mat element = getStructuringElement(morph_elem, Size(2 * morph_size + 1, 2 * morph_size + 1), Point(morph_size, morph_size));
	morphologyEx(img, dst, operation, element);
	
	//grey conversion
	if (dst.channels() == 3)
	{
		cvtColor(dst, gray, COLOR_BGR2GRAY);
	}
	else
	{
		gray = dst;
	}
	namedWindow(morph, WINDOW_FREERATIO);
	imshow(morph, gray);
	
	/*
	*	After processing, we can choose wheter or not to select horizontal lines.
	*/

	//Steps to obtain horizontal lines, from openCV tutorial

	adaptiveThreshold(gray, bw, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);
	// Create the images that will use to extract the horizontal and vertical lines
	Mat horizontal = bw.clone();
	// Specify size on horizontal axis
	int horizontal_size = horizontal.cols / 10;
	// Create structure element for extracting horizontal lines through morphology operations
	Mat horizontalStructure = getStructuringElement(MORPH_RECT, Size(horizontal_size, 1));
	// Apply morphology operations
	erode(horizontal, horizontal, horizontalStructure, Point(-1, -1));
	dilate(horizontal, horizontal, horizontalStructure, Point(-1, -1));

	//Step 1
	const char* cut = "cut";
	adaptiveThreshold(horizontal, edges, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 3, -2);
	// Step 2
	Mat kernel = Mat::ones(2, 2, CV_8UC1);
	dilate(edges, edges, kernel);
	// Step 3
	Mat smooth;
	horizontal.copyTo(smooth);
	// Step 4
	blur(smooth, smooth, Size(2, 2));
	// Step 5
	smooth.copyTo(horizontal, edges);
	
	if (hori) {
		horizontal.copyTo(result);
	}
	else {
		gray.copyTo(result);
	}

	// Detecting the edges in the picture needed for the hough transform
	// If horizontal mat isn't appropriate, pursue with the (Mat) gray variable
	
	//Trackbar for adjustments in the resulting the hough transform
	namedWindow(standard_name, WINDOW_FREERATIO);
	createTrackbar("Length", 
		standard_name, &length, max_length, 
		Hough);
	createTrackbar("Gap", 
		standard_name, &gap, max_gap, 
		Hough);
	createTrackbar("Threshold", 
		standard_name, &thresh, max_thresh, 
		Hough);
	
	Hough(0, 0);
	
}

/** Hough transformation with parameters explained above
*    
*/
void Hough(int, void*)
{
	vector<Vec4i> lines;
	
	Canny(result, edges, 80, 240, 3);

	// Converting gray to color image.
	cvtColor(edges, img_o, COLOR_GRAY2BGR);
	cvtColor(edges, ctrl, COLOR_GRAY2BGR);

	// Hough probabilistic function
	HoughLinesP(edges, lines, 10, CV_PI / 180, thresh, length, gap);

	for (size_t i = 1; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(ctrl, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, LINE_AA);
	}


	// Hough probabilistic function v2
	HoughLinesP(edges, lines, 1, CV_PI / 180, thresh, length, gap);

	Vec4i l = lines[0];
	line(img_o, Point(0, l[1]), Point(img.cols, l[1]), Scalar(0, 0, 255), 3, LINE_AA);
	

	vector<int> lines_keeper;
	lines_keeper.push_back(l[1]);

	int okey = 1;
	int stair_counter = 1;

	for (size_t i = 1; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		for (int m : lines_keeper)
		{
			if (abs(m - l[1]) < 10)
				okey = 0;

		}
		if (okey)
		{
			line(img_o, Point(0, l[1]), Point(img.cols, l[1]), Scalar(0, 0, 255), 3, LINE_AA);
			lines_keeper.push_back(l[1]);
			stair_counter++;
		}
		okey = 1;

	}
	putText(img_o, "Steps number:" + to_string(stair_counter), Point(40, 60), FONT_HERSHEY_DUPLEX, 1.5, Scalar(169, 240, 13), 2);
	imshow(standard_name,img_o);
	//imshow("control", control);
}

