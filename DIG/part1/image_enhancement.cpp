#include "image_enhancement.h"
#include<QDebug>
#include<QPainter>


image_enhancement::image_enhancement()
{

}

QVector<int> image_enhancement::cal_histogram(QImage image)
{
    QVector<int> histogram(256, 0);

    int width = image.width();
    int height = image.height();

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            QRgb pixel = image.pixel(x, y);
            int temp;
            temp=qGray(pixel);
            histogram[temp]++;
        }
    }
    return histogram;
}

void image_enhancement::draw_histogram(QVector<int> histogram,QLabel *label)
{
    int maxCount = *std::max_element(histogram.begin(), histogram.end());

    QPixmap histogramPixmap(256, 256);
    histogramPixmap.fill(Qt::white);
    QPainter painter(&histogramPixmap);
    painter.setPen(Qt::black);

    for (int i = 0; i < 256; i++) {
        int barHeight = static_cast<int>(100.0 * histogram[i] / maxCount);
        painter.drawRect(i, 150 - barHeight, 1, barHeight);
        if(i%30==0) painter.drawText(i, 150 + 12, QString::number(i));
    }
    label->setPixmap(histogramPixmap);
}

QImage image_enhancement::histogram_normalization(QImage img,int a,int b)
{

    QImage resimg=img;
    int width = img.width();
    int height = img.height();

    int c = 255,d=0;  // 初始化一个较大的值作为初始最小值
    //qDebug("%d %d",minval,maxval);

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        {
            int grayval = qGray(img.pixel(x, y));

            if (grayval < c) c = grayval;
            if(grayval>d) d=grayval;
        }
    //qDebug("%d %d",c,d);
    for(int y=0;y<height;y++)
        for(int x=0;x<width;x++)
        {
            int grayval = qGray(img.pixel(x, y));
            //qDebug("%d",grayval);
            //resimg.setPixel(x,y,qRgb(255,255,255));
            int val=(b-a)*(grayval-c)/(d-c)+a;
            //qDebug("%d %d %d",x,y,val);
            resimg.setPixel(x,y,val);
        }

    return resimg;
}
