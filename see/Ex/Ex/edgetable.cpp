#include "edgetable.h"
#include<cstring>
edgetable::edgetable(vector<PII> dot)
{
	memset(st, 0, sizeof(st));
	int n = dot.size();
	for (int i = 0; i < n - 1; i++)
	{
		ET.push_back(edge(dot[i], dot[i + 1]));
		st[min(dot[i].y, dot[i + 1].y)] = 1;
		xmin = min(dot[i].x, xmin);
		xmax = max(dot[i].x, xmax);
		ymin = min(dot[i].y, ymin);
		ymax = max(dot[i].y, ymax);
	}
	ET.push_back(edge(dot[0], dot[n-1]));
	st[min(dot[0].y, dot[n-1].y)] = 1;
	xmin = min(dot[n-1].x, xmin);
	xmax = max(dot[n-1].x, xmax);
	ymin = min(dot[n-1].y, ymin);
	ymax = max(dot[n-1].y, ymax);
}
void edgetable::add1(vector<edge> &AET,int y)
{
	for (auto it : ET)
	{
		if (it.y1 == y&&it.y1!=it.y2)
		{
			AET.push_back(it);
		}
	}

}
void edgetable::update(vector<edge> &AET,int y)
{
	for (int i = 0; i < AET.size(); i++)
	{
		
		if (AET[i].y2 <= y)
		{
			swap(AET[i], AET[AET.size()-1]);
			AET.pop_back();
			i--;
		}
		else AET[i].x += AET[i].dx;
	}
}


void edgetable::add2(vector<edge> &AET, int y,int dy)
{
	for (auto it : ET)
	{
		if (it.y1 <= y && it.y1 != it.y2&&it.y1>=(y-dy))
		{
			AET.push_back(it);
		}
	}
}
