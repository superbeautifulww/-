#include<stdlib.h>
#include<cmath>
#include<iostream>
using namespace std;

const double bGM84 = 3.986005e14;
const double bOMEGAE84 = 7.2921151467e-5;

long double mk, ek, vk, tak, ik, omegak, phik, uk, rk;
long double corr_u, corr_r, corr_i;
long double xpk, ypk;
long double xk, yk, zk;
long iter;

int main()
{
	
    long double rinex[] = { 01,2018,05,06,8,00,00,-4.573306068778E-05,-2.842170943040E-12,0.000000000000E+00,
         7.100000000000E+01,-6.165625000000E+01, 4.259820496344E-09,-9.699866621236E-03,
        -3.188848495483E-06, 7.693550782278E-03, 7.748603820801E-06, 5.153673528671E+03,
         2.880000000000E+04, 3.911554813385E-08,-2.371054149340E+00, 8.754432201385E-08,
         9.710246200559E-01, 2.385000000000E+02, 6.197493408991E-01,-8.003905094256E-09,
         1.496490847908E-10, 1.000000000000E+00, 2.000000000000E+03, 0.000000000000E+00,
         2.000000000000E+00, 0.000000000000E+00, 5.587935447693E-09, 7.100000000000E+01,
         2.154000000000E+04 };
	
    long double crs = -99.751234;
    long double delta_n = 4.425184e-9;
    long double m0 = 2.143310;//平近角点
    long double cuc = -5.226582e6;
    long double e = 0.016043;
    long double cus = 2.348796e-6;
    long double roota = 5153.708647;//a的平方根
    long double toe = 446400;//toe=28800
    long double cic = 2.272427e-7;
    long double bigomega0 = -8.047478e-9;
    long double cis = 1.490116e-8;
    long double i0 = 0.967632;//轨道倾角
    long double crc = 336.531250;
    long double smallomega = -1.206129;//近地点角距 25
    long double bigomegadot = -8.047478e-9;
    long double idot = -2.967981e-10;
    //long double wne = rinex[28];
    long double earthrate = bOMEGAE84;//地球引力常数，mu
	
    //int WN, 
	int TOW;
	std::cin >> TOW;
	
	long double dt = TOW - toe;
		//(WN - wne) * 7 * 24 * 3600;
    long double A=roota*roota;//轨道长半轴
    //long double n0, n;
    
	
    //计算卫星运行的平均角速度
    long double n0 = sqrt(bGM84 / (A*A*A)); 
    long double n = n0 + delta_n;
	cout << n << endl;
    //计算t时刻的卫星平近角点
    mk = m0 + n * dt;
	cout << mk << endl;
    //迭代计算偏近点角
    ek = mk;
    for (iter = 0; iter < 7; iter++)
        ek = mk + e * sin(ek);
	cout << ek << endl;
    //计算真近点角
    tak = atan2(sqrt(1.0 - e * e)*sin(ek), cos(ek) - e);

    //计算升交距角phik相当于ut的导数，tak相当于ft
    phik = tak + smallomega;
    //计算摄动改正项
    corr_u = cus * sin(2.0*phik) + cuc * cos(2.0*phik);
    corr_r = crs * sin(2.0*phik) + crc * cos(2.0*phik);
    corr_i = cis * sin(2.0*phik) + cic * cos(2.0*phik);
    //计算摄动改正
    uk = phik + corr_u;
    rk = A * (1.0 - e * cos(ek)) + corr_r;
    ik = i0 + idot * dt + corr_i;

    //计算在轨道平面坐标系中的位置
    xpk = rk * cos(uk);
    ypk = rk * sin(uk);

    omegak = bigomega0 + (bigomegadot - earthrate)*dt - earthrate * toe;

    xk = xpk * cos(omegak) - ypk * sin(omegak)*cos(ik);
    yk = xpk * sin(omegak) + ypk * cos(omegak)*cos(ik);
    zk = ypk * sin(ik);
   
	std::cout << xk << std::endl;
	std::cout << yk << std::endl;
	std::cout << zk << std::endl;
	
    system("pause");
	
    return 0;
}



/*
一般情况下，所求时刻与参考星历时刻接近，因而输入的WN应与星历的wne相近，为2000
TOW与本星历的toe相近，本星历中，toe=28800
*/
