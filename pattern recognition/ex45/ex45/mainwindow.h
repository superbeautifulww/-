#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"bayes.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




    /*
    QVector<QVector<int>> bayes_water_sample;

    QVector<QVector<int>> bayes_field_sample;

    QVector<QVector<int>> bayes_road_sample;
    QVector<QVector<int>> bayes_building_sample;

    QVector<QVector<int>> fisher_water_sample;
    QVector<QVector<int>> fisher_field_sample;
    QVector<QVector<int>> fisher_road_sample;
    QVector<QVector<int>> fisher_building_sample;
    */





private slots:
    void on_picture_botton_clicked();

    //void on_building_botton_clicked();

    void on_building_botton_clicked();

private:
    Ui::MainWindow *ui;

    QPixmap loadDatImage(const QString& filePath);
    QString filePath;
    Bayes b;



};
#endif // MAINWINDOW_H
