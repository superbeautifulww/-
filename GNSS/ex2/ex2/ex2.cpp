#include <iostream>
#include<cmath>
using namespace std;

const long double pi = 3.141592653589;
const long double c = 299792458;
const long double L1 = 1575.42e+6;
long double T, rs,t=1;
long double xr, yr, zr;
long double x1, y_1, z1, x2, y2, z2;

int main()
{
	/*
	cout << "周期T:" << endl;
	cin >> T;
	cout << "轨道半径rs:" << endl;
	cin >> rs;
	
	cout << "时间t：" << endl;
	cin >> t;
	
	long double w = 2 * pi / T;
	long double vs = rs * w;
	*/
	cout << "接收机xr：" << endl;
	cin >> xr;
	cout << "接收机yr：" << endl;
	cin >> yr;
	cout << "接收机zr：" << endl;
	cin >> zr;
	
	cout << "S1的x：" << endl;
	cin >> x1;
	
	cout << "S1的y：" << endl;
	cin >> y_1;
	cout << "S1的z：" << endl;
	cin >> z1;
	cout << "S2的x：" << endl;
	cin >> x2;
	cout << "S2的y：" << endl;
	cin >> y2;
	cout << "S2的z：" << endl;
	cin >> z2;

	long double d1 = sqrt((x1 - xr)*(x1 - xr) + (y_1 - yr)*(y_1 - yr) + (z1 - zr)*(z1 - zr));
	long double d2 = sqrt((x2 - xr)*(x2 - xr) + (y2 - yr)*(y2 - yr) + (z2 - zr)*(z2 - zr));
	long double vd = abs(d1 - d2) / t;
	long double fd = vd * L1 / c;
	cout << d1 << endl;
	cout << d2 << endl;
	cout << fd << endl;
	
	return 0;

}


