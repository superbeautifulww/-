#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QString>
#include"image_enhancement.h"
#include<QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QString filePath;
    QImage img;
    QImage grayimg;

    image_enhancement I;


private slots:
    void on_choose_picture_clicked();

    void on_normalization_button_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
