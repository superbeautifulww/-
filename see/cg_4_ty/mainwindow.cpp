#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<cmath>
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


void MainWindow::on_action_triggered()
{
    ui->openGLWidget->zzty();
}

void MainWindow::on_action_2_triggered()
{
    double x=acos(-1)/4.0,y=acos(-1)/4.0;
    ui->openGLWidget->xzty(x,y);
}

void MainWindow::on_action_3_triggered()
{
    double x=atan(2),y=acos(-1)/4.0;
    ui->openGLWidget->xzty(x,y);
}

void MainWindow::on_actionthree_triggered()
{
    double t=acos(-1)/6.0;
    t=-t;
    ui->openGLWidget->t1(0.25,-0.2,-0.15,t,t);
}
