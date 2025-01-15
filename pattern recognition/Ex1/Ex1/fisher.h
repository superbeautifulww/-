#ifndef FISHER_H
#define FISHER_H
#include<QVector>
#include<QImage>
#include"vector_calculator.h"

class Fisher
{
public:
    Fisher();

    QVector<double> cal_avg(QVector<QVector<int>> sample);
    QVector<double> cal_var(QVector<QVector<int>> sample);

    QImage fisherClassify(QImage img,QVector<QVector<int>> back_sample,QVector<QVector<int>> target_sample,QString band);
    vector_calculator v;
};

#endif // FISHER_H
