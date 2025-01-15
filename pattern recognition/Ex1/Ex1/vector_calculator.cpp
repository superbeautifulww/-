#include "vector_calculator.h"

vector_calculator::vector_calculator()
{


}

QVector<double> vector_calculator::add(QVector<double> a,QVector<double> b)
{
    QVector<double> res;
    for(int i=0;i<a.size();i++) res.push_back(a[i]+b[i]);
    return res;
}

QVector<double> vector_calculator::minus(QVector<double> a,QVector<double> b)
{
    QVector<double> res;
    for(int i=0;i<a.size();i++) res.push_back(a[i]-b[i]);
    return res;
}

QVector<double> vector_calculator::div(QVector<double> a,QVector<double> b)
{
    QVector<double> res;
    for(int i=0;i<a.size();i++) res.push_back(a[i]/b[i]);
    return res;
}

QVector<double> vector_calculator::mul(QVector<double> a,QVector<double> b)
{
    QVector<double> res;
    for(int i=0;i<a.size();i++) res.push_back(a[i]*b[i]);
    return res;
}



