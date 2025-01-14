#include "interection.h"
void interection::mouse_draw_line()
{
	int startX, startY, endX, endY;
	// ѭ�����������Ϣ
	while (!_kbhit())
	{
		MOUSEMSG msg = GetMouseMsg();
		// ������������ʱ
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			// ���֮ǰ�Ѿ�ѡ���������㣬��������ֱ��
			if (points.size() >= 1)
			{
				startX = points.back().x;
				startY = points.back().y;
				endX = msg.x;
				endY = msg.y;
				// ��ֱ��
				D.Midpoint_Line1(startX, startY, endX, endY, 0, 0, 0);
			}
			PII point = { msg.x, msg.y };
			points.push_back(point);
		}
		// ������Ҽ�����ʱ�����ƶ����
		if (msg.uMsg == WM_RBUTTONDOWN)
		{
			int n = points.size();
			// ������Ҫ����������ܻ��ƶ����
			isok = 1;
			if (n >= 3)
			{
				// ���ƶ����
				D.Midpoint_Line1(points[0].x, points[0].y, points[n - 1].x, points[n - 1].y, 0, 0, 0);
			}
			return;
		}
	}
}
void interection::is_inside_polygon(bool &isDragging, MOUSEMSG m,PII startpos )
{
	int n = points.size();
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if ((points[i].y <= m.y && points[(i + 1) % n].y > m.y) || (points[(i + 1) % n].y <= m.y && points[i].y > m.y))
		{
			// ����������ߵĽ���� x ����
			int x = (m.y - points[i].y) * (points[(i + 1) % n].x - points[i].x) / (points[(i + 1) % n].y - points[i].y) + points[i].x;

			// �������� x ������ڵ��ڵ����� x ���꣬�����ӽ�������
			if (x >= m.x)
				count++;
		}
	}
	if (count % 2 == 1)
	{
		startpos = { m.x,m.y };
		isDragging = true;
	}
}
void interection::is_in_line(bool &isDragging, MOUSEMSG m, PII startpos)
{
	int d1 = (m.x - points[0].x) * (points[1].y - points[0].y);
	int d2 = (points[1].x - points[0].x) * (m.y - points[0].y);
	int d = abs(d1 - d2);
	if (d < 3 * abs(points[1].y - points[0].y))
	{
		startpos = { m.x,m.y };
		isDragging = true;
	}
}

void interection::draw_option(RECT &rect, const char* text, int x, int y)
{
	settextcolor(BLACK);
	settextstyle(20, 0, _T("΢���ź�"));
	outtextxy(x, y, text);
	int textWidth = textwidth(text);
	int textHeight = textheight(text);
	rect.left = x;
	rect.top = y;
	rect.right = x + textWidth;
	rect.bottom = y + textHeight;
	setcolor(BLACK);
	rectangle(rect.left - 4, rect.top - 4, rect.right + 4, rect.bottom + 4);
}
void interection::draw_menu()
{
	initgraph(640, 480, EW_SHOWCONSOLE);  // ��ʼ��ͼ�δ���
	setbkcolor(WHITE);
	cleardevice();

	RECT rect1;
	draw_option(rect1, _T("����/�����"), 50, 50);

	RECT rect2;
	draw_option(rect2, _T("ɨ�������"), 50, 100);

	RECT rect3;
	draw_option(rect3, _T("ɨ�������ӵ����"), 50, 150);

	RECT rect4;
	draw_option(rect4, _T("ƽ��"), 50, 200);

	RECT rect5;
	draw_option(rect5, _T("��ת"), 50, 250);

	RECT rect6;
	draw_option(rect6, _T("����"), 50, 300);


	RECT rect7;
	draw_option(rect7, _T("��ջ�ͼ��"), 50, 350);
	rectangle(180, 30, 610, 450);
	while (!_kbhit())
	{
		MOUSEMSG msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN)
		{
			//���ߡ������
			if (msg.x >= rect1.left - 4 && msg.x <= rect1.right + 4 && msg.y <= rect1.bottom + 4 && msg.y > rect1.top - 4)
			{
				points.clear();
				mouse_draw_line();
			}
			//ɨ�������
			else if (msg.x >= rect2.left - 4 && msg.x <= rect2.right + 4 && msg.y <= rect2.bottom + 4 && msg.y > rect2.top - 4)
			{
				if(isok) D.scanline_fill(points,255, 0, 0);
			}
			//ɨ�������ӵ����
			else if (msg.x >= rect3.left - 4 && msg.x <= rect3.right + 4 && msg.y <= rect3.bottom + 4 && msg.y > rect3.top - 4)
			{
				if (isok)
				{
					while (!_kbhit())
					{
						MOUSEMSG seedMsg = GetMouseMsg();
						if (seedMsg.uMsg == WM_LBUTTONDOWN)
						{
							PII seed = { seedMsg.x, seedMsg.y };
							if (seed.x > 180 && seed.y > 30 && seed.x < 610 && seed.y < 450)
							{
								D.seed_fill(points, seed, 255, 0, 0);
							}
							break;
						}
					}
				}
			}
			//ƽ��
			else if (msg.x >= rect4.left - 4 && msg.x <= rect4.right + 4 && msg.y <= rect4.bottom + 4 && msg.y > rect4.top - 4)
			{
				I_translation();
			}
			//��ת
			else if (msg.x >= rect5.left - 4 && msg.x <= rect5.right + 4 && msg.y <= rect5.bottom + 4 && msg.y > rect5.top - 4)
			{
				I_rotation();
				continue;
			}
			//����
			else if (msg.x >= rect6.left - 4 && msg.x <= rect6.right + 4 && msg.y <= rect6.bottom + 4 && msg.y > rect6.top - 4)
			{
				
				I_scaling(181, 31, 609, 449);
			}
			//��ջ�ͼ��
			else if (msg.x >= rect7.left - 4 && msg.x <= rect7.right + 4 && msg.y <= rect7.bottom + 4 && msg.y > rect7.top - 4)
			{
				setfillcolor(WHITE);
				bar(181, 31, 609, 449);
				points.clear();
			}
		}

	}
}

void interection::symbol_menu()
{
	initgraph(1200, 800, EW_SHOWCONSOLE);//����һ��800��800�Ļ�ͼ����
	setbkcolor(WHITE);
	cleardevice();
	setcolor(BLACK);
	RECT rect1;
	draw_option(rect1, _T("����ͼ��"), 1100, 50);

	RECT rect2;
	draw_option(rect2, _T("ƽ��"), 1100, 100);

	RECT rect3;
	draw_option(rect3, _T("��ת"), 1100, 150);

	RECT rect4;
	draw_option(rect4, _T("����"), 1100, 200);

	while (!_kbhit())
	{
		MOUSEMSG msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN)
		{ 
			//����ͼ��
			if (msg.x >= rect1.left - 4 && msg.x <= rect1.right + 4 && msg.y <= rect1.bottom + 4 && msg.y > rect1.top - 4)
			{
				D.draw();
			}
		   else if (msg.x >= rect2.left - 4 && msg.x <= rect2.right + 4 && msg.y <= rect2.bottom + 4 && msg.y > rect2.top - 4)
		   {
				translation_symbol();
		   }
		   else if (msg.x >= rect3.left - 4 && msg.x <= rect3.right + 4 && msg.y <= rect3.bottom + 4 && msg.y > rect3.top - 4)
			{
				rotation_symbol();
				continue;
			}
		   else if (msg.x >= rect4.left - 4 && msg.x <= rect4.right + 4 && msg.y <= rect4.bottom + 4 && msg.y > rect4.top - 4)
			{
				scaling_symbol();
			}
		}
	}

	if (_getch()) closegraph();
}

void interection::I_translation()
{
	bool isDragging = false;
	PII startpos, tagpos;
	int n = points.size();
	while (!_kbhit() && isDragging == false) // �������̰����¼�
	{
		MOUSEMSG m = GetMouseMsg();
		startpos = { m.x,m.y };
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			// �жϵ��Ƿ���ֱ���ϣ�����һ������Χ��
			if (n == 2)	is_in_line(isDragging, m, startpos);
			//�жϵ��Ƿ��ڶ�����ڲ�(���߷�)
			else is_inside_polygon(isDragging, m, startpos);
		}
	}
	cout << isDragging;
	while (!_kbhit())
	{
		MOUSEMSG m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			tagpos = { m.x, m.y };
			break;
		}
	}
	int tx = tagpos.x - startpos.x;
	int ty = tagpos.y - startpos.y;
	n = points.size();
	for (int i = 0; i < n; i++)
	{
		//cout << "ǰ"<<points[i].x << " " << points[i].y << endl;
		D.translation(points[i].x, points[i].y, tx, ty);
		//cout << "��"<<points[i].x << " " << points[i].y << endl;
	}
	D.draw_polygon(points);
}
void interection::I_rotation()
{
	char s[10];
	InputBox(s, 10, "��������ת�Ƕ�");
	float r = atof(s);
	//float r = 0;
	// ���û�����ת��Ϊ����
	//for (int i = 0; i < 10; i++) r = r * 10 + (s[i] - '0');
	int cx = points[0].x, cy = points[0].y;//������ת����Ϊ����ε�һ���˵�
	int n = points.size();

	for (int i = 0; i < n; i++)
	{
		D.rotation(cx, cy, points[i].x, points[i].y, r * 3.1415926 / 180);
	}
	D.draw_polygon(points);
}
void interection::I_scaling(int x1,int y1,int x2,int y2)
{
	float s = 1; // ��������
	vector<PII> temp;
	while (!_kbhit())
	{
		MOUSEMSG m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEWHEEL) // ��⵽�������¼�
		{
			// �����Ļ
			setfillcolor(WHITE);
			bar(x1,y1,x2,y2);
			if (m.wheel > 0) // ���Ϲ������Ŵ�ͼ��
				s += 0.1;
			else if (m.wheel < 0 && s>0.3) // ���¹�������Сͼ�Σ�����������С��С��1
				s -= 0.1;
		}
		int cx = points[0].x, cy = points[0].y;
		//��ͼ
		int n = points.size();
		temp.clear();
		for (int i = 0; i < n; i++)
		{
			temp.push_back(D.scaling(cx, cy, points[i].x, points[i].y, s));
		}
		D.draw_polygon(temp);
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			break;
		}
	}
}

void interection::translation_symbol()
{
	setcolor(BLACK);
	int tcx1 = cx1, tcy1 = cy1, tr1 = r1;
	int tcx2 = cx2, tcy2 = cy2, tr2 = r2;
	vector<PII> tdot[4];
	for (int i = 0; i <= 3; i++)
	{
		for (auto it : dot[i])
		{
			tdot[i].push_back(it);
		}
	}
	char s1[10];
	InputBox(s1, 10, "������x�����ƽ�ƾ���");
	float tx= atof(s1);
	char s2[10];
	InputBox(s2, 10, "������y�����ƽ�ƾ���");
	float ty = atof(s1);
	D.translation(tcx1, tcy1, tx, ty);
	setfillcolor(WHITE);
	bar(0, 0, 1050, 800);
	setfillcolor(RGB(220, 243, 255));
	fillcircle(tcx1, tcy1, tr1);
	for (int i = 0; i <= 3; i++)
	{
		int n = tdot[i].size();
		for (int j = 0; j < n; j++)
		{
			D.translation(tdot[i][j].x, tdot[i][j].y, tx, ty);
		}
		D.scanline_fill(tdot[i], GetRValue(color[i]), GetGValue(color[i]), GetBValue(color[i]));
		D.draw_polygon(tdot[i]);
	}
	D.translation(tcx2, tcy2, tx, ty);
	setfillcolor(RGB(250, 177, 178));
	fillcircle(tcx2, tcy2, tr2);
}

void interection::rotation_symbol()
{
	
	int tcx1 = cx1, tcy1 = cy1, tr1 = r1;
	int tcx2 = cx2, tcy2 = cy2, tr2 = r2;
	vector<PII> tdot[4];
	for (int i = 0; i <= 3; i++)
	{
		for (auto it : dot[i])
		{
			tdot[i].push_back(it);
		}
	}
	int cx = cx1, cy = cy1;//������ת����
	
	char s[10];
	InputBox(s, 10, "��������ת�Ƕ�");
	float a = atof(s);
	//��ջ�ͼ��
	setfillcolor(WHITE);
	bar(0, 0, 800, 999);
	D.rotation(cx, cy, tcx1, tcy1, a * 3.14159 / 180);	
	setfillcolor(WHITE);
	bar(0, 0, 1050, 800);
	setfillcolor(RGB(220, 243, 255));
	fillcircle(tcx1, tcy1, tr1);
	for (int i = 0; i <= 3; i++)
	{
		int n = tdot[i].size();
		for (int j = 0; j < n; j++)
		{
			D.rotation(cx, cy, tdot[i][j].x, tdot[i][j].y, a * 3.14159 / 180);
		}
		D.scanline_fill(tdot[i], GetRValue(color[i]), GetGValue(color[i]), GetBValue(color[i]));
		D.draw_polygon(tdot[i]);
	}
	D.rotation(cx, cy, tcx2, tcy2, a * 3.14159 / 180);
	setfillcolor(RGB(250, 177, 178));
	fillcircle(tcx2, tcy2, tr2);
}

void interection::scaling_symbol()
{
	
	setcolor(BLACK);
	
	int tcx1 = cx1, tcy1 = cy1, tr1 = r1;
	
	vector<PII> tdot[4];
	for (int i = 0; i <= 3; i++)
	{
		for (auto it : dot[i])
		{
			tdot[i].push_back(it);
		}
	}
	
	int tcx2 = cx2, tcy2 = cy2, tr2 = r2;
	
	float s = 1; // ��������
	while (!_kbhit())
	{
		MOUSEMSG m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEWHEEL) // ��⵽�������¼�
		{
			// ��ջ�ͼ��
			setfillcolor(WHITE);
			bar(0, 0, 1050, 800);
			for (int i = 0; i <= 3; i++) tdot[i].clear();
			if (m.wheel > 0) // ���Ϲ������Ŵ�ͼ��
				s += 0.1;
			else if (m.wheel < 0 && s>0.3) // ���¹�������Сͼ�Σ�����������С��С��0.3
				s -= 0.1;
		
			int cx = cx1, cy = cy1;
			//��ͼ
			setfillcolor(RGB(220, 243, 255));
			PII t = D.scaling(cx, cy, cx1, cy1, s);
			tcx1 = t.x, tcy1 = t.y;
			fillcircle(tcx1, tcy1, tr1*s);
			
			for (int i = 0; i <= 3; i++)
			{
				int n = dot[i].size();
				for (int j = 0; j < n; j++)
				{
					tdot[i].push_back(D.scaling(cx, cy, dot[i][j].x, dot[i][j].y, s));
				}
				D.draw_polygon(tdot[i]);
				D.scanline_fill(tdot[i],GetRValue(color[i]), GetGValue(color[i]), GetBValue(color[i]));
			}
			setfillcolor(RGB(250, 177, 178));
			t = D.scaling(cx, cy, cx2, cy2, s);
			tcx2 = t.x, tcy2 = t.y;
			fillcircle(tcx2, tcy2, tr2*s);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				break;
			}
	    }
	}
	
}
