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
	
	void translation(int &x, int &y, int tx, int ty);//ƽ��
	
	void rotation(int x0, int y0, int &x, int &y, float theta);//��ת
	
	PII scaling(int x0, int y0, int x, int y, float s);//����
	vector<float> Matrix_mul(vector<float> &matrix1, vector<vector<float>> &matrix2);
	//��ֵ΢�ַ���ֱ��
	void Line_DDA(float x1, float y1, float x2, float y2, int color_r, int color_g, int color_b);
	//�е㻭�߷���ֱ��
	void Midpoint_Line1(int x1, int y1, int x2, int y2, int color_r, int color_g, int color_b);
	//����չʾ
	void Show_Line(int x_start, int y_start, int x_end, int y_end);
	//ɨ������䷨
	void scanline_fill(vector<PII> points, int color_r, int color_g, int color_b);
	//ɨ�������ӵ���䷨
	void seed_fill(vector<PII> dot, PII seed, int color_r, int color_g, int color_b);
	
	//�������
	void draw_polygon(vector<PII> dot);
	//��ͼ��
	void draw();
	//����ͳ��ͼ
	void statistical_chart();
	void draw_column(int startx, int starty, int width, int high);
	//�������
	void symbol_fill(vector<PII> dot,int dy,int dx);//dy��dx��4�ı���


	
};

