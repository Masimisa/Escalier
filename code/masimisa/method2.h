#ifndef METHOD2_H
#define METHOD2_H

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
class Method2;
}

class Method2 : public QDialog
{
    Q_OBJECT

public:
    explicit Method2(QWidget *parent = nullptr, string path_ = "");
    ~Method2();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Method2 *ui;
    string path;
};
#endif // METHOD2_H
