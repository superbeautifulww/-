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


QVector<QVector<int>> vector_calculator::add2D(QVector<QVector<int>> a, QVector<QVector<int>> b)
{
    QVector<QVector<int>> res;
    for(int i=0; i<a.size(); i++)
    {
        QVector<int> temp;
        for(int j=0; j<a[i].size(); j++)
        {
            if(i < b.size() && j < b[i].size()) // 检查索引是否在b的有效范围内
            {
                temp.push_back(a[i][j] + b[i][j]);
            }
            else
            {
                temp.push_back(a[i][j]); // 如果b的大小小于a，那么只添加a的元素
            }
        }
        res.push_back(temp);
    }
    return res;
}
