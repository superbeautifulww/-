#pragma once
#include<GL\glew.h>
#include<GLFW\glfw3.h>
#include<stdlib.h>
#include"glut.h"
#include<iostream>
#include<vector>
using namespace std;

struct Point
{
	float x, y, z;
};

struct Face
{
	GLuint indices[4];
	GLfloat color[3];
};

struct PFF
{
	float x, y;
};
class draw_3D
{
	
public:
	//顶点
	Point points[8] = {
		{ -0.5f, -0.5f, 0.5f },  // 0
		{ 0.5f, -0.5f, 0.5f },   // 1
		{ 0.5f, 0.5f, 0.5f },    // 2
		{ -0.5f, 0.5f, 0.5f },   // 3
		{ -0.5f, -0.5f, -0.5f }, // 4
		{ 0.5f, -0.5f, -0.5f },  // 5
		{ 0.5f, 0.5f, -0.5f },   // 6
		{ -0.5f, 0.5f, -0.5f }   // 7
	};

	//设置每一面的颜色
	Face facescolor[6] = {
		{ { 0, 1, 2, 3 }, { 1.0f, 0.0f, 0.0f } }, // Front face (red)
		{ { 1, 5, 6, 2 }, { 0.0f, 1.0f, 0.0f } }, // Right face (green)
		{ { 5, 4, 7, 6 }, { 0.0f, 0.0f, 1.0f } }, // Back face (blue)
		{ { 4, 0, 3, 7 }, { 1.0f, 1.0f, 0.0f } }, // Left face (yellow)
		{ { 3, 2, 6, 7 }, { 1.0f, 0.0f, 1.0f } }, // Top face (purple)
		{ { 4, 5, 1, 0 }, { 0.0f, 1.0f, 1.0f } }  // Bottom face (cyan)
	};
	void drawCube();
	static void renderScene();
	void start2(int argc, char ** argv);
	
	
	 void render();
	
	 void reshape(int width, int height);
	float convertX(float x);
	float convertY(float y);
	
	
	void drawCircle(float centerX, float centerY, float radius, float R, float G, float B, vector<vector<float>> &matrix);
	void drawMultipleShapes(vector<vector<float>> &matrix);
	void init();
	
	void start1(int argc, char** argv);
	vector<float> Matrix_mul(vector<float> &matrix1, vector<vector<float>> &matrix2);
	
};

static void renderWrapper()
{
	draw_3D D;
	D.render();
}

static void reshapeWrapper(int width, int height)
{
	draw_3D D;
	D.reshape(width, height);
}