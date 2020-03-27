#ifndef METHOD1_H
#define METHOD1_H

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
class Method1;
}

class Method1 : public QDialog
{
    Q_OBJECT

public:

    explicit Method1(QWidget *parent = nullptr, string path_ = "");
    ~Method1();

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Method1 *ui;
    string path;
};

#endif // METHOD1_H
