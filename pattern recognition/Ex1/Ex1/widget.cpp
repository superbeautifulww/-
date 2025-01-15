
#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QPainter>
#include<QVector>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("background-color: white;");
    ui->singleshowlabel->setStyleSheet("background-color: white;");
    ui->histogramlabel->setStyleSheet("background-color: white;");
    ui->thresholdinglabel->setStyleSheet("background-color: white;");
    ui->bayes_choose_label->setStyleSheet("background-color: white;");
    ui->bayes_show_label->setStyleSheet("background-color: white;");
    ui->fisher_choose_label->setStyleSheet("background-color: white;");
    ui->fisher_show_label->setStyleSheet("background-color: white;");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_choosepicture_clicked()
{
    filePath = QFileDialog::getOpenFileName(this, tr("选择文件"), "", tr("所有文件 (*.*)"));
    if (!filePath.isEmpty()) {
        QPixmap pixmap(filePath);
        ui->label->setPixmap(pixmap.scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->label->setAlignment(Qt::AlignCenter);
        ui->bayes_choose_label->setPixmap(pixmap.scaled(ui->bayes_choose_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->bayes_choose_label->setAlignment(Qt::AlignCenter);
        ui->fisher_choose_label->setPixmap(pixmap.scaled(ui->fisher_choose_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->fisher_choose_label->setAlignment(Qt::AlignCenter);
    }
}


void Widget::on_singleshow_clicked()
{
    QPixmap pixmap;
    QString show_color=ui->show_color_comboBox->currentText();
    if (!filePath.isEmpty()) {

        QImage image(filePath);
        for (int x = 0; x < image.width(); x++) {
            for (int y = 0; y < image.height(); y++) {
                QRgb pixel = image.pixel(x, y);
                int val ;
                if(show_color=='R') val=qRed(pixel);
                else if(show_color=='G') val=qGreen(pixel);
                else val=qBlue(pixel);
                image.setPixel(x, y, qRgb(val,val,val));
            }
        }
        pixmap = QPixmap::fromImage(image);
        ui->singleshowlabel->setPixmap(pixmap.scaled(ui->singleshowlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->singleshowlabel->setAlignment(Qt::AlignCenter);}
}


void Widget::on_show_histogram_clicked()
{
    if (!filePath.isEmpty()){

        QString band = ui->comboBox->currentText();
        QImage image(filePath);

        QVector<int> histogram=w.cal_histogram(band,image);

        int maxCount = *std::max_element(histogram.begin(), histogram.end());

        QPixmap histogramPixmap(256, 180);
        histogramPixmap.fill(Qt::white);
        QPainter painter(&histogramPixmap);
        painter.setPen(Qt::black);

        for (int i = 0; i < 256; i++) {
            int barHeight = static_cast<int>(100.0 * histogram[i] / maxCount);
            painter.drawRect(i, 150 - barHeight, 1, barHeight);
            //QString valueText = QString::number(histogram[i]);
            if(i%30==0) painter.drawText(i, 150 + 12, QString::number(i));
        }
        ui->histogramlabel->setPixmap(histogramPixmap);
    }
}


void Widget::on_thresholding_clicked()
{
    if (!filePath.isEmpty()){
        int rl=0;
        int rh=255;
        int bl=0;
        int bh=255;
        int gl=0;
        int gh=255;
        if(ui->RL->text().toInt()) rl=ui->RL->text().toInt();
        if(ui->RH->text().toInt()) rh=ui->RH->text().toInt();
        if(ui->BL->text().toInt()) bl=ui->BL->text().toInt();
        if(ui->BH->text().toInt()) bh=ui->BH->text().toInt();
        if(ui->GL->text().toInt()) gl=ui->GL->text().toInt();
        if(ui->GH->text().toInt()) gh=ui->GH->text().toInt();
        QImage image(filePath);

        QImage resimg=w.thresholding(rl,rh,gl,gh,bl,bh,image);
        QPixmap pixmap = QPixmap::fromImage(resimg);
        ui->thresholdinglabel->setPixmap(pixmap.scaled(ui->thresholdinglabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->thresholdinglabel->setAlignment(Qt::AlignCenter);
    }
}

void Widget::mousePressEvent(QMouseEvent* event) {

    if (bayes_tag&&!ui->bayes_choose_label->pixmap().isNull()&&event->button() == Qt::LeftButton) {
        QPoint pos = event->pos();
        pos = ui->bayes_choose_label->mapFrom(this, pos);
        QPixmap pixmap = ui->bayes_choose_label->pixmap().copy();

        QColor color = pixmap.toImage().pixelColor(pos);

        int red = color.red();
        int green = color.green();
        int blue = color.blue();

        QVector<int> rgb = {red, green, blue};
        if(bayes_tag==1) bayes_back_sample.push_back(rgb);
        else if(bayes_tag==2) bayes_target_sample.push_back(rgb);
    }
    else if(!ui->fisher_choose_label->pixmap().isNull()&&event->button() == Qt::LeftButton)
    {
        QPoint pos = event->pos();
        pos = ui->fisher_choose_label->mapFrom(this, pos);
        QPixmap pixmap = ui->fisher_choose_label->pixmap().copy();

        QColor color = pixmap.toImage().pixelColor(pos);

        int red = color.red();
        int green = color.green();
        int blue = color.blue();

        QVector<int> rgb = {red, green, blue};
        if(fisher_tag==1)fisher_back_sample.push_back(rgb);
        else if(fisher_tag==2) fisher_target_sample.push_back(rgb);
    }
}

void Widget::on_Bayes_button_clicked()
{
    QVector<QVector<double>> prob1,prob0;
    b.train(bayes_back_sample,prob0);
    b.train(bayes_target_sample,prob1);
    QString band=ui->Bayes_comboBox->currentText();
    QImage img(filePath);
    QImage resimg=b.predict(prob1,prob0,img,band);
    QPixmap pixmap = QPixmap::fromImage(resimg);
    ui->bayes_show_label->setPixmap(pixmap.scaled(ui->bayes_show_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->bayes_show_label->setAlignment(Qt::AlignCenter);

}




void Widget::on_fisher_button_clicked()
{
    QImage img(filePath);
    QString band=ui->Fisher_comboBox->currentText();
    QImage resimg=f.fisherClassify(img,fisher_back_sample,fisher_target_sample,band);
    QPixmap pixmap = QPixmap::fromImage(resimg);
    ui->fisher_show_label->setPixmap(pixmap.scaled(ui->fisher_show_label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->fisher_show_label->setAlignment(Qt::AlignCenter);


}


void Widget::on_bayes_start_clicked()
{
    bayes_target_sample.clear();
    bayes_tag=2;
}


void Widget::on_fisher_start_clicked()
{
    fisher_target_sample.clear();
    fisher_tag=2;
}


void Widget::on_bayes_back_clicked()
{
    bayes_back_sample.clear();
    bayes_tag=1;
}


void Widget::on_fisher_back_clicked()
{
    fisher_back_sample.clear();
    fisher_tag=1;
}

