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
#include<unordered_map>
#include"Draw.h"
#include"draw_3D.h"
#include"interection.h"
using namespace std;
#define x first
#define y second
typedef pair<int,int> PII;

int main(int argc, char** argv)
{
	Draw D;
	interection I;
	draw_3D T;

	/*
	//画线算法展示
	D.Show_Line(20, 20, 1100, 700);
	*/

	/*
	//画线、填充、二维基本变换功能交互测试函数
	I.draw_menu();
	*/

	/*
	//图标绘制、二维基本变换展示函数
	I.symbol_menu();
	*/

	/*
	//三维基本变换展示函数
	//需要在draw_3D的render()函数中对二维矩阵use进行设置，实现各个变换
	T.start1(argc,argv);
	*/

	/*
	//正方体旋转展示函数
	T.start2(argc, argv);
	*/

	/*
	//统计图展示函数
	D.statistical_chart();
	*/

	
	
}

