#ifndef BAYESCLASSIFICATION_H
#define BAYESCLASSIFICATION_H
#include<QVector>
#include<QImage>


class Bayes
{
public:
    Bayes();
    void train(QVector<QVector<int>> sample, QVector<QVector<double>> &prob) ;
    QImage predict(QVector<QVector<double>> prob1,QVector<QVector<double>> prob0,QImage img,QString band);







};

#endif // BAYESCLASSIFICATION_H
