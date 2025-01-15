#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QFileDialog>
#include"bayes.h"
#include<QMouseEvent>
#include"fisher.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_choose_picture_clicked();

    void on_bayes_clicked();

    void on_road_choose_clicked();

    void on_field_choose_clicked();

    void on_building_choose_clicked();

    void on_water_choose_clicked();

    void mousePressEvent(QMouseEvent* event);

    void on_Fisher_clicked();

private:
    Ui::Widget *ui;

    QString filePath;
    bayes b;
    fisher f;


    QVector<QVector<int>> water_sample;
    QVector<QVector<int>> field_sample;
    QVector<QVector<int>> road_sample;
    QVector<QVector<int>> building_sample;

    int sample_flag=0;

};
#endif // WIDGET_H
