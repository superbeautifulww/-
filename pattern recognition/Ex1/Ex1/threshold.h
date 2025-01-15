#ifndef WORK_H
#define WORK_H
#include<QString>
#include<QVector>
#include<QImage>

class threshold
{
public:
    threshold();
    QVector<int> cal_histogram(QString band,QImage image);
    QImage thresholding(int rl,int rh,int gl,int gh,int bl,int bh,QImage img);

};

#endif // WORK_H
