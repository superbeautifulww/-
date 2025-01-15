#include "fisher.h"

fisher::fisher()
{

}

QVector<double> fisher::cal_avg(QVector<QVector<int>> sample)
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

QVector<double> fisher::cal_var(QVector<QVector<int>> sample)
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

QImage fisher::fisherClassify(QImage img,QVector<QVector<int>> road_sample,QVector<QVector<int>> field_sample,
                              QVector<QVector<int>> water_sample,QVector<QVector<int>> building_sample)
{
    QImage resimg(img);

    QVector<double> m_road = cal_avg(road_sample);
    QVector<double> m_field=cal_avg(field_sample);
    QVector<double> m_water = cal_avg(water_sample);
    QVector<double> m_building=cal_avg(building_sample);
    QVector<double> SW_road = cal_var(road_sample);
    QVector<double> SW_field = cal_var(field_sample);
    QVector<double> SW_water = cal_var(water_sample);
    QVector<double> SW_building = cal_var(building_sample);

    // 第一次二分类：road和thers
    QVector<double> m_others = cal_avg(v.add2D(v.add2D(field_sample, water_sample), building_sample));
    QVector<double> SW_others = cal_var(v.add2D(v.add2D(field_sample, water_sample), building_sample));
    QVector<double> SW1 = v.add(SW_road, SW_others);
    QVector<double> w1 = v.div(v.minus(m_road, m_others), SW1);
    QVector<double> _b1 = v.mul(w1, v.add(m_road, m_others));
    for(int i=0;i<_b1.size();i++) _b1[i]*=0.5;

    // 第二次二分类：building和others
    QVector<double> m_others2 = cal_avg(v.add2D(water_sample, field_sample));
    QVector<double> SW_others2 = cal_var(v.add2D(water_sample, field_sample));
    QVector<double> SW2 = v.add(SW_building, SW_others2);
    QVector<double> w2 = v.div(v.minus(m_building, m_others2), SW2);
    QVector<double> _b2 = v.mul(w2, v.add(m_building, m_others2));
    for(int i=0;i<_b2.size();i++) _b2[i]*=0.5;

    // 第三次二分类：water和field
    QVector<double> SW3 = v.add(SW_water, SW_field);
    QVector<double> w3 = v.div(v.minus(m_water, m_field), SW3);
    QVector<double> _b3 = v.mul(w3, v.add(m_water, m_field));
    for(int i=0;i<_b3.size();i++) _b3[i]*=0.5;


    for (int y = 0; y < img.height(); y++) {
        for (int x = 0; x < img.width(); x++) {
            QRgb pixel = img.pixel(x, y);
            double r = qRed(pixel)*1.0;
            double g=qGreen(pixel)*1.0;
            double b=qBlue(pixel)*1.0;

            QVector<double> predict1={r*w1[0],g*w1[1],b*w1[2]};
            QVector<double> predict2={r*w2[0],g*w2[1],b*w2[2]};
            QVector<double> predict3={r*w3[0],g*w3[1],b*w3[2]};

            if(predict1[0]<=_b1[0]&&predict1[1]<=_b1[1]&&predict1[2]<=_b1[2]) {
                resimg.setPixel(x, y, qRgb(255, 255, 0)); // road
            } else if(predict2[0]<=_b2[0]&&predict2[1]<=_b2[1]&&predict2[2]<=_b2[2]) {
                resimg.setPixel(x, y, qRgb(255, 0, 0)); // building
            } else if(predict3[0]<=_b3[0]&&predict3[1]<=_b3[1]&&predict3[2]<=_b3[2]) {
                resimg.setPixel(x, y, qRgb(0, 0, 255)); // water
            } else {

                resimg.setPixel(x, y, qRgb(0, 128, 0)); // field
            }
        }
    }
    resimg.save("fisher.jpg", "JPG", 100);
    return resimg;
}
