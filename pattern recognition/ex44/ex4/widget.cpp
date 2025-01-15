#include "widget.h"
#include "ui_widget.h"
#include<QPainter>


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
    if (!filePath.isEmpty()) {
        QPixmap pixmap(filePath);
        ui->show_label->setPixmap(pixmap.scaled(ui->show_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->show_label->setAlignment(Qt::AlignCenter);
    }
}


void Widget::on_bayes_clicked()
{
    QVector<QVector<double>> prob_road,prob_water,prob_building,prob_field;
    b.train(road_sample,prob_road);
    b.train(water_sample,prob_water);
    b.train(building_sample,prob_building);
    b.train(field_sample,prob_field);
    QImage img(filePath);
    QImage resimg=b.predict(prob_road,prob_water,prob_building,prob_field,img);
    QPixmap pixmap = QPixmap::fromImage(resimg);
    ui->show_label->setPixmap(pixmap.scaled(ui->show_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->show_label->setAlignment(Qt::AlignCenter);

}


void Widget::mousePressEvent(QMouseEvent* event) {

    if (!ui->show_label->pixmap().isNull()&&event->button() == Qt::LeftButton) {
        QPoint pos = event->pos();
        pos = ui->show_label->mapFrom(this, pos);
        QPixmap pixmap = ui->show_label->pixmap().copy();

        QColor color = pixmap.toImage().pixelColor(pos);

        int red = color.red();
        int green = color.green();
        int blue = color.blue();

        QVector<int> rgb = {red, green, blue};
        QPainter painter(&pixmap);
        if(sample_flag==1)
        {
            road_sample.push_back(rgb);
            painter.setPen(qRgb(255, 255, 0));
        }
        else if(sample_flag==2) {
            field_sample.push_back(rgb);
            painter.setPen(qRgb(0, 128, 0));
        }
        else if(sample_flag==3) {
            building_sample.push_back(rgb);
            painter.setPen(qRgb(255, 0, 0));
        }
        else if(sample_flag==4) {
            water_sample.push_back(rgb);
            painter.setPen(qRgb(0,0, 255));
        }


        painter.drawEllipse(pos, 1, 1);

        ui->show_label->setPixmap(pixmap);
    }

}


void Widget::on_road_choose_clicked()
{
    sample_flag=1;
}


void Widget::on_field_choose_clicked()
{
    sample_flag=2;
}


void Widget::on_building_choose_clicked()
{
    sample_flag=3;
}


void Widget::on_water_choose_clicked()
{
    sample_flag=4;
}


void Widget::on_Fisher_clicked()
{
    QImage img(filePath);
    QImage resimg=f.fisherClassify(img,road_sample,field_sample,water_sample,building_sample);
    QPixmap pixmap = QPixmap::fromImage(resimg);
    ui->show_label->setPixmap(pixmap.scaled(ui->show_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->show_label->setAlignment(Qt::AlignCenter);
}

