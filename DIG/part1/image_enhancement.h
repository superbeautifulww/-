#ifndef IMAGE_ENHANCEMENT_H
#define IMAGE_ENHANCEMENT_H
#include<QImage>
#include<QLabel>

class image_enhancement
{
public:
    image_enhancement();

    QVector<int> cal_histogram(QImage image);
    void draw_histogram(QVector<int> histogram,QLabel *label);

    QImage histogram_normalization(QImage img,int l,int r);

};

#endif // IMAGE_ENHANCEMENT_H
