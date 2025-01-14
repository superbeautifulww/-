#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<opencv2/opencv.hpp>
#include <QMainWindow>
#include<QString>
#include<vector>


using namespace std;
using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void init();
    ~MainWindow();



private slots:

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();





    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;

    void color_distribution(Mat img,int result[]);
    uchar color_hash(uchar &val);
    double cdcompare(int t1[],Mat img2);

    QString aHash(Mat img);
    QString pHash(Mat img);
    QString dHash(Mat img);
    int acompare(QString str1,Mat img2);
    int pcompare(QString str1,Mat img2);
    int dcompare(QString str1,Mat img2);


};
#endif // MAINWINDOW_H
