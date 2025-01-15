#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_picture_botton_clicked()
{
    filePath = QFileDialog::getOpenFileName(this, tr("选择文件"), "", tr("所有文件 (*.*)"));
    if (!filePath.isEmpty()) {
        QPixmap pixmap(filePath);
        ui->picture_show_label->setPixmap(pixmap.scaled(ui->picture_show_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->picture_show_label->setAlignment(Qt::AlignCenter);
    }

}


/*

void MainWindow::on_building_botton_clicked()
{
    QVector<QVector<double>> prob_road,prob_water,prob_building,prob_field;
    b.train(bayes_road_sample,prob_road);
    b.train(bayes_water_sample,prob_water);
    b.train(bayes_building_sample,prob_building);
    b.train(bayes_field_sample,prob_field);
    QImage img(filePath);
    QImage resimg=b.predict(prob_road,prob_water,prob_building,prob_field,img);
    QPixmap pixmap = QPixmap::fromImage(resimg);
    ui->picture_show_label->setPixmap(pixmap.scaled(ui->picture_show_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->picture_show_label->setAlignment(Qt::AlignCenter);

}

*/
