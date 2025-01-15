#include "Bayes.h"

Bayes::Bayes()
{


}


void Bayes::train(QVector<QVector<int>> sample, QVector<QVector<double>> &prob)
{
    prob.resize(3);
    for(int i=0;i<3;i++) prob[i].resize(256);
    for(int i=0;i<sample.size();i++)
    {
        for(int j=0;j<3;j++)
        {
            int curpixel=sample[i][j];
            prob[j][curpixel]++; //j波段值为i的像素个数
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<256;j++)
        {
            prob[i][j]/=(sample.size()*1.0);

        }
    }
}


QImage Bayes::predict(QVector<QVector<double>> prob1,QVector<QVector<double>> prob0,QImage img,QString band)
{
    QImage resimg(img);

    for (int y = 0; y < img.height(); y++) {
        for (int x = 0; x < img.width(); x++) {
            QRgb pixel = img.pixel(x, y);
            double p0=1.0,p1=1.0;
            int r = qRed(pixel);
            int g=qGreen(pixel);
            int b=qBlue(pixel);
            if(band=="ALL"){
                if(prob1[0][r]!=0.0) p1*=prob1[0][r];
                if(prob1[1][g]!=0.0) p1*=prob1[1][g];
                if(prob1[2][b]!=0.0) p1*=prob1[2][b];

                if(prob0[0][r]!=0.0) p0*=prob0[0][r];
                if(prob0[1][g]!=0.0) p0*=prob0[1][g];
                if(prob0[2][b]!=0.0) p0*=prob0[2][b];
            }
            else if (band == 'R')
            {
                if (prob1[0][r] != 0.0) p1 *= prob1[0][r];
                if (prob0[0][r] != 0.0) p0 *= prob0[0][r];

            }
            else if (band == 'G')
            {
                if (prob1[1][g] != 0.0) p1 *= prob1[1][g];
                if (prob0[1][g] != 0.0) p0 *= prob0[1][g];
            }
            else if (band == 'B')
            {
                if (prob1[2][b] != 0.0) p1 *= prob1[2][b];
                if (prob0[2][b] != 0.0) p0 *= prob0[2][b];
            }
            if(p1==1) p1=0;
            if(p0==1) p0=0;
            if (p1<p0)
            {
                resimg.setPixel(x, y, qRgb(255, 255, 255));
            }
        }
    }
    return resimg;
}
