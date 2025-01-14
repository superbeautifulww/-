#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"qcheckbox.h"
#include<vector>
#include<math.h>
#include<opencv2/opencv.hpp>
#include<QFileDialog>
#include<QDir>
#include<QFileInfo>
#include<QDateTime>
#include<QDebug>
#pragma execution_character_set("utf-8")


using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
    connect(ui->tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT (on_tableWidget_cellDoubleClicked(int row, int column)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::init()
{
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"文件名"<<"文件夹"<<"尺寸"<<"大小"<<"修改时间"<<"相似度");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior ( QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode ( QAbstractItemView::SingleSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
void MainWindow::color_distribution(Mat img,int result[])
{
    uchar b=0,g=0,r=0;
    int item=0;
    for (int i = 0; i < img.rows; i++)
        {
            uchar* p = img.ptr<uchar>(i);
            for (int j = 0; j < img.cols; j++)
            {
                r = color_hash(p[3*j + 2]);
                g = color_hash(p[3*j + 1]);
                b = color_hash(p[3*j]);
                item = b*16 + g*4 + r;
                result[item]++;
            }
         }
    return ;
}
uchar MainWindow::color_hash(uchar &val)
{
    if(val>=192) return 3;
    else if(val>=128) return 2;
    else if(val>=64) return 1;
    else return 0;
}
QString MainWindow::aHash(Mat img)
{
    cv::resize(img, img, Size(8, 8));
    cvtColor(img, img, COLOR_BGR2GRAY);
    uchar *p;
    int sum = 0;
    for (int i = 0; i < img.rows; i++)
    {
        p = img.ptr<uchar>(i);
        for (int j = 0; j < img.cols; j++)
        {
            p[j] = p[j] / 4;
            sum += p[j];
        }
    }
    int ave = sum / 64;
    QString res;
    for (int i = 0; i < img.rows; i++)
    {
        p = img.ptr<uchar>(i);
        for (int j = 0; j < img.cols; j++)
        {
            if (p[j] >= ave) res+='1';
            else res+= '0';
        }
    }
    return res;
}
QString MainWindow::dHash(Mat img)
{
    cv::resize(img, img, Size(9, 8));
    qDebug("yes1");
    cvtColor(img, img, COLOR_BGR2GRAY);
    uchar *p;
    for (int i = 0; i < img.rows; i++)
    {
        p = img.ptr<uchar>(i);
        for (int j = 0; j < img.cols; j++)
        {
            p[j] = p[j] / 4;
        }
    }
     qDebug("yes2");
    img.convertTo(img, CV_64F, 1.0/ 255);
     qDebug("yes3");
    QString result;
    for (int i = 0; i < img.rows; i++)
    {

        for (int j = 0; j < img.cols-1; j++)
        {
            if (img.at<double>(i, j) >= img.at<double>(i, j+1)) result += '1';
            else result += '0';
        }
    }
     qDebug("yes4");
    return result;
}
QString MainWindow::pHash(Mat img)
{
    cv::resize(img, img, Size(32, 32));
    Mat dst,img1;
    cvtColor(img, img, COLOR_BGR2GRAY);
    uchar *p;
    for (int i = 0; i < img.rows; i++)
    {
        p = img.ptr<uchar>(i);
        for (int j = 0; j < img.cols; j++)
        {
            p[j] = p[j] / 4;
        }
    }
    img.convertTo(img1, CV_64F, 1.0/ 255);
    dct(img1, dst);

    double d[64];
    double average=0;
    int k=0;
    for (int i = 0; i < 8; ++i)
    {
            for (int j = 0; j < 8; ++j)
            {
                d[k] = dst.at<double>(i, j);
                average += dst.at<double>(i, j) / 64;
                ++k;
            }
    }

    QString res;
    for (int i = 0; i < 64; i++)
    {
            if (d[i] >= average) res += '1';
            else res += '0';
    }

    return res;

   }
int MainWindow::pcompare(QString str1,Mat img2)
{
    QString str2=pHash(img2);
    if (str1.size() != str2.size()) return -1;
    int n=str1.size();
    int cnt=0;
    for (int i = 0; i <n; i++)
    {
        if (str1[i] == str2[i]) cnt++;
    }
    return cnt*25 / 16;
}

int MainWindow::acompare(QString str1,Mat img2)
{
    QString str2=aHash(img2);
    if (str1.size() != str2.size()) return -1;
    int cnt=0;
    int n=str1.size();
    for (int i = 0; i <n; i++)
    {
        if (str1[i] == str2[i]) cnt++;
    }
    return cnt*100 / 64;
}

double MainWindow::cdcompare(int t1[],Mat img2)
{
    int t2[64]={0};
    color_distribution(img2,t2);
    double average1=0.0,average2=0.0;
    double sum1 = 0, sum2 = 0, sum = 0;
    for(int i=0; i<64; i++)
    {
     average1 += t1[i];
     average2 += t2[i];
    }
    average1/=64.0;
    average2/=64.0;
        for (int i = 0; i < 64; i++)
        {
            sum1  += ( t1[i]-average1)*(t1[i]-average1);
            sum2 +=  (t2[i]-average2)*(t2[i]-average2) ;
            sum += (t2[i]-average2)*(t1[i]-average1);
        }
    double res=1.0*sum/(sqrt(fabs(sum1))*sqrt(fabs(sum2)));
    return res*100;
}

int MainWindow::dcompare(QString str1,Mat img2)
{
    QString str2=dHash(img2);
    if (str1.size() != str2.size()) return -1;
    int cnt=0;
    int n=str1.size();
    for (int i = 0; i <n; i++)
    {
        if (str1[i] == str2[i]) cnt++;
    }
    return cnt*25 / 16;
}


void MainWindow::on_pushButton_3_clicked()
{

    QString filename=ui->lineEdit->text();
    QString wayname=ui->comboBox->currentText();
    QFile file(filename);
    Mat img1;
       if(file.open(QFile::ReadOnly))
       {

           QByteArray ba = file.readAll();
           img1 = imdecode(vector<char>(ba.begin(), ba.end()), 1);
       }
   if(wayname=="Color Distribution")
    {
         int t1[64]={0};
         color_distribution(img1,t1);
         QString path=ui->textEdit->toPlainText();

         QDir dir(path);
         if(!dir.exists())return;
         QStringList filters;
         filters<<"*.jpg"<<"*.png"<<"*.bmp";
         dir.setNameFilters(filters);
         int dir_count=dir.count();
         if(dir_count<=0)return;
         QChar sep = QChar('/');
               if(!path.contains(sep))
               {
                 sep = QChar('\\');
               }
               QChar last_char = path.at(path.length()-1);
               if(last_char == sep)
               {
                 sep = QChar();
               }

         for(int i=0;i<dir_count;i++)
         {
             QString filename2=dir[i];
             QString file_path = path + sep + filename2;
             QFile file2(file_path);

             Mat img2;
             if(!file2.open(QFile::ReadOnly))
             {
                 qDebug("读取失败");
             }else{
                 QByteArray ba2 = file2.readAll();
                 img2 = imdecode(vector<char>(ba2.begin(), ba2.end()), 1);
             }
             if(img2.empty ()){
                 qDebug("图像为空");}

             double result=cdcompare(t1,img2);
             int biggest_similarity=ui->spinBox->value();
             int lm=0;
             if(biggest_similarity){
                 lm=biggest_similarity;
             }
             else lm=70;
             if(result>=lm){
             int rowcount = ui->tableWidget->rowCount();
             ui->tableWidget->insertRow(rowcount);
             for(int i=0;i<6;i++)
             ui->tableWidget->horizontalHeader()->setSectionResizeMode(i,QHeaderView::ResizeToContents);
             ui->tableWidget->setItem(rowcount, 0, new QTableWidgetItem(filename2));
             ui->tableWidget->setItem(rowcount, 1, new QTableWidgetItem(path));
             QString big=QString::number(img2.cols);
             big+="*";
             big+=QString::number(img2.rows);
             ui->tableWidget->setItem(rowcount, 2, new QTableWidgetItem(big));
             QString size=QString::number(file2.size()/1024)+"KB";
             ui->tableWidget->setItem(rowcount, 3, new QTableWidgetItem(size));
             QFileInfo info(file2);
             QString time=info.lastModified().toString(tr("yyyy/yy/yy"));
             ui->tableWidget->setItem(rowcount, 4,new QTableWidgetItem(time));
             ui->tableWidget->setItem(rowcount, 5, new QTableWidgetItem(QString::number(int(result))+"%"));
             }
         }



    }

   if(wayname=="Average Hash")
    {
        QString str1=aHash(img1);
        QString path=ui->textEdit->toPlainText();
        QDir dir(path);
        if(!dir.exists())return;
        QStringList filters;
        filters<<"*.jpg"<<"*.png"<<"*.bmp";
        dir.setNameFilters(filters);
        int dir_count=dir.count();
        if(dir_count<=0)return;
        QChar separator = QChar('/');
              if(!path.contains(separator))
              {
                separator = QChar('\\');
              }
              QChar last_char = path.at(path.length()-1);
              if(last_char == separator)
              {
                separator = QChar();
              }

        for(int i=0;i<dir_count;i++)
        {

            QString filename2=dir[i];
            QString file_path = path + separator + filename2;
            QFile file2(file_path);
            Mat img2;
            if(!file2.open(QFile::ReadOnly))
            {
                qDebug("读取失败");
            }else{
                QByteArray ba2 = file2.readAll();
                img2 = imdecode(vector<char>(ba2.begin(), ba2.end()), 1);
            }
            if(img2.empty ()){
                qDebug("图像为空");}

            int result=acompare(str1,img2);
            int biggest_similarity=ui->spinBox->value();
            int lm=0;
            if(biggest_similarity){
                lm=biggest_similarity;
            }
            else lm=84;
            if(result>lm){
            int rowcount = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rowcount);
            QString big=QString::number(img2.cols);
            for(int i=0;i<6;i++)
            ui->tableWidget->horizontalHeader()->setSectionResizeMode(i,QHeaderView::ResizeToContents);
            ui->tableWidget->setItem(rowcount, 0, new QTableWidgetItem(filename2));
            ui->tableWidget->setItem(rowcount, 1, new QTableWidgetItem(path));
            big+="*";
            big+=QString::number(img2.rows);
            ui->tableWidget->setItem(rowcount, 2, new QTableWidgetItem(big));
            QString size=QString::number(file2.size()/1024)+"KB";
            ui->tableWidget->setItem(rowcount, 3, new QTableWidgetItem(size));
            QFileInfo info(file2);
            QString time=info.lastModified().toString(tr("yyyy/yy/yy/"));
            ui->tableWidget->setItem(rowcount, 4,new QTableWidgetItem(time));
            ui->tableWidget->setItem(rowcount, 5, new QTableWidgetItem(QString::number(result)+"%"));
            }
        }
    }

    if(wayname=="Perceptual Hash")
    {
        QString str1=pHash(img1);
        QString path=ui->textEdit->toPlainText();

        QDir dir(path);
        if(!dir.exists())return;
        QStringList filters;
        filters<<"*.jpg"<<"*.png"<<"*.bmp";
        dir.setNameFilters(filters);
        int dir_count=dir.count();
        if(dir_count<=0)return;
        QChar separator = QChar('/');
              if(!path.contains(separator))
              {
                separator = QChar('\\');
              }
              QChar last_char = path.at(path.length()-1);
              if(last_char == separator)
              {
                separator = QChar();
              }

        for(int i=0;i<dir_count;i++)
        {

            QString filename2=dir[i];
            QString file_path = path + separator + filename2;
            QFile file2(file_path);

            Mat img2;
            if(file2.open(QFile::ReadOnly))
            {
                QByteArray ba2 = file2.readAll();
                img2 = imdecode(vector<char>(ba2.begin(), ba2.end()), 1);
            }
            int result=pcompare(str1,img2);

            int l=0;
            int biggest_similarity=ui->spinBox->value();
            if(biggest_similarity){
                l=biggest_similarity;
            }
            else l=84;
            if(result>l){
            int rowcount = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rowcount);
            for(int i=0;i<6;i++)
            ui->tableWidget->horizontalHeader()->setSectionResizeMode(i,QHeaderView::ResizeToContents);
            ui->tableWidget->setItem(rowcount, 0, new QTableWidgetItem(filename2));
            ui->tableWidget->setItem(rowcount, 1, new QTableWidgetItem(path));
            QString big=QString::number(img2.cols);
            big+="*";
            big+=QString::number(img2.rows);
            ui->tableWidget->setItem(rowcount, 2, new QTableWidgetItem(big));
            QString size=QString::number(file2.size()/1024)+"KB";
            ui->tableWidget->setItem(rowcount, 3, new QTableWidgetItem(size));
            QFileInfo info(file2);
            QString time=info.lastModified().toString(tr("yyyy/yy/yy"));
            ui->tableWidget->setItem(rowcount, 4,new QTableWidgetItem(time));
            ui->tableWidget->setItem(rowcount, 5, new QTableWidgetItem(QString::number(result)+"%"));
}
        }
   }

    if(wayname=="Different Hash")
    {
        QString str1=dHash(img1);
        QString path=ui->textEdit->toPlainText();

        QDir dir(path);
        if(!dir.exists())return;
        QStringList filters;
        filters<<"*.jpg"<<"*.png"<<"*.bmp";
        dir.setNameFilters(filters);
        int dir_count=dir.count();
        if(dir_count<=0)return;

        QChar separator = QChar('/');
              if(!path.contains(separator))
              {
                separator = QChar('\\');
              }
              QChar last_char = path.at(path.length()-1);
              if(last_char == separator)
              {
                separator = QChar();
              }

        for(int i=0;i<dir_count;i++)
        {

            QString filename2=dir[i];
            QString file_path = path + separator + filename2;
            QFile file2(file_path);

            Mat img2;
            if(file2.open(QFile::ReadOnly))
            {
                QByteArray ba2 = file2.readAll();
                img2 = imdecode(vector<char>(ba2.begin(), ba2.end()), 1);
            }
            int result=dcompare(str1,img2);
            int biggest_similarity=ui->spinBox->value();
            int lm=0;
            if(biggest_similarity){
                lm=biggest_similarity;
            }
            else lm=84;
            if(result>lm){
            int rowcount = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rowcount);

            for(int i=0;i<6;i++)
            ui->tableWidget->horizontalHeader()->setSectionResizeMode(i,QHeaderView::ResizeToContents);
            ui->tableWidget->setItem(rowcount, 0, new QTableWidgetItem(filename2));
            ui->tableWidget->setItem(rowcount, 1, new QTableWidgetItem(path));
            QString big=QString::number(img2.cols);
            big+="*";
            big+=QString::number(img2.rows);
            ui->tableWidget->setItem(rowcount, 2, new QTableWidgetItem(big));
            QString size=QString::number(file2.size()/1024)+"KB";
            ui->tableWidget->setItem(rowcount, 3, new QTableWidgetItem(size));
            QFileInfo info(file2);
            QString time=info.lastModified().toString(tr("yyyy/MM/dd"));
            ui->tableWidget->setItem(rowcount, 4,new QTableWidgetItem(time));
            ui->tableWidget->setItem(rowcount, 5, new QTableWidgetItem(QString::number(result)+"%"));
 }
}
}

}
void MainWindow::on_pushButton_5_clicked()
{
    QString cur=QDir::currentPath();
    QString filename =QFileDialog::getOpenFileName(this,"",cur,"(*.*)");
    ui->lineEdit->setText(filename);
    ui->label_9->setScaledContents(true);
    ui->label_9->setPixmap(filename);
}

void MainWindow::on_pushButton_clicked()
{
    QString cur=QFileDialog::getExistingDirectory(this,"选择目录","./",QFileDialog::ShowDirsOnly);
    ui->textEdit->setText(cur);
}
void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QTableWidgetItem *item=new QTableWidgetItem;
    item=ui->tableWidget->item(row,0);
    QTableWidgetItem *item2=new QTableWidgetItem;
    item2=ui->tableWidget->item(row,1);
    QChar sep = QChar('/');
    QString curfile=item2->text()+"/"+item->text();
          if(!curfile.contains(sep))
          {
            sep = QChar('\\');
          }
          QChar last_char = curfile.at(curfile.length()-1);
          if(last_char == sep)
          {
            sep = QChar();
          }
    ui->label_10->setScaledContents(true);
    ui->label_10->setPixmap(curfile);
}
