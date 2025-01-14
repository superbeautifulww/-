#include<opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>
#include<string.h>
using namespace cv;
using namespace std;

//均值哈希
string aHash(Mat &img)
{
	//1.缩小尺寸
	resize(img, img, Size(8, 8));
	//2.简化色彩
	cvtColor(img, img, COLOR_BGR2GRAY);
	uchar *p; //uchar:0~255
	int sum = 0;
	for (int i = 0; i < img.rows; i++)
	{
		p = img.ptr<uchar>(i);     //ptr获取指向每一行首地址的指针
		for (int j = 0; j < img.cols; j++)
		{
			p[j] = p[j] / 4;   //256位转换为64位
			sum += p[j];
		}
	}
	//3.计算平均值
	int average = sum / 64;
	//4.比较像素灰度并得出哈希值
	string result;
	for (int i = 0; i < img.rows; i++)
	{
		p = img.ptr<uchar>(i);     
		for (int j = 0; j < img.cols; j++)
		{
			if (p[j] >= average) result+='1';
			else result+= '0';
		}
	}
	return result;
}

//感知哈希
string qHash(Mat &img)
{
	//1.缩小尺寸
	resize(img, img, Size(8, 8));
	//2.简化色彩
	cvtColor(img, img, COLOR_BGR2GRAY);
	uchar *p; //uchar:0~255
	for (int i = 0; i < img.rows; i++)
	{
		p = img.ptr<uchar>(i);     //ptr获取指向每一行首地址的指针
		for (int j = 0; j < img.cols; j++)
		{
			p[j] = p[j] / 4;   //256位转换为64位
		}
	}
	//3.进行离散余弦变化并求出平均值
	dct(img, img);
	double a[64];
	int k = 0;
	double sum;
	for (int i = 0; i < img.rows; ++i) {
		for (int j = 0; j < img.cols; ++j)
		{
			a[k] = img.at<double>(i, j);
			sum += img.at<double>(i, j);
			++k;
		}
	}
	double average = sum / 64;
	//4.比较像素灰度并得出哈希值
	string result;
	for (int i = 0; i < 64; i++)
	{
			if (a[i] >= average) result += '1';
			else result += '0';
	}
	return result;
}


string dHash(Mat &img)
{
	//1.缩小尺寸
	//注意缩小到9*8，后面求差值就得到8*8
	resize(img, img, Size(9, 8));
	//2.简化色彩
	cvtColor(img, img, COLOR_BGR2GRAY);
	uchar *p; //uchar:0~255
	for (int i = 0; i < img.rows; i++)
	{
		p = img.ptr<uchar>(i);     //ptr获取指向每一行首地址的指针
		for (int j = 0; j < img.cols; j++)
		{
			p[j] = p[j] / 4;   //256位转换为64位
		}
	}
	//3.差异值计算并生成哈希值
	string result;
	for (int i = 0; i < img.rows; i++)
	{
		p = img.ptr<uchar>(i);
		for (int j = 0; j < img.cols; j++)
		{
			if (img.at<double>(i, j) >= img.at<double>(i, j+1)) result += '1';
			else result += '0';
		}
	}
	return result;
}

//哈希值对比
int compare(string str1, string str2)
{
	if (str1.length() != str2.length()) return -1;
	int cnt;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] == str2[i]) cnt++;
	}
	return cnt / 64;
}

int main()
{
	Mat sakura = imread("2.jpg");
	imshow("sakura", sakura);
	waitKey(0);
	return 0;
}