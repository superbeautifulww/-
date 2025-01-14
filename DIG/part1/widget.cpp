#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_choose_picture_clicked()
{
     filePath = QFileDialog::getOpenFileName(this, tr("选择文件"), "", tr("所有文件 (*.*)"));
    img.load(filePath);
    grayimg = img.convertToFormat(QImage::Format_Grayscale8);
    QPixmap pixmap = QPixmap::fromImage(grayimg);

    ui->picture_show->setPixmap(pixmap.scaled(ui->picture_show->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->picture_show->setAlignment(Qt::AlignCenter);
    //绘制直方图
    QVector<int> h=I.cal_histogram(grayimg);
    I.draw_histogram(h,ui->start_histogram_show);


}


void Widget::on_normalization_button_clicked()
{
     QImage grayimgCopy = grayimg;
     QImage resimg=I.histogram_normalization(grayimgCopy,0,255);
    QPixmap pixmap = QPixmap::fromImage(resimg);
/*
     int width = resimg.width();
     int height = resimg.height();
     for(int y=0;y<height;y++)
         for(int x=0;x<width;x++)
         {
             qDebug("%d",qGray(resimg.pixel(x,y)));
         }
*/
    ui->res_show->setPixmap(pixmap.scaled(ui->res_show->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->res_show->setAlignment(Qt::AlignCenter);
    //绘制直方图

    QVector<int> h=I.cal_histogram(resimg);
    I.draw_histogram(h,ui->res_histogram_show);

}

