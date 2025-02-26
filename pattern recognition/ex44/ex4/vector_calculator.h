﻿#ifndef VECTOR_CALCULATOR_H
#define VECTOR_CALCULATOR_H
#include<QVector>

class vector_calculator
{
public:
    vector_calculator();
    //一维数组运算
    QVector<double> add(QVector<double> a,QVector<double> b);
    QVector<double> minus(QVector<double> a,QVector<double> b);
    QVector<double> div(QVector<double> a,QVector<double> b);
    QVector<double> mul(QVector<double> a,QVector<double> b);

    //二位数组运算
    QVector<QVector<int>> add2D(QVector<QVector<int>> a, QVector<QVector<int>> b);



};

#endif // VECTOR_CALCULATOR_H
