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
#include"edgetable.h"

using namespace std;
#define x first
#define y second
typedef pair<int, int> PII;


class Draw
{

public:
	vector<PII> alldots;

	void ChangeXY(int &x, int &y, int winx_start, int winy_end);
	
	void translation(int &x, int &y, int tx, int ty);//平移
	
	void rotation(int x0, int y0, int &x, int &y, float theta);//旋转
	
	PII scaling(int x0, int y0, int x, int y, float s);//缩放
	vector<float> Matrix_mul(vector<float> &matrix1, vector<vector<float>> &matrix2);
	//数值微分法画直线
	void Line_DDA(float x1, float y1, float x2, float y2, int color_r, int color_g, int color_b);
	//中点画线法画直线
	void Midpoint_Line1(int x1, int y1, int x2, int y2, int color_r, int color_g, int color_b);
	//画线展示
	void Show_Line(int x_start, int y_start, int x_end, int y_end);
	//扫描线填充法
	void scanline_fill(vector<PII> points, int color_r, int color_g, int color_b);
	//扫描线种子点填充法
	void seed_fill(vector<PII> dot, PII seed, int color_r, int color_g, int color_b);
	
	//画多边形
	void draw_polygon(vector<PII> dot);
	//画图标
	void draw();
	//绘制统计图
	void statistical_chart();
	void draw_column(int startx, int starty, int width, int high);
	//矩形填充
	void symbol_fill(vector<PII> dot,int dy,int dx);//dy、dx设4的倍数


	
};

