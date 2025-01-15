#include "bayes.h"



Bayes::Bayes()
{


}
/*
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

QImage Bayes::predict(QVector<QVector<double>> prob_road,QVector<QVector<double>> prob_water,QVector<QVector<double>> prob_building,
                      QVector<QVector<double>> prob_field,QImage img)
{
    QImage resimg(img);
    for (int y = 0; y < img.height(); y++) {
        for (int x = 0; x < img.width(); x++) {
            QRgb pixel = img.pixel(x, y);
            double p_road=1.0,p_water=1.0,p_building=1.0,p_field=1.0;
            int r = qRed(pixel);
            int g=qGreen(pixel);
            int b=qBlue(pixel);

            if(prob_road[0][r]!=0.0)  p_road*=prob_road[0][r];
            if(prob_road[1][g]!=0.0)  p_road*=prob_road[1][g];
            if(prob_road[2][b]!=0.0)  p_road*=prob_road[2][b];

            if(prob_water[0][r]!=0.0)  p_water*=prob_water[0][r];
            if(prob_water[1][g]!=0.0)  p_water*=prob_water[1][g];
            if(prob_water[2][b]!=0.0)  p_water*=prob_water[2][b];

            if(prob_building[0][r]!=0.0)  p_building*=prob_building[0][r];
            if(prob_building[1][g]!=0.0)  p_building*=prob_building[1][g];
            if(prob_building[2][b]!=0.0)  p_building*=prob_building[2][b];

            if(prob_field[0][r]!=0.0)  p_field*=prob_field[0][r];
            if(prob_field[1][g]!=0.0)  p_field*=prob_field[1][g];
            if(prob_field[2][b]!=0.0)  p_field*=prob_field[2][b];

            if(p_road==1) p_road=0;
            if(p_water==1) p_water=0;
            if(p_building==1) p_building=0;
            if(p_field==1) p_field=0;

            double maxp=std::max(std::max(p_road,p_water),std::max(p_building,p_field));
            if (maxp==p_road)
            {
                resimg.setPixel(x, y, qRgb(255, 255, 0));
            }
            else if(maxp==p_water)
            {
                resimg.setPixel(x, y, qRgb(0,0, 255));
            }
            else if(maxp==p_building)
            {
                resimg.setPixel(x, y, qRgb(255, 0, 255));
            }
            else if(maxp==p_field)
            {
                resimg.setPixel(x, y, qRgb(0, 255, 255));
            }
            else{
                resimg.setPixel(x, y, qRgb(0, 0, 0));
            }
        }
    }
    return resimg;
}

*/
