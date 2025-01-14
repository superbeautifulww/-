
#include <iostream>
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include<vector>
#include<string.h>



using namespace std;

double W =960;
double H = 960;
/*
const char* soctext1 =
"#version 330 core                        \n"
"layout (location = 0) in vec3 aPos;      \n"
"layout (location = 1) in vec2 aTexCoord;    \n"
"out vec2 TexCoord;                       \n"
"void main() {                            \n"
"    gl_Position = vec4(aPos, 1.0);       \n"
"    TexCoord = aTexCoord;                \n"
"}                                        \n";

const char* soctext2 =
"#version 330 core                              \n"
"out vec4 FragColor;                            \n"
"in vec2 TexCoord;                              \n"
"uniform sampler2D ourTexture;                  \n"
"void main() {                                  \n"
"FragColor = texture(texture, TexCoord);\n"
"}                                              \n";
const char* cube1 =
"#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"
"out vec3 TexCoords;\n"
"uniform mat4 projection;\n"
"uniform mat4 view;\n"
"void main()\n"
"{\n"
"TexCoords = aPos;\n"
"gl_Position = projection * view * vec4(aPos, 1.0);\n"
"}\n";
const char* cube2 =
"#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 TexCoords;\n"
"uniform samplerCube cubemap;\n"
"void main()\n"
"{\n"
"	FragColor = texture(cubemap, TexCoords);\n"
"}\n";
/*
unsigned int loadcubeTexture(vector<std::string> faces) 
{
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
	
	// 加载并生成纹理
	int width, height, nrChannels;
	for (unsigned int i = 0; i < faces.size(); i++)
	{
		unsigned char *data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
		
		if (data!=nullptr)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
				0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			std::cout << i  << std::endl;
			stbi_image_free(data);
		}
		else
		{
			std::cout << "Cubemap texture failed to load at path: " << i << std::endl;
			stbi_image_free(data);
		}
	}
	//设置纹理参数
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	
	return texture;
}
*/
/*
unsigned int loadTexture(string path)
{
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	//设置纹理参数
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	// 加载并生成纹理
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

	if (data != nullptr)
	{
		glTexImage2D(GL_TEXTURE_2D,
			0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		std::cout << "Texture failed to load at path: " << path << std::endl;
	}
	stbi_image_free(data);
	return texture;
}

void draw_cube(float x, float y, float z, float a, float b, float h, unsigned int textureid)
{
	// 计算缩放比例
	x = x / W * 2.0;
	y = y / W * 2.0;
	z = z / W * 2.0;
	a = a / W * 2.0;
	b = b / W * 2.0;
	h = h / W * 2.0;

	glBegin(GL_TRIANGLES);
	// 第一个三角形
	glTexCoord2d(0, 1);
	glVertex3f(x, y, z + b); // 左上
	glTexCoord2d(1, 1);
	glVertex3f(x + a, y, z + b); // 右上
	glTexCoord2d(0, 0);
	glVertex3f(x, y + h, z + b); // 左下

	// 第二个三角形
	glTexCoord2d(1, 1);
	glVertex3f(x + a, y, z + b); // 右上
	glTexCoord2d(1, 0);
	glVertex3f(x + a, y + h, z + b); // 右下
	glTexCoord2d(0, 0);
	glVertex3f(x, y + h, z + b); // 左下
	glEnd();
	
}
*/
/*
void draw_cube(float x, float y, float z, float a, float b, float h, vector<std::string> faces)
{
	// 计算缩放比例
	x = x / W * 2.0;
	y = y / W * 2.0;
	z = z / W * 2.0;
	a = a / W * 2.0;
	b = b / W * 2.0;
	h = h / W * 2.0;

	float vertices[] = {
		// 顶点坐标              // 纹理坐标
		// 右面
		x, y, z + b, 1.0f, 1.0f, // 顶部右
		x, y, z, 0.0f, 1.0f,      // 顶部左
		x, y + h, z, 0.0f, 0.0f,  // 底部左
		x, y + h, z + b, 1.0f, 0.0f, // 底部右

		// 左面
		x + a, y, z, 1.0f, 1.0f, // 顶部右
		x + a, y, z + b, 0.0f, 1.0f, // 顶部左
		x + a, y + h, z + b, 0.0f, 0.0f, // 底部左
		x + a, y + h, z, 1.0f, 0.0f, // 底部右

		// 顶面
		x, y, z, 0.0f, 0.0f,      // 左下
		x + a, y, z, 1.0f, 0.0f,  // 右下
		x + a, y, z + b, 1.0f, 1.0f, // 右上
		x, y, z + b, 0.0f, 1.0f,    // 左上

		// 底面
		x, y + h, z + b, 0.0f, 0.0f, // 左下
		x + a, y + h, z + b, 1.0f, 0.0f, // 右下
		x + a, y + h, z, 1.0f, 1.0f,  // 右上
		x, y + h, z, 0.0f, 1.0f,      // 左上

		// 后面
		x + a, y, z, 1.0f, 1.0f, // 右上
		x, y, z, 0.0f, 1.0f,     // 左上
		x, y + h, z, 0.0f, 0.0f, // 左下
		x + a, y + h, z, 1.0f, 0.0f, // 右下

		// 前面
		x, y, z + b, 0.0f, 1.0f, // 左上
		x + a, y, z + b, 1.0f, 1.0f, // 右上
		x + a, y + h, z + b, 1.0f, 0.0f, // 右下
		x, y + h, z + b, 0.0f, 0.0f // 左下
	};

	// 创建并绑定VAO
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// 创建并绑定VBO
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// 设置顶点属性指针
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// 加载纹理
	unsigned int texture = loadcubeTexture(faces);
	
	// 绘制立方体
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
	glDrawArrays(GL_QUADS, 0, 24); // 直接绘制所有顶点


	// 解绑VAO和VBO
	glBindVertexArray(0);

	// 释放资源
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
*/
/*
//绘制长方体
void draw_cube(float x,float y,float z, float a, float b, float h, vector<std::string> faces)
{

	//计算缩放比例
	x = x / W * 2.0;
	y = y / W * 2.0;
	z = z / W * 2.0;
	a = a / W * 2.0; 
	b = b / W * 2.0; 
	h = h / W * 2.0; 

	float vertices[] = {
		x,y,z,   
		x,y,z+b,  
		x+a,y,z+b, 
		x+a,y,z,
		x, y + h, z ,
		x , y + h, z + b,
		x+a , y + h, z + b,
		x + a, y + h, z,
	};

	unsigned int indices[] = {
		2,3,7,6,//右面
		0,1,5,4,//左面
		4,5,6,7, // 顶面
		0, 1, 2,3, // 底面
		0,4,7,3,//后面
		1,2,6,5//前面
	};

	// 创建并绑定VAO
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// 创建并绑定VBO
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// 创建并绑定EBO
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 设置顶点属性指针
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	

	// 加载纹理
	unsigned int texture = loadcubeTexture(faces);
	
	// 绘制立方体
	glBindVertexArray(VAO);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
	glDrawElements(GL_QUADS, sizeof(indices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	// 解绑VAO、VBO和EBO
	glBindVertexArray(0);

	// 释放资源
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

*/
/*
void draw_roof()
{
	double t = 2.0/ W;
	//左侧三角形
	glBegin(GL_POLYGON);
	glVertex3d(0,140*t,0);
	glVertex3d(0,140*t,135*t);
	glVertex3d(23*t,224*t,63*t);
	glEnd();
	
	//右侧三角形
	glBegin(GL_POLYGON);
	glVertex3d(253*t,224*t,63*t);
	glVertex3d(280*t,140*t,0);
	glVertex3d(280*t,140*t,135*t);
	glEnd();
	
	//前侧梯形
	glBegin(GL_POLYGON);
	glVertex3d(0,140*t,135*t);
	glVertex3d(280*t,140*t,135*t);
	glVertex3d(253*t,224*t,63*t);
	glVertex3d(23*t,224*t,63*t);
	glEnd();
	
	//后侧梯形
	glBegin(GL_POLYGON);
	glVertex3d(0,140*t,0);
	glVertex3d(23*t,224*t,63*t);
	glVertex3d(253*t,224*t,63*t);
	glVertex3d(280*t,140*t,63*t);
	glEnd();
	
}
void draw_doorhead()
{
	double t = 2.0 / W;
	//最外侧三角
	//前左
	glBegin(GL_POLYGON);
	glVertex3d(6*t, 78 * t, 186*t);
	glVertex3d(16 * t, 78 * t, 186 * t);
	glVertex3d(70 * t, 163 * t, 186 * t);
	glVertex3d(70 * t, 183 * t, 186 * t);
	glEnd();

	//前右
	glBegin(GL_POLYGON);
	glVertex3d(117 * t, 78 * t, 186 * t);
	glVertex3d(127 * t, 78 * t, 186 * t);
	glVertex3d(70 * t, 183 * t, 186 * t);
	glVertex3d(70 * t, 163 * t, 186 * t);
	glEnd();

	//左
	glBegin(GL_POLYGON);
	glVertex3d(6 * t, 78 * t, 186 * t);
	glVertex3d(6 * t, 78 * t, 100 * t);
	glVertex3d(70 * t, 183 * t, 100 * t);
	glVertex3d(70 * t, 183 * t, 186 * t);
	glEnd();

	//右
	glBegin(GL_POLYGON);
	glVertex3d(70 * t, 183 * t, 100 * t);
	glVertex3d(70 * t, 183 * t, 186 * t);
	glVertex3d(127 * t, 78 * t, 186 * t);
	glVertex3d(127 * t, 78 * t, 100 * t);
	glEnd();

	//左下
	glBegin(GL_POLYGON);
	glVertex3d(6 * t, 78 * t, 186 * t);
	glVertex3d(16 * t, 78 * t, 186 * t);
	glVertex3d(16 * t, 78 * t, 100 * t);
	glVertex3d(6 * t, 78 * t, 100 * t);
	glEnd();

	//右下
	glBegin(GL_POLYGON);
	glVertex3d(117 * t, 78 * t, 186 * t);
	glVertex3d(127 * t, 78 * t, 186 * t);
	glVertex3d(127 * t, 78 * t, 100 * t);
	glVertex3d(117 * t, 78 * t, 100 * t);
	glEnd();

	//左内
	glBegin(GL_POLYGON);
	glVertex3d(16 * t, 78 * t, 186 * t);
	glVertex3d(70 * t, 163 * t, 186 * t);
	glVertex3d(70 * t, 163 * t, 100 * t);
	glVertex3d(16 * t, 78 * t, 100 * t);
	glEnd();

	//右内
	glBegin(GL_POLYGON);
	glVertex3d(117 * t, 78 * t, 186 * t);
	glVertex3d(70 * t, 163 * t, 186 * t);
	glVertex3d(70 * t, 163 * t, 100 * t);
	glVertex3d(117 * t, 78 * t, 100 * t);
	glEnd();

	glColor3f(1.0f, 1.0f, 0.0f);
	//中间三角
	//前
	glBegin(GL_POLYGON);
	glVertex3d(28 * t, 98 * t, 186 * t);
	glVertex3d(106 * t, 98 * t, 186 * t);
	glVertex3d(70 * t, 163 * t, 186 * t);
	glEnd();
	
	//后
	glBegin(GL_POLYGON);
	glVertex3d(28 * t, 98 * t, 100 * t);
	glVertex3d(106 * t, 98 * t, 100 * t);
	glVertex3d(70 * t, 163 * t, 100 * t);
	glEnd();
	
	//左
	glBegin(GL_POLYGON);
	glVertex3d(28 * t, 98 * t, 186 * t);
	glVertex3d(70 * t, 163 * t, 186 * t);
	glVertex3d(70 * t, 163 * t, 100 * t);
	glVertex3d(28 * t, 98 * t, 100 * t);
	glEnd();

	//右
	glBegin(GL_POLYGON);
	glVertex3d(106 * t, 98 * t, 186 * t);
	glVertex3d(70 * t, 163 * t, 186 * t);
	glVertex3d(70 * t, 163 * t, 100 * t);
	glVertex3d(106 * t, 98 * t, 100 * t);
	glEnd();

	//下
	glBegin(GL_POLYGON);
	glVertex3d(28 * t, 98 * t, 186 * t);
	glVertex3d(106 * t, 98 * t, 186 * t);
	glVertex3d(117 * t, 98 * t, 100 * t);
	glVertex3d(16 * t, 98 * t, 100 * t);
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);

	//内部三角
	//前
	glBegin(GL_POLYGON);
	glVertex3d(55 * t, 119 * t, 186 * t);
	glVertex3d(81 * t, 119 * t, 186 * t);
	glVertex3d(70 * t, 144 * t, 186 * t);
	glEnd();
	
	//后
	glBegin(GL_POLYGON);
	glVertex3d(55 * t, 119 * t, 100 * t);
	glVertex3d(81 * t, 119 * t, 100 * t);
	glVertex3d(70 * t, 144 * t, 100 * t);
	glEnd();

	//左
	glBegin(GL_POLYGON);
	glVertex3d(55 * t, 119 * t, 186 * t);
	glVertex3d(70 * t, 144 * t, 186 * t);
	glVertex3d(70 * t, 144 * t, 100 * t);
	glVertex3d(55 * t, 119 * t, 100 * t);
	glEnd();

	//右
	glBegin(GL_POLYGON);
	glVertex3d(81 * t, 119 * t, 186 * t);
	glVertex3d(70 * t, 144 * t, 186 * t);
	glVertex3d(70 * t, 144 * t, 100 * t);
	glVertex3d(81 * t, 119 * t, 100 * t);
	glEnd();

	//下
	glBegin(GL_POLYGON);
	glVertex3d(81 * t, 119 * t, 186 * t);
	glVertex3d(55 * t, 119 * t, 186 * t);
	glVertex3d(55 * t, 119 * t, 100 * t);
	glVertex3d(81 * t, 119 * t, 100 * t);
	glEnd();
	
}



int main() {
	// 初始化 GLFW
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	// 创建窗口对象
	GLFWwindow* window = glfwCreateWindow(800, 600, "Cube Example", nullptr, nullptr);
	if (window == nullptr) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);


	// 初始化 GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW" << std::endl;
		return -1;
	}


	// 设置视口大小
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	
	float x = -20/W*2.0, y = -18 / W * 2.0, z = -12 / W * 2.0, a = 317 / W * 2.0, b = 130 / W * 2.0, h = 18 / W * 2.0;
	float vertices[] = {
		// positions          // colors           // texture coords
		 x + a, y, z,        1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right front
		 x + a, y, z + b,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right front
		 x, y, z + b,        0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left front
		 x, y, z,            1.0f, 1.0f, 0.0f,   0.0f, 1.0f, // top left front

		 x + a, y + h, z,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right back
		 x + a, y + h, z + b,0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right back
		 x, y + h, z + b,    0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left back
		 x, y + h, z,        1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left back
	};

	unsigned int indices[] = {
		// front face
		0, 1, 2,
		2, 3, 0,
		// right face
		0, 4, 5,
		5, 1, 0,
		// back face
		4, 7, 6,
		6, 5, 4,
		// left face
		7, 3, 2,
		2, 6, 7,
		// top face
		0, 3, 7,
		7, 4, 0,
		// bottom face
		1, 5, 6,
		6, 2, 1
	};

	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	// 加载和编译着色器
	unsigned int vertexcubeShader;
	vertexcubeShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexcubeShader, 1, &soctext1, NULL);
	glCompileShader(vertexcubeShader);

	unsigned int fragmentcubeShader;
	fragmentcubeShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentcubeShader, 1, &soctext2, NULL);
	glCompileShader(fragmentcubeShader);

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexcubeShader);
	glAttachShader(shaderProgram, fragmentcubeShader);
	glLinkProgram(shaderProgram);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	
	
	unsigned int house_down = loadTexture("C:/Users/21161/Desktop/IMG_5825(20240423-075537).JPG");

	// 渲染循环
	while (!glfwWindowShouldClose(window)) {
		// 清空颜色缓冲区和深度缓冲区
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT );
		
		glBindTexture(GL_TEXTURE_2D, house_down);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

		glUseProgram(shaderProgram);
		glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
		*/
		// 绘制立方体
		//draw_cube(-20, -18, -12, 317, 130, 18,house_down);//底座
		/*
		draw_cube(0, 0, 0, 280, 120, 140);//房子
		glColor3f(1.0f, 1.0f, 0.0f);
		draw_cube(2, -17, 130, 127, 80, 27);//门底座
		glColor3f(1.0f, 1.0f, 1.0f);
		draw_cube(-10,130,-9,297,130,10);//房檐
		glColor3f(1.0f, 1.0f, 0.0f);
		//draw_roof();//房顶
		draw_cube(153, 40, 140, 65, 5, 60);//窗
		
		glColor3f(0.0f, 1.0f, 1.0f);
		draw_cube(148, 34, 140, 77, 5, 5);//窗底座
		draw_cube(188, 239, 17, 40, 43, 9);//烟囱顶
		glColor3f(1.0f, 1.0f, 1.0f);
		draw_cube(196, 182, 27, 26, 36, 57);//烟囱
		glColor3f(0.0f, 0.0f, 1.0f);
		//draw_doorhead();
		glColor3f(1.0f, 1.0f, 1.0f);
		draw_cube(22, 7, 120, 90, 3, 91);//门最底层
		glColor3f(0.0f, 0.0f, 1.0f);
		draw_cube(45, 7, 120, 46, 3, 84);//门板
		draw_cube(95, 7, 163, 16, 16, 91);//右门柱
		draw_cube(22, 7, 163, 16, 16, 91);//左门柱
		glColor3f(1.0f, 1.0f, 1.0f);
		*/
		/*
		// 交换缓冲区
		glfwSwapBuffers(window);

		// 检查是否有事件触发，并更新窗口状态
		glfwPollEvents();

	}
	
	// 释放 GLFW 资源
	glfwTerminate();
	return 0;
	
}
*/



/*
float vertices[] = {
	//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
};
unsigned int indices[] = {
	0,1,3,
	1,2,3
};
*/

const char* soctext1 =
"#version 330 core                        \n"
"layout (location = 0) in vec3 aPos;      \n"
"layout (location = 1) in vec3 aColor;    \n"
"layout (location = 2) in vec2 aTexCoord; \n"
"out vec3 ourColor;                       \n"
"out vec2 TexCoord;                       \n"
"void main() {                            \n"
"    gl_Position = vec4(aPos, 1.0);       \n"
"    ourColor = aColor;                   \n"
"    TexCoord = aTexCoord;                \n"
"}                                        \n";

const char* soctext2 =
"#version 330 core                              \n"
"out vec4 FragColor;                            \n"
"in vec3 ourColor;                              \n"
"in vec2 TexCoord;                              \n"
"uniform sampler2D ourTexture;                  \n"
"void main() {                                  \n"
"FragColor = texture(ourTexture, TexCoord);\n"
"}                                              \n";

//屋顶
void draw_roof()
{
	float t = 2.0 / W;
	
	float vertices[] = {
		// positions          // colors           // texture coords
		 0,      140 * t, 0,          0.0f, 0.0f, 0.0f,   0.0f, 0.0f, // 左下角 
		 0,      140 * t, 135 * t,    0.0f, 0.0f, 0.0f,   1.0f, 0.0f, // 右下角
		 23 * t, 224 * t, 63 * t,     0.0f, 0.0f, 0.0f,   0.5f, 1.0f ,// 上中
		
		 253 * t, 224 * t, 63 * t, 0.0f, 0.0f, 0.0f,   0.5f, 1.0f ,// 上中
		 280 * t, 140 * t, 0,      0.0f, 0.0f, 0.0f,   1.0f, 0.0f,  // 左下角 
		 280 * t, 140 * t,135 * t, 0.0f, 0.0f, 0.0f,  1.0f, 0.0f, // 右下角
	};
	
	unsigned int indices[] = {
		// 左侧三角形
		0,1,2,
		//右侧三角形
		3,4,5,
		//前侧梯形
		1,2,3,
		3,5,1,
		//后侧梯形
		0,2,3,
		3,4,0
	};
	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	// 绘制立方体
	glDrawElements(GL_TRIANGLES,18, GL_UNSIGNED_INT, 0);
	// 解绑顶点数组对象
	glBindVertexArray(0);
	// 删除顶点数组对象和缓冲区对象
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

}
//最外侧三角
void draw_doorhead1()
{
	float t = 2.0 / W;
	float vertices[] = {
		6 * t, 78 * t, 186 * t,   0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   //0
		16 * t, 78 * t, 186 * t,   0.0f, 0.0f, 0.0f,   1.0f, 0.0f,   //1
		70 * t, 163 * t, 186 * t,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f,  //2
		70 * t, 183 * t, 186 * t,   0.0f, 0.0f, 0.0f,   0.0f, 1.0f ,//3

		117 * t, 78 * t, 186 * t,0.0f, 0.0f, 0.0f,   1.0f, 1.0f,//4
		127 * t, 78 * t, 186 * t,0.0f, 0.0f, 0.0f,   1.0f, 1.0f,//5
		
		6 * t, 78 * t, 186 * t,0.0f, 0.0f, 0.0f,   1.0f, 1.0f,//6
		6 * t, 78 * t, 100 * t,0.0f, 0.0f, 0.0f,   1.0f, 1.0f,//7
		70 * t, 183 * t, 100 * t,0.0f, 0.0f, 0.0f,   1.0f, 1.0f,//8
		70 * t, 183 * t, 186 * t,0.0f, 0.0f, 0.0f,   1.0f, 1.0f,//9

		127 * t, 78 * t, 100 * t,0.0f, 0.0f, 0.0f,1.0f, 1.0f,//10
		16 * t, 78 * t, 100 * t,0.0f, 0.0f, 0.0f,1.0f, 1.0f,//11
		117 * t, 78 * t, 100 * t,0.0f, 0.0f, 0.0f,1.0f, 1.0f,//12
		70 * t, 163 * t, 100 * t,0.0f, 0.0f, 0.0f,1.0f, 1.0f,//13
	};
	unsigned int indices[] = {
		//前左
		0,1,2,
		2,3,0,
		//前右
		4,5,3,
		3,2,4,
		//左
		6,7,8,
		8,9,6,
		//右
		8,9,5,
		5,10,8,
		//左下
		0,1,11,
		11,7,0,
		//右下
		4,5,10,
		10,12,4,
		//左内
		1,2,13,
		13,11,1,
		//右内
		4,2,13,
		13,12,4
	};
	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	// 绘制立方体
	glDrawElements(GL_TRIANGLES, 48, GL_UNSIGNED_INT, 0);
	// 解绑顶点数组对象
	glBindVertexArray(0);
	// 删除顶点数组对象和缓冲区对象
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}
//中间三角
void draw_doorhead2()
{
	float t = 2.0 / W;
	
	float vertices[] = {
		28 * t, 98 * t, 186 * t,   0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   //0
		106 * t, 98 * t, 186 * t,   0.0f, 0.0f, 0.0f,   1.0f, 0.0f,   //1
		70 * t, 163 * t, 186 * t,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f,  //2
		28 * t, 98 * t, 100 * t,   0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   //3
		106 * t, 98 * t, 100 * t,   0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   //4
		70 * t, 163 * t, 100 * t,   0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   //5
		117 * t, 98 * t, 100 * t,   0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   //6
		16 * t, 98 * t, 100 * t,   0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   //7
	};
	unsigned int indices[] = {
		//前
		0,1,2,
		//后
		3,4,5,
		//左
		0,2,5,
		5,3,0,
		//右
		1,2,5,
		5,4,1,
		//下
		0,1,6,
		6,7,0
	};
	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	// 绘制立方体
	glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
	// 解绑顶点数组对象
	glBindVertexArray(0);
	// 删除顶点数组对象和缓冲区对象
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}
//内部三角
void draw_doorhead3()
{
	float t = 2.0 / W;
	float vertices[] = {
		55 * t, 119 * t, 186 * t,   0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   //0
		81 * t, 119 * t, 186 * t,   0.0f, 0.0f, 0.0f,   1.0f, 0.0f,   //1
		70 * t, 144 * t, 186 * t,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f,  //2

		55 * t, 119 * t, 100 * t,   0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   //3
		81 * t, 119 * t, 100 * t,   0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   //4
		70 * t, 144 * t, 100 * t,   0.0f, 0.0f, 0.0f,   1.0f, 1.0f,   //5
	};
	unsigned int indices[] = {
		//前
		0,1,2,
		//后
		3,4,5,
		//左
		0,2,5,
		5,3,0,
		//右
		1,2,5,
		5,4,1,
		//下
		1,0,3,
		3,4,1
	};
	/*
	//前
	glBegin(GL_POLYGON);
	glVertex3d(55 * t, 119 * t, 186 * t);
	glVertex3d(81 * t, 119 * t, 186 * t);
	glVertex3d(70 * t, 144 * t, 186 * t);
	glEnd();
	
	//后
	glBegin(GL_POLYGON);
	glVertex3d(55 * t, 119 * t, 100 * t);
	glVertex3d(81 * t, 119 * t, 100 * t);
	glVertex3d(70 * t, 144 * t, 100 * t);
	glEnd();
	
	//左
	glBegin(GL_POLYGON);
	glVertex3d(55 * t, 119 * t, 186 * t);
	glVertex3d(70 * t, 144 * t, 186 * t);
	glVertex3d(70 * t, 144 * t, 100 * t);
	glVertex3d(55 * t, 119 * t, 100 * t);
	glEnd();
	
	//右
	glBegin(GL_POLYGON);
	glVertex3d(81 * t, 119 * t, 186 * t);
	glVertex3d(70 * t, 144 * t, 186 * t);
	glVertex3d(70 * t, 144 * t, 100 * t);
	glVertex3d(81 * t, 119 * t, 100 * t);
	glEnd();
	
	//下
	glBegin(GL_POLYGON);
	glVertex3d(81 * t, 119 * t, 186 * t);
	glVertex3d(55 * t, 119 * t, 186 * t);
	glVertex3d(55 * t, 119 * t, 100 * t);
	glVertex3d(81 * t, 119 * t, 100 * t);
	glEnd();
	*/
	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	// 绘制立方体
	glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
	// 解绑顶点数组对象
	glBindVertexArray(0);
	// 删除顶点数组对象和缓冲区对象
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}
void draw_cube(float x, float y, float z, float a, float b, float h)
{
	float t = 2.0 / W;
	x *=t, y *= t, z *= t, a  *= t, b  *= t, h *= t;

	float vertices[] = {
		 x + a, y, z,        0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 
		 x + a, y, z + b,    0.0f, 0.0f, 0.0f,   1.0f, 0.0f, 
		 x, y, z + b,        0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 
		 x, y, z,            0.0f, 0.0f, 0.0f,   0.0f, 1.0f, 

		 x + a, y + h, z,    0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 
		 x + a, y + h, z + b,0.0f, 0.0f, 0.0f,   1.0f, 0.0f, 
		 x, y + h, z + b,    0.0f, 0.0f, 0.0f,   0.0f, 0.0f, 
		 x, y + h, z,        0.0f, 0.0f, 0.0f,   0.0f, 1.0f  
	};

	unsigned int indices[] = {
		// 前
		1,5,6,
		6,2,1,
		// 右
		2,6,7,
		7,3,2,
		// 后
		4, 7, 3,
		3, 0, 4,
		// 左
		4,5,1,
		1,0,4,
		// 上
		4,5,6,
		6,7,4,
		// 下
		0, 1, 2,
		2, 3, 0
	};
	unsigned int VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	// 绘制立方体
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	// 解绑顶点数组对象
	glBindVertexArray(0);
	// 删除顶点数组对象和缓冲区对象
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

}
unsigned int loadTexture(string path)
{
	unsigned int textureid;
	glGenTextures(1, &textureid);
	glBindTexture(GL_TEXTURE_2D, textureid);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
	return textureid;
}

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "TextWindow", 0, 0);

	if (window == NULL) {
		printf("Err Create Window");
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	glewExperimental = true;

	if (glewInit() != GLEW_OK)
	{
		printf("30:Error");
		glfwTerminate();
		return -1;
	}

	glViewport(0, 0, 800, 600);

	//绑定纹理
	unsigned int house_down=loadTexture("D:/3dgis/ex1/ex1/code_tie/house_down.JPG");
	unsigned int house = loadTexture("D:/3dgis/ex1/ex1/code_tie/house.JPG");
	unsigned int door_down = loadTexture("D:/3dgis/ex1/ex1/code_tie/door_down.JPG");
	unsigned int house_head=loadTexture("D:/3dgis/ex1/ex1/code_tie/house_head.JPG");
	unsigned int house_window = loadTexture("D:/3dgis/ex1/ex1/code_tie/window.JPG");
	unsigned int window_down= loadTexture("D:/3dgis/ex1/ex1/code_tie/window_down.JPG");
	unsigned int chimney_head= loadTexture("D:/3dgis/ex1/ex1/code_tie/chimney_head.JPG");
	unsigned int chimney = loadTexture("D:/3dgis/ex1/ex1/code_tie/chimney.JPG");
	unsigned int door_back=loadTexture("D:/3dgis/ex1/ex1/code_tie/door_back.JPG");
	unsigned int door= loadTexture("D:/3dgis/ex1/ex1/code_tie/door.JPG");
	unsigned int column = loadTexture("D:/3dgis/ex1/ex1/code_tie/column.JPG");
	unsigned int head= loadTexture("D:/3dgis/ex1/ex1/code_tie/head.JPG");
	unsigned int head_mid = loadTexture("D:/3dgis/ex1/ex1/code_tie/head_mid.JPG");
	unsigned int intextureID = loadTexture("D:/3dgis/ex1/ex1/code_tie/in.JPG");

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &soctext1, NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &soctext2, NULL);
	glCompileShader(fragmentShader);

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	//float angle = 0;
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glUseProgram(shaderProgram);

		glBindTexture(GL_TEXTURE_2D, head_mid);
		draw_cube(-20, -18, -12, 317, 130, 18);
		glBindTexture(GL_TEXTURE_2D, house);
		draw_cube(0, 0, 0, 280, 120, 140);//房子
		glBindTexture(GL_TEXTURE_2D, head);
		draw_roof();//房顶
		glBindTexture(GL_TEXTURE_2D, head_mid);
		draw_cube(2, -17, 130, 127, 80, 27);//门底座
		glBindTexture(GL_TEXTURE_2D, head_mid);
		draw_cube(-10,130,-9,297,130,10);//房檐
		glBindTexture(GL_TEXTURE_2D, house_window);
		draw_cube(153, 40, 140, 65, 5, 60);//窗
		glBindTexture(GL_TEXTURE_2D, head_mid);
		draw_cube(148, 34, 140, 77, 5, 5);//窗底座
		draw_cube(188, 239, 17, 40, 43, 9);//烟囱顶
		draw_cube(196, 182, 27, 26, 36, 57);//烟囱
		glBindTexture(GL_TEXTURE_2D,  door_back);
		draw_cube(22, 7, 120, 90, 3, 91);//门最底层
		glBindTexture(GL_TEXTURE_2D, door);
		draw_cube(45, 7, 120, 46, 3, 84);//门板
		glBindTexture(GL_TEXTURE_2D, head_mid);
		draw_cube(95, 7, 163, 16, 16, 91);//右门柱
		draw_cube(22, 7, 163, 16, 16, 91);//左门柱
		glBindTexture(GL_TEXTURE_2D, head_mid);
		draw_doorhead1();
		draw_doorhead2();
		glBindTexture(GL_TEXTURE_2D, intextureID);
		draw_doorhead3();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}


