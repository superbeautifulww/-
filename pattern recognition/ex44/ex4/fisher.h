#ifndef FISHER_H
#define FISHER_H
#include<QVector>
#include<QImage>
#include"vector_calculator.h"


class fisher
{
public:
    fisher();
    vector_calculator v;

    QVector<double> cal_avg(QVector<QVector<int>> sample);
    QVector<double> cal_var(QVector<QVector<int>> sample);
    QImage fisherClassify(QImage img,QVector<QVector<int>> road_sample,QVector<QVector<int>> field_sample,
                          QVector<QVector<int>> water_sample,QVector<QVector<int>> building_sample);
};

#endif // FISHER_H
