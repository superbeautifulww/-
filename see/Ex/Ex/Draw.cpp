#include "Draw.h"
#include<fstream>
#include<string>
//根据窗口调整坐标
void Draw::ChangeXY(int &x, int &y, int winx_start, int winy_end)
{
	x = x + winx_start;
	y = winy_end - y;
}
void Draw::translation(int &x, int &y, int tx, int ty)//平移
{

	x = x + tx;
	y = y + ty;
}
void Draw::rotation(int x0,int y0,int &x, int &y, float theta)//旋转
{
	
	vector<vector<float>> romateMatrix = {
		{cos(theta),-sin(theta), x0*(1 - cos(theta)) + y0 * sin(theta)},
		{sin(theta),  cos(theta),y0 * (1 - cos(theta)) - x0 * sin(theta)},
		{0,0, 1},
	};
	
	float tx = x * 1.0, ty = y * 1.0;
	vector<float> t = { tx,ty,1 };
	vector<float> r = Matrix_mul(t, romateMatrix);
	x = r[0];
	y = r[1];
}
PII Draw::scaling(int x0,int y0,int x, int y,float s)
{
	vector<vector<float>> scaleMatrix = {
		{s, 0, x0*1.0f*(1 - s)},
		{0, s, y0*1.0f*(1 - s)},
		{0, 0, 0},
	};
	float tx = x * 1.0, ty = y * 1.0;
	vector<float> t = { tx,ty,1 };
	vector<float> r = Matrix_mul(t, scaleMatrix);
	x = r[0];
	y =r[1];
	return { x,y };
}

vector<float> Draw:: Matrix_mul(vector<float> &matrix1, vector<vector<float>> &matrix2)
{
	vector<float> a;
	// 进行矩阵乘法运算
	for (int i = 0; i < 3; i++) a.push_back(0);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			a[i] += matrix2[i][j] * matrix1[j];
		}

	return a;
}
void Draw::Show_Line(int x_start, int y_start, int x_end, int y_end)
{
	initgraph(1120, 720, EW_SHOWCONSOLE);//创建一个1120×720的绘图窗口
	setbkcolor(WHITE);
	cleardevice();
	//绘制表格
	setlinecolor(BLACK);
	int first_lielength = 80;//第一列宽度
	int first_hanglength = 60;//第一行宽度
	int lielength = (x_end - x_start - first_lielength) / 3;//接下来每一列宽度
	int hanglength = (y_end - y_start - first_hanglength) / 4; //接下来每一行宽度
	line(x_start, y_start, x_end, y_start);
	line(x_start, y_start, x_start, y_end);
	line(x_start + first_lielength, y_start, x_start + first_lielength, y_end);
	line(x_end, y_start, x_end, y_end);
	line(lielength + x_start + first_lielength, y_start, lielength + x_start + first_lielength, y_end);
	line(2 * lielength + x_start + first_lielength, y_start, 2 * lielength + x_start + first_lielength, y_end);
	line(x_start, y_end, x_end, y_end);
	line(x_start, y_start + first_hanglength, x_end, y_start + first_hanglength);
	line(x_start, y_start + first_hanglength + hanglength, x_end, y_start + first_hanglength + hanglength);
	line(x_start, y_start + first_hanglength + 2 * hanglength, x_end, y_start + first_hanglength + 2 * hanglength);
	line(x_start, y_start + first_hanglength + 3 * hanglength, x_end, y_start + first_hanglength + 3 * hanglength);
	settextcolor(BLUE);
	outtextxy(x_start + first_lielength + 110, y_start + first_hanglength / 2, "EasyX函数绘制");
	settextcolor(RED);
	outtextxy(x_start + first_lielength + lielength + 100, y_start + first_hanglength / 2, "数值微分法函数绘制");
	settextcolor(GREEN);
	outtextxy(x_start + first_lielength + 2 * lielength + 100, y_start + first_hanglength / 2, "中点划线法函数绘制");
	settextcolor(BLACK);
	outtextxy(x_start + 20, y_start + first_hanglength + 60, "左斜线");
	outtextxy(x_start + 20, y_start + first_hanglength + hanglength + 60, "右斜线");
	outtextxy(x_start + 20, y_start + first_hanglength + 2 * hanglength + 60, "竖直线");
	outtextxy(x_start + 20, y_start + first_hanglength + 3 * hanglength + 60, "水平线");


	//EasyX函数绘制
	setlinecolor(BLUE);
	//左斜线
	int x1 = 20, y1 = 20, x2 = 300, y2 = 120;
	ChangeXY(x1, y1, x_start + first_lielength, y_start + first_hanglength + hanglength);
	ChangeXY(x2, y2, x_start + first_lielength, y_start + first_hanglength + hanglength);
	line(x1, y1, x2, y2);
	//右斜线
	x1 = 20, y1 = 120, x2 = 300, y2 = 20;
	ChangeXY(x1, y1, x_start + first_lielength, y_start + first_hanglength + 2 * hanglength);
	ChangeXY(x2, y2, x_start + first_lielength, y_start + first_hanglength + 2 * hanglength);
	line(x1, y1, x2, y2);
	//竖直线
	x1 = 150, y1 = 120, x2 = 150, y2 = 20;
	ChangeXY(x1, y1, x_start + first_lielength, y_start + first_hanglength + 3 * hanglength);
	ChangeXY(x2, y2, x_start + first_lielength, y_start + first_hanglength + 3 * hanglength);
	line(x1, y1, x2, y2);
	//水平线
	x1 = 20, y1 = 70, x2 = 300, y2 = 70;
	ChangeXY(x1, y1, x_start + first_lielength, y_start + first_hanglength + 4 * hanglength);
	ChangeXY(x2, y2, x_start + first_lielength, y_start + first_hanglength + 4 * hanglength);
	line(x1, y1, x2, y2);


	//数值微分法函数绘制
	//左斜线
	x1 = 20, y1 = 20, x2 = 300, y2 = 120;
	ChangeXY(x1, y1, x_start + first_lielength + lielength, y_start + first_hanglength + hanglength);
	ChangeXY(x2, y2, x_start + first_lielength + lielength, y_start + first_hanglength + hanglength);

	Line_DDA(x1, y1, x2, y2, 255, 0, 0);
	//右斜线
	x1 = 20, y1 = 120, x2 = 300, y2 = 20;
	ChangeXY(x1, y1, x_start + first_lielength + lielength, y_start + first_hanglength + 2 * hanglength);
	ChangeXY(x2, y2, x_start + first_lielength + lielength, y_start + first_hanglength + 2 * hanglength);
	Line_DDA(x1, y1, x2, y2, 255, 0, 0);
	//竖直线
	x1 = 150, y1 = 120, x2 = 150, y2 = 20;
	ChangeXY(x1, y1, x_start + first_lielength + lielength, y_start + first_hanglength + 3 * hanglength);
	ChangeXY(x2, y2, x_start + first_lielength + lielength, y_start + first_hanglength + 3 * hanglength);
	Line_DDA(x1, y1, x2, y2, 255, 0, 0);
	//水平线
	x1 = 20, y1 = 70, x2 = 300, y2 = 70;
	ChangeXY(x1, y1, x_start + first_lielength + lielength, y_start + first_hanglength + 4 * hanglength);
	ChangeXY(x2, y2, x_start + first_lielength + lielength, y_start + first_hanglength + 4 * hanglength);
	Line_DDA(x1, y1, x2, y2, 255, 0, 0);


	//中点划线法函数绘制
	//左斜线
	x1 = 20, y1 = 20, x2 = 300, y2 = 120;
	ChangeXY(x1, y1, x_start + first_lielength + 2 * lielength, y_start + first_hanglength + hanglength);
	ChangeXY(x2, y2, x_start + first_lielength + 2 * lielength, y_start + first_hanglength + hanglength);
	cout << "左" << endl;
	Midpoint_Line1(x1, y1, x2, y2, 0, 255, 0);
	//右斜线
	x1 = 20, y1 = 120, x2 = 300, y2 = 20;
	ChangeXY(x1, y1, x_start + first_lielength + 2 * lielength, y_start + first_hanglength + 2 * hanglength);
	ChangeXY(x2, y2, x_start + first_lielength + 2 * lielength, y_start + first_hanglength + 2 * hanglength);
	cout << "右" << endl;
	Midpoint_Line1(x1, y1, x2, y2, 0, 255, 0);
	//竖直线
	x1 = 150, y1 = 120, x2 = 150, y2 = 20;
	ChangeXY(x1, y1, x_start + first_lielength + 2 * lielength, y_start + first_hanglength + 3 * hanglength);
	ChangeXY(x2, y2, x_start + first_lielength + 2 * lielength, y_start + first_hanglength + 3 * hanglength);
	cout << "竖" << endl;
	Midpoint_Line1(x1, y1, x2, y2, 0, 255, 0);
	//水平线
	x1 = 20, y1 = 70, x2 = 300, y2 = 70;
	ChangeXY(x1, y1, x_start + first_lielength + 2 * lielength, y_start + first_hanglength + 4 * hanglength);
	ChangeXY(x2, y2, x_start + first_lielength + 2 * lielength, y_start + first_hanglength + 4 * hanglength);
	cout << "平" << endl;
	Midpoint_Line1(x1, y1, x2, y2, 0, 255, 0);
	if (_getch()) closegraph();
}

void Draw::Midpoint_Line1(int x1, int y1, int x2, int y2, int color_r, int color_g, int color_b)
{
	bool f1 = 0, f2 = 0;
	//putpixel(x1, y1, RGB(color_r, color_g, color_b));
	if (abs(y1 - y2) > abs(x2 - x1))//|k|>1
	{
		swap(x1, y1);
		swap(x2, y2);
		f1 = 1;
	}
	if (x1 > x2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	if ((y1 - y2)*(x2 - x1) > 0)//k<0
	{
		y1 = -y1;
		y2 = -y2;
		f2 = 1;
	}
	int a = y1 - y2;
	int b = x2 - x1;
	int d, d1, d2;
	d = 2 * a + b;
	d1 = 2 * a;
	d2 = 2 * (a + b);
	int tx = x1, ty = y1;
	while (tx < x2)
	{
		if (d < 0)
		{
			tx++, ty++, d += d2;
		}
		else
		{
			tx++, d += d1;
		}
		int px = tx, py = ty;
		if (f2) py = -py;
		if (f1) swap(px, py);
		putpixel(px, py, RGB(color_r, color_g, color_b));
	}
}
void Draw::Line_DDA(float x1, float y1, float x2, float y2, int color_r, int color_g, int color_b)
{
	float stepx, stepy, steps;
	putpixel(x1, y1, RGB(color_r, color_g, color_b));
	stepx = x2 - x1;
	stepy = y2 - y1;
	if (fabs(stepx) > fabs(stepy)) steps = fabs(stepx);
	else steps = fabs(stepy);
	stepx /= steps;
	stepy /= steps;
	float curx = x1, cury = y1;
	for (int i = 0; i < steps; i++)
	{
		curx += stepx;
		cury += stepy;
		putpixel(round(curx), round(cury), RGB(color_r, color_g, color_b));
	}
}

void Draw::scanline_fill(vector<PII> points,int color_r, int color_g, int color_b)
{
	edgetable ET(points);
	vector<edge> AET;
	for (int i = ET.ymin; i <ET.ymax; i++)
	{
		ET.update(AET, i);
		ET.add1(AET, i);
		sort(AET.begin(), AET.end(), cmp);
		for (int j = 0; j < AET.size() - 1; j += 2)
		{
			Midpoint_Line1(AET[j].x, i, AET[j + 1].x, i,color_r,color_g,color_b);
		}
	}
}

//扫描线种子点填充法
void Draw::seed_fill(vector<PII> dot, PII seed, int color_r, int color_g, int color_b)
{
	int n = dot.size();
	setlinecolor(BLACK);
	int line_color_r = 0, line_color_g = 0, line_color_b = 0;

	for (int i = 0; i < n - 1; i++)
	{
		line(dot[i].x, dot[i].y, dot[i + 1].x, dot[i + 1].y);
	}
	line(dot[n - 1].x, dot[n - 1].y, dot[0].x, dot[0].y);
	stack<PII> S;
	S.push(seed);
	int xl, xr;
	while (S.size())
	{
		int tx = S.top().x, ty = S.top().y;
		S.pop();
		//putpixel(tx, ty, RGB(color_r, color_g, color_b));
		int p = tx;//指向当前点的指针
		while (getpixel(p, ty) != BLACK)
		{
			putpixel(p, ty, RGB(color_r, color_g, color_b));
			p--;
		}
		xl = p;
		p = tx + 1;
		while (getpixel(p, ty) != BLACK)
		{
			putpixel(p, ty, RGB(color_r, color_g, color_b));
			p++;
		}
		xr = p;

		for (int i = xl + 1; i < xr; i++)
		{
			if (getpixel(i, ty - 1) == WHITE)
			{
				int j = i;
				while (getpixel(j, ty - 1) == WHITE) j++;
				i = --j;
				S.push({ j ,ty - 1 });
			}
		}

		for (int i = xl + 1; i < xr; i++)
		{
			if (getpixel(i, ty + 1) == WHITE)
			{
				int j = i + 1;
				while (getpixel(j, ty + 1) != BLACK) j++;
				i = j--;
				S.push({ j,ty + 1 });
			}
		}
	}
}
void Draw::draw_polygon(vector<PII> dot)
{
	int n = dot.size();

	for (int i = 0; i < n - 1; i++)
	{
		Midpoint_Line1(dot[i].x, dot[i].y, dot[i + 1].x, dot[i + 1].y, 0, 0, 0);
	}
	Midpoint_Line1(dot[n - 1].x, dot[n - 1].y, dot[0].x, dot[0].y,0,0,0);
}
void Draw::draw()
{
	/*
	initgraph(800, 800, EW_SHOWCONSOLE);//创建一个800×800的绘图窗口
	setbkcolor(WHITE);
	cleardevice();*/
	setcolor(BLACK);
	//setfillcolor(RGB(243, 243, 208));
	setfillcolor(RGB(220, 243, 255));
	fillcircle(402, 403, 377.5);
	COLORREF color[4] = { RGB(188, 223, 121),RGB(122,106,91),RGB(169,133,104),RGB(179, 221, 47) };
	vector<PII> dot[4];
	 dot[0] = {
	{306,161},{307,161},{307,160},{312,158},{323,157},{338,157},{357,157},
	{362,158},{369,161},{374,162},{374,163},{376,163},{378,164},{399,178},
	{403,182},{408,188},{414,198},{425,215},{430,226},{434,243},{436,254},
	{437,270},{434,281},{440,275},{456,265},{466,259},{486,252},{499,250},
	{512,250},{526,251},{538,253},{561,259},{573,263},{591,270},{601,274},
	{609,279},{615,284},{619,289},{621,295},{619,301},{610,308},{590,309},
	{573,308},{561,308},{543,308},{543,308},{494,303},{476,304},{457,311},
	{447,317},{459,315},{477,315},{487,315},{506,318},{508,319},{519,324},
	{530,331},{542,342},{546,347},{552,354},{556,362},{558,363},{560,369},
	{563,379},{566,391},{566,395},{566,406},{562,415},{553,419},{550,419},
	{547,419},{542,416},{541,415},{534,410},{528,403},{516,391},{500,378},
	{488,367},{478,360},{464,351},{450,343},{443,340},{432,346},{427,335},
	{422,329},{411,323},{404,321},{394,324},{385,329},{379,336},{374,345},
	{370,340},{363,338},{341,353},{331,359},{326,362},{317,368},{301,381},
	{284,397},{274,408},{265,415},{254,420},{250,419},{244,414},{240,407},
	{241,395},{242,385},{246,373},{244,376},{250,365},{258,351},{265,342},
	{282,327},{294,322},{302,319},{314,316},{333,314},{339,314},{350,315},
	{360,316},{350,311},{335,306},{326,305},{314,304},{291,305},{285,306},
	{264,308},{244,309},{226,310},{209,310},{197,307},{187,302},{186,295},
	{194,283},{195,280},{206,275},{214,270},{238,262},{248,259},{261,255},
	{282,251},{296,249},{310,250},{322,252},{334,255},{341,259},{352,264},
	{364,274},{372,281},{385,291},{386,279},{384,270},{371,247},{368,239},
	{353,218},{344,205},{338,198},{329,187},{315,174}

	};
	
	 dot[1] = {
	{432,346},{429,358},{430,357},{426,365},{418,375},{413,376},{409,377},
	{404,379},{401,379},{398,378}, {396,377},{390,376},
	{385,371},//树干
	{382,370},{380,364},{379,362},{375,355} ,{374,345},{382,436},{381,464},
	{381,488},{379,505},{378,526},{376,549},{376,593},{375,607},{375,612},
	{372,630},{370,639},{367,644},{366,646},{362,648},{359,650},{353,654},{338,656},
	{322,658},//小树干右
	{308,662}, {298,665},{287,669},
	{270,678},//小树干左
	{263,683},{244,698},{238,706},{237,708},{233,712},{231,719},{230,727},
	{229,721},{228,735},
	{227,738},//大树干底部左
	{234,740},{247,748},{250,749},{251,751},{255,752},{260,755},{272,759},
	{289,765},{302,768},
	{315,771},{335,775},{342,776},{353,778},{370,780},{374,781},{375,780},
	{399,781},{404,781},{432,779},{470,776},{471,776},{479,773},{482,773},
	{486,772},{494,770},{496,769},{498,769},{509,766},{514,765},
	{523,762},{524,761},{531,759},{535,757},{542,754},{559,746},
	{578,737},//大树干底部右
	{579,733},{577,722},{571,709},{568,706},{557,692},{548,684},{542,680},
	{534,676},{517,668},{489,659},{486,658},{458,653},{454,652},{447,650},
	{440,641},{438,638},{435,633},{432,609},{430,561},{430,541},{429,525},
	{426,472},{426,455},{425,408}
	};
	
	 dot[2] = {
	{322,658},{318,649},{301,608},{277,549},
	{270,532},//小树干上右
	{264,530},{259,530},{258,530},{254,530},{250,530},{243,533},
	{239,535},//小树干上左
	{247,548},{258,569},{266,597},{270,617},{273,653},{270,678},{308,662},
	{298,665},{287,669}
	};

	 dot[3] = {
	{270,532},{264,530},{259,530},{258,530},{254,530},{250,530},{243,533},
	{239,535},{229,542},{220,558},{213,574},{209,588},{205,599},{201,611},
	{196,614},{192,613},{189,612},{181,601},{178,586},{177,574},{180,553},
	{182,538},{186,530},{171,539},{162,545},{150,553},{144,554},{135,552},
	{133,546},{134,530},{140,517},{144,509},{147,506},{155,498},{160,496},
	{170,491},{185,489},{201,489},{189,478},{176,470},{161,465},{165,454},
	{172,450},{176,449},{186,446},{198,446},{211,449},{223,453},{235,462},
	{240,468},{250,460},{257,457},{271,454},{287,455},{306,462},{310,466},
	{314,474},{310,478},{312,477},{298,485},{290,489},{274,501},{286,508},
	{290,512},{294,514},
	{300,520},{305,523},{314,534},{316,537},{318,540},{322,545},{325,551},
	{325,559},{320,561},{308,554},{290,542}
	};
	
	 for (int i = 0; i <= 3; i++)
	 {
		 scanline_fill(dot[i], GetRValue(color[i]),GetGValue(color[i]),GetBValue(color[i]));
		 draw_polygon(dot[i]);
	 }
	
	setfillcolor(RGB(250, 177, 178));
	fillcircle(403, 351, 29);
	//if (_getch()) closegraph();
}
void Draw::statistical_chart()
{
	initgraph(900, 750, EW_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	ifstream fin("stastical_result.txt");
	settextcolor(BLACK);
	outtextxy(340, 50, "遥感专业2021级学生分省统计图");
	char str[100];
	int cnt;
	int width = 35, chigh = 20;
	int startx = 100, starty = 100;
	Midpoint_Line1(startx,starty,startx+720,starty,0,0,0);
	Midpoint_Line1(startx+720,starty,startx+720,starty+600,0,0,0);
	Midpoint_Line1(startx + 720, starty + 600, startx, starty + 600,0,0,0);
	Midpoint_Line1(startx, starty + 600, startx, starty,0,0,0);
	outtextxy(startx - 20, starty + 600 - 10, "0");
	outtextxy(startx - 20, starty - 10, "30");
	Midpoint_Line1(startx, starty + 100, startx + 720, starty + 100, 211, 211, 211);
	outtextxy(startx - 20, starty + 100 - 10, "25");
	Midpoint_Line1(startx, starty + 200, startx + 720, starty + 200, 211, 211, 211);
	outtextxy(startx - 20, starty + 200 - 10, "20");
	Midpoint_Line1(startx, starty + 300, startx + 720, starty + 300, 211, 211, 211);
	outtextxy(startx - 20, starty + 300 - 10, "15");
	Midpoint_Line1(startx, starty + 400, startx + 720, starty + 400, 211, 211, 211);
	outtextxy(startx - 20, starty + 400 - 10, "10");
	Midpoint_Line1(startx, starty + 500, startx + 720, starty + 500, 211, 211, 211);
	outtextxy(startx - 20, starty + 500 - 10, "5");
	
	int i = 0;
	while (fin >> str >> cnt)
	{
		int tx= startx + 10 + i * width, ty = starty+600;
		outtextxy(tx, ty+10, str);
		int high = chigh * cnt;
		draw_column(tx,ty , width, high);
		i++;
		char num[10];
		string st = to_string(cnt);
		strcpy_s(num, st.c_str());
		outtextxy(tx+width/2, ty - high-20, num);
	}
	
	fin.close();
	if (_getch()) closegraph();
}
void Draw::draw_column(int startx, int starty, int width, int high)
{
	vector<PII> dot;
	dot.push_back({ startx,starty });
	dot.push_back({ startx + width,starty });
	dot.push_back({ startx + width,starty -high });
	dot.push_back({ startx,starty -high });
	//seed_fill(dot, { startx + 1,starty - 1 }, 0, 255, 0);
	symbol_fill(dot, 20, 20);
	draw_polygon(dot);
}
void Draw::symbol_fill(vector<PII> dot, int dy, int dx)
{
	edgetable ET(dot);
	vector<edge> AET;
	int y1 = ET.ymin + dy / 2;
	int x1 = ET.xmin + dx / 4;
	int l = (ET.ymax - ET.ymin) / dy - 1;
	//ET.update(AET,y1);
	//ET.add2(AET,y1,dy);
	int yi;
	for (int i = 1; i <= l+1; i++)
	{
		yi = y1 + (i - 1)*dy;
		ET.update(AET, yi);
		ET.add2(AET, yi,dy);
		sort(AET.begin(), AET.end(), cmp);
		for (int j = 0; j < AET.size() - 1; j += 2)
		{
			int tx1 = AET[j].x, tx2 = AET[j+1].x;
			for (int k = tx1 / (dx / 2) + 1; k <tx2 / (dx / 2); k++)
			{
				setfillcolor(RGB(250, 177, 178));
				fillcircle((dx / 2)*k, yi, 3);
			}
		}
		
	}
}
