#include "draw_3D.h"
#include<assert.h>
const float PI = 3.1415926;
float draw_3D::convertX(float x)
{
	return x;
}


float draw_3D::convertY(float y)
{
	return 800 - y;
}

//float draw_3D::rotationAngle = 0.0f;

void draw_3D::drawCircle(float centerX, float centerY, float radius, float R, float G, float B,vector<vector<float>> &matrix)
{
	
	int numSegments = 100; // 设置圆的细分程度

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(R, G , B); // 设置填充颜色为RGB(220, 243, 255)
	vector<float> t = { centerX, centerY,0,1 };

	vector<float> r = Matrix_mul(t, matrix);
	glVertex2f(r[0],r[1]); // 圆心点

	for (int i = 0; i <= numSegments; ++i)
	{
		float angle = 2.0f * 3.14159f * i / numSegments;
		float x = centerX + radius * cos(angle);
		float y = centerY + radius * sin(angle);
		//cout << x << " " << y << endl;
		t = { x,y,0,1 };
	
		r=Matrix_mul(t, matrix);
		glVertex2f(r[0],r[1]);
	
	}
	glEnd();
}

void draw_3D::drawMultipleShapes(vector<vector<float>> &matrix)
{
	vector<PFF> dot[4];
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
	GLfloat color[4][3] = { {188.0f / 255.0f, 223.0f / 255.0f, 121.0f / 255.0f},
		{122.0f / 255.0f,106.0f / 255.0f,91.0f / 255.0f},
		{169.0f / 255.0f,133.0f / 255.0f,104.0f / 255.0f},
	   {179.0f / 255.0f, 221.0f / 255.0f, 47.0f / 255.0f } };
	for (int i = 0; i < sizeof(dot) / sizeof(dot[0]); ++i)
	{
		glBegin(GL_POLYGON);
		glColor3f(color[i][0], color[i][1], color[i][2]); // 设置填充颜色

		for (int j = 0; j < dot[i].size(); ++j)
		{
			float X = convertX(dot[i][j].x*1.0);
			float Y = convertY(dot[i][j].y*1.0);
			vector<float> t = { X,Y,0,1 };

			vector<float> r = Matrix_mul(t, matrix);
			glVertex2f(r[0], r[1]);
		}
		glEnd();
	}
}

void draw_3D::init()
{
	//glClearDepth(1.0f);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // 设置背景色为白色
	//glEnable(GL_DEPTH_TEST); // 启用深度测试
	
}
void draw_3D::render()
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT); // 清除颜色缓冲区
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 800); // 设置正交投影矩阵
	//gluPerspective(45.0, 1.0, 0.1, 1000.0); // 设置透视投影矩阵

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//原始
	vector<vector<float>> normal =
	{
		{1, 0, 0,0},
		{0, 1, 0,0},
		{0, 0, 1,0},
		{0, 0, 0,1}
	};
	//绕x轴旋转
	float a = 45*3.1415926 / 180;
	vector<vector<float>>  romateMatrix_x = {
		{1, 0, 0,0},
		{0, cos(a), sin(a),0},
		{0, -sin(a), cos(a),0},
		{0, 0, 0,1}
	};
	//绕y轴旋转
	vector<vector<float>> romateMatrix_y = {
		{cos(a), 0, -sin(a),0},
		{0, 1, 0,0},
		{sin(a), 0, cos(a),0},
		{0, 0, 0,1}
	};
	//绕z轴旋转
	vector<vector<float>> romateMatrix_z = {
		{cos(a),-sin(a), 0, 0},
		{sin(a),  cos(a),0,0},
		{0,0, 1,0 },
		{0, 0, 0,1}
	};
	
	//平移
	float tx = 100, ty = 100, tz = 100;
	vector<vector<float>> move = {
		{1, 0, 0,tx},
		{0, 1, 0,ty},
		{0, 0, 1,tz},
		{0,0, 0,1}
	};
	//缩放
	float sx = 0.5, sy = 0.5, sz = 0.5;
	vector<vector<float>> scale = {
		{sx, 0, 0,0},
		{0, sy, 0,0},
		{0, 0, sz,0},
		{0, 0, 0,1}
	};
	vector<vector<float>> use = scale;
	drawCircle(402, 403, 377.5, 220.0 / 255.0, 243.0 / 255.0, 255.0 / 255.0,use);
	drawMultipleShapes(use); // 调用绘制多边形的函数
	drawCircle(403, 800-351, 29, 250.0 / 255.0, 177.0 / 255.0, 178.0 / 255.0,use);
	glFlush(); // 强制刷新缓冲区，将绘制结果显示到窗口上
	//glutSwapBuffers();
	glutPostRedisplay(); // 标记窗口需要重新绘制
}

void draw_3D::reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height); // 设置正交投影矩阵
	//gluPerspective(45.0, static_cast<double>(width) / height, 0.1, 100.0); // 设置透视投影矩阵

	glMatrixMode(GL_MODELVIEW); // 切换到模型视图矩阵模式
}

void draw_3D::start1(int argc, char** argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // 设置显示模式
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // 设置显示模式为双缓冲、RGB颜色和深度缓冲

	glutInitWindowSize(800, 800);
	
	glutCreateWindow("OpenGL Circle"); // 创建窗口并设置标题
	
	init(); // 调用初始化函数

	glutDisplayFunc(renderWrapper);
	glutReshapeFunc(reshapeWrapper);

	glutMainLoop();
}

vector<float> draw_3D::Matrix_mul(vector<float> &matrix1, vector<vector<float>> &matrix2)
{
	
	vector<float> a;
	// 进行矩阵乘法运算
	for (int i = 0; i < 4; i++) a.push_back(0);
	for(int i=0;i<4;i++)
		for (int j = 0; j < 4; j++)
		{
			a[i] += matrix2[i][j]*matrix1[j];
		}

	return a;
}

void draw_3D::drawCube()
{
	
	glBegin(GL_QUADS);

	for (const Face& face : facescolor)
	{
		glColor3f(face.color[0], face.color[1], face.color[2]);

		for (GLuint index : face.indices)
		{
			const Point& point = points[index];
			glVertex3f(point.x, point.y, point.z);
			//cout << point.x << " " << point.y << " " << point.z << endl;
		}
	}
	glEnd();
	
}
void draw_3D::renderScene()
{
	draw_3D D;
	static float rotate = 0;
	static int times = 0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 清理颜色缓冲和深度缓冲

	glMatrixMode(GL_MODELVIEW); // 对模型视景的操作
	glLoadIdentity(); // 重置当前指定的矩阵为单位矩阵
	glPushMatrix(); // 压栈
	
	times+=2;
	if (times > 100)
	{
		times = 0;
	}

	if (times % 100 == 0) // [0, 100)
	{
		rotate += 1; // [0, 20)
	}
	//绕x轴旋转
	float a = rotate * 3.1415926 / 180;
	vector<vector<float>>  romateMatrix_x = {
		{1, 0, 0,0},
		{0, cos(a), sin(a),0},
		{0, -sin(a), cos(a),0},
		{0, 0, 0,1}
	}; 
	vector<vector<float>> romateMatrix_y = {
		{cos(a), 0, -sin(a),0},
		{0, 1, 0,0},
		{sin(a), 0, cos(a),0},
		{0, 0, 0,1}
	};	vector<Point> result;
	for (int i = 0; i < 8; i++)
	{
		vector<float> temp,r;
		temp.push_back(D.points[i].x);
		temp.push_back(D.points[i].y);
		temp.push_back(D.points[i].z);
		temp.push_back(1);
		r = D.Matrix_mul(temp, romateMatrix_x);
		r = D.Matrix_mul(r, romateMatrix_y);
		result.push_back({r[0],r[1],r[2]});
	}
	for (int i = 0; i < 8;i++) D.points[i] = result[i];

	D.drawCube(); // 绘制立方体

	glPopMatrix();// 出栈
	glutSwapBuffers();
}
void draw_3D::start2(int argc, char** argv)
{
	glutInit(&argc, argv);  // 初始化GLUT
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);  // 显示窗口在屏幕的相对位置
	glutInitWindowSize(500, 500); // 设置显示窗口大小
	glutCreateWindow(argv[0]); // 创建窗口，附带标题

	glutDisplayFunc(&draw_3D::renderScene); // 注册显示用的函数
	glutIdleFunc(&draw_3D::renderScene); // 注册空闲用的函数

	glutMainLoop(); // GLUT 状态机
}
