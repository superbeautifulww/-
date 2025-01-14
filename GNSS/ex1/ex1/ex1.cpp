#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const long double GM = 3.986005e14;
const long double we = 7.2921151467e-5;
long double toe,t;
long double sqrtA, e, M0, w0, i0, omega0, deltaN, iDot, omegaDot, Cuc, Cus, Crc, Crs, Cic, Cis;
const long double pi = 3.1415926535898;
int main()
{
	cout << "t" << endl;
	cin >> t;
	cout << "toe:" << endl;
	cin >> toe;
	cout << "sqrtA:" << endl;
	cin >> sqrtA;
	cout << "e:" << endl;
	cin >> e;
	cout << "M0:" << endl;
	cin >> M0;
	cout << "w0:" << endl;
	cin >> w0;
	cout << "i0:" << endl;
	cin >> i0;
	cout << "omega0:" << endl;
	cin >> omega0;
	cout << "deltaN:" << endl;
	cin >> deltaN;
	cout << "iDot:" << endl;
	cin >> iDot;
	cout << "omegaDot:" << endl;
	cin >> omegaDot;
	cout << "Cuc:" << endl;
	cin >> Cuc;
	cout << "Cus:" << endl;
	cin >> Cus;
	cout << "Crc:" << endl;
	cin >> Crc;
	cout << "Crs:" << endl;
	cin >> Crs;
	cout << "Cic:" << endl;
	cin >> Cic;
	cout << "Cis:" << endl;
	cin >> Cis;
	//计算卫星的平均角速度
	long double n0 = sqrt(GM) / (sqrtA*sqrtA*sqrtA);
	long double n = n0 + deltaN;
	cout << "n:" << n <<endl;
	//计算观测瞬间卫星的平近点角
	long double M = M0 + n * (t - toe);
	cout << "M:" << M << endl;
	//计算偏近点角
	long double E = M;
	long double temp;
	while (1)
	{
		temp = M + e * sin(E);
		if (abs(temp - E) < 1e-13) break;
		E = temp;
	}
	E = temp;
	cout << "E:" << E<<endl;
	//计算真近点角
	long double f = atan((sqrt(1 - e * e)*sin(E)) / (cos(E) - e));
	//计算升交角距
	long double upie = w0 + f;
	//计算摄动改正项
	long double deltau = Cuc * cos(2 * upie) + Cus * sin(2 * upie);
	long double deltar = Crc * cos(2 * upie) + Crs * sin(2 * upie);
	long double deltai = Cic * cos(2 * upie) + Cis * sin(2 * upie);
	//计算upie、rpie、i0摄动改正值
	long double u = upie + deltau;
	long double r = sqrtA * sqrtA*(1 - e * cos(E)) + deltar;
	long double i = i0 + deltai + iDot * (t - toe);
	//计算卫星在轨道面坐标系中的位置
	long double x0 = r * cos(u);
	long double y0 = r * sin(u);
	long double z0 = 0;
	//计算观测瞬间升交点的经度
	//GPS
	long double L = omega0 + omegaDot * (t - toe) - we * t;
	//北斗GEO
	//long double L = omega0 + omegaDot * (t - toe) - we * toe;
	//计算卫星的空间直角坐标
	long double x = x0 * cos(L) - y0 * sin(L)*cos(i) + z0 * sin(L)*sin(i);
	long double y = x0 * sin(L) + y0 * cos(L)*cos(i) - z0 * cos(L)*sin(i);
	long double z = y0 * sin(i) + z0 * cos(i);
	//北斗CEO卫星的坐标进行坐标系转换
	long double phiz = we * (t - toe);
	long double phix = (-5.0) * pi / 180.0;
	long double xk = x * cos(phiz) + y * sin(phiz)*cos(phix) + z * sin(phiz)*sin(phix);
	long double yk = -x * sin(phiz) + y * cos(phiz)*cos(phix) + z * cos(phiz)*sin(phix);
	long double zk = -y * sin(phix) + z * cos(phix);
	/*
	cout << "GPSx:" <<fixed<<x << endl;
	cout << "GPSy:" << fixed<<y << endl;
	cout << "GPSz:" << fixed<<z <<endl;
	*/
	cout << "BDSx:" << fixed << x << endl;
	cout << "BDSy:" << fixed << y << endl;
	cout << "BDSz:" << fixed << z << endl;
}

