#ifndef BAYES_H
#define BAYES_H
#include<QVector>
#include<QImage>


class bayes
{
public:
    bayes();
    void train(QVector<QVector<int>> sample, QVector<QVector<double>> &prob);
    QImage predict(QVector<QVector<double>> prob_road,QVector<QVector<double>> prob_water,QVector<QVector<double>> prob_building,
               QVector<QVector<double>> prob_field,QImage img);

};

#endif // BAYES_H
