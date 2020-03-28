#ifndef METHOD3_H
#define METHOD3_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QTextStream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

namespace Ui {
class Method3;
}

class Method3 : public QDialog
{
    Q_OBJECT

public:
    explicit Method3(QWidget *parent = nullptr, string path_ = "");
    ~Method3();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Method3 *ui;
    string path;
};

#endif // METHOD3_H
