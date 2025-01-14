#pragma once
#include<graphics.h>
#include<conio.h>
#include<Windows.h>
#define first x
#define second y
#include<cmath>
#include<algorithm>
#include<stack>
#include<iostream>
#include<vector>

using namespace std;
#define x first
#define y second
typedef pair<int, int> PII;
struct edge {
	int y1;
	int y2;
	double dx;
	double x;
	edge(PII p1, PII p2)
	{
		if (p1.y >p2.y) swap(p1, p2);
		y1 = p1.y;
		y2 = p2.y;
		if(p2.y!=p1.y) dx = (p2.x - p1.x)*1.0 / ((p2.y - p1.y)*1.0);
		else dx = 1e5;
		x = p1.x;
	}
};

inline bool cmp(edge a, edge b)
{
	return a.x < b.x;
}

class edgetable {
public:
	vector<edge> ET;
	int xmin = 1e5;
	int xmax = -1e5;
	int ymin=1e5;
	int ymax=-1e5;

	bool st[1000];//标记当前y扫描线的初始边表是否有结点
	
	edgetable(){}
	edgetable(vector<PII> dot);
	void add1(vector<edge> &AET,int y);
	void update(vector<edge> &AET,int y);

	void add2(vector<edge> &AET, int y,int dy);
	//void del(vector<edge> &AET, int y);
};

