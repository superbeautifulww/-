
#ifndef WIDGET_H
#define WIDGET_H
#pragma execution_character_set("utf-8")
#include <QWidget>
#include<QLabel>
#include"threshold.h"
#include"Bayes.h"
#include<QMouseEvent>
#include<QPixmap>
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
    void on_choosepicture_clicked();

    void on_singleshow_clicked();

    void on_show_histogram_clicked();

    void on_thresholding_clicked();

    void on_Bayes_button_clicked();

    void mousePressEvent(QMouseEvent* event);





    void on_fisher_button_clicked();

    void on_bayes_start_clicked();

    void on_fisher_start_clicked();

    void on_bayes_back_clicked();

    void on_fisher_back_clicked();

private:
    Ui::Widget *ui;
    QString filePath;
    threshold w;
    Bayes b;
    Fisher f;
    QVector<QVector<int>> bayes_back_sample;
    QVector<QVector<int>> fisher_back_sample;
    QVector<QVector<int>> bayes_target_sample;
    QVector<QVector<int>> fisher_target_sample;
    int fisher_tag=0;
    int bayes_tag=0;



};
#endif // WIDGET_H

