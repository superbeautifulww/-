#include "fisher.h"

Fisher::Fisher()
{



}

QVector<double> Fisher::cal_avg(QVector<QVector<int>> sample)
{
    double tr=0.0,tg=0.0,tb=0.0 ;//totalrval,totalgval,totalbval
    for(int i=0;i<sample.size();i++)
    {
        int r=sample[i][0];
        int g=sample[i][1];
        int b=sample[i][2];
        tr+=r;
        tg+=g;
        tb+=b;
    }
    if(!sample.size()) return {0,0,0};
    return {tr/sample.size(),tg/sample.size(),tb/sample.size()};
}

QVector<double> Fisher::cal_var(QVector<QVector<int>> sample)
{
    double tr=0.0,tg=0.0,tb=0.0;
    QVector<double> avg=cal_avg(sample);
    for(int i=0;i<sample.size();i++)
    {
        int r=sample[i][0];
        int g=sample[i][1];
        int b=sample[i][2];
        tr += (r - avg[0]) * (r - avg[0]);
        tg += (g - avg[1]) * (g - avg[1]);
        tb += (b - avg[2]) * (b - avg[2]);
    }
    if(!sample.size()) return {0,0,0};
    return {tr,tg,tb};
}

QImage Fisher::fisherClassify(QImage img,QVector<QVector<int>> back_sample,QVector<QVector<int>> target_sample,QString band)
{
    QImage resimg(img);
    QVector<double> m1 = cal_avg(target_sample);
    QVector<double> m2=cal_avg(back_sample);
    QVector<double> SW1 = cal_var(target_sample);
    QVector<double> SW2 = cal_var(back_sample);
    QVector<double> SW = v.add(SW1,SW2);
    QVector<double> w=v.div(v.minus(m1,m2),SW);
    m1=v.mul(w,m1);
    m2=v.mul(w,m2);
    QVector<double> _b=v.add(m1,m2);
    for(int i=0;i<_b.size();i++) _b[i]*=0.5;
    for (int y = 0; y < img.height(); y++) {
        for (int x = 0; x < img.width(); x++) {
            QRgb pixel = img.pixel(x, y);
            double r = qRed(pixel)*1.0;
            double g=qGreen(pixel)*1.0;
            double b=qBlue(pixel)*1.0;

            if(band=="ALL")
            {
                QVector<double> predict={r*w[0],g*w[1],b*w[2]};
                if(predict[0]<=_b[0]&&predict[1]<=_b[1]&&predict[2]<=_b[2]) resimg.setPixel(x, y, qRgb(255, 255, 255));
            }
            else if (band == "R")
            {
                double predict = r * w[0];
                if (predict <= _b[0])  resimg.setPixel(x, y, qRgb(255, 255, 255));
            }
            else if (band == "G")
            {
                double predict = g * w[1];
                if (predict <= _b[1])  resimg.setPixel(x, y, qRgb(255, 255, 255));
            }
            else if (band == "B")
            {
                double predict = b * w[2];
                if (predict <= _b[2])  resimg.setPixel(x, y, qRgb(255, 255, 255));
            }
        }
    }
    return resimg;
}
