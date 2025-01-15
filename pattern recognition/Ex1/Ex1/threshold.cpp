#include "threshold.h"

threshold::threshold()
{

}
QVector<int> threshold::cal_histogram(QString band,QImage image)
{
    QVector<int> histogram(256, 0);

    int width = image.width();
    int height = image.height();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            QRgb pixel = image.pixel(x, y);
            int temp;
            if(band=='R') temp=qRed(pixel);
            else if(band=='G') temp=qGreen(pixel);
            else temp=qBlue(pixel);
            histogram[temp]++;
        }
    }
    return histogram;
}
QImage threshold::thresholding(int rl,int rh,int gl,int gh,int bl,int bh,QImage img)
{
    QImage resimg(img);

    for (int y = 0; y < img.height(); y++) {
        for (int x = 0; x < img.width(); x++) {
            QRgb pixel = img.pixel(x, y);
            int r = qRed(pixel);
            int g=qGreen(pixel);
            int b=qBlue(pixel);

            if (r>=rl&&r<=rh&&g>=gl&&g<=gh&&b>=bl&&b<=bh) {
                resimg.setPixel(x, y, qRgb(r, g, b));
            } else {
                resimg.setPixel(x, y, qRgb(255, 255, 255));
            }
        }
    }
    return resimg;
}
