#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include<cmath>
using namespace std;
int main()
{
	// 初始化GLFW
	glfwInit();

	// 创建一个窗口
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Circle", nullptr, nullptr);
	if (window == nullptr)
	{
		// 窗口创建失败
		glfwTerminate();
		return -1;
	}

	// 设置窗口上下文
	glfwMakeContextCurrent(window);
	// 初始化GLEW
	if (glewInit() != GLEW_OK)
	{
		// GLEW初始化失败
		return -1;
	}
	const char* vertexShaderSource = R"(
    #version 330 core

    layout (location = 0) in vec2 position;

    void main()
    {
        gl_Position = vec4(position, 0.0, 1.0);
    }
)";
	const char* fragmentShaderSource = R"(
    #version 330 core

    out vec4 color;

    void main()
    {
        color = vec4(1.0, 0.0, 0.0, 1.0);
    }
)";
	// 创建顶点着色器对象
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);

	// 创建片段着色器对象
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);

	// 创建着色器程序
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// 删除着色器对象
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	// 定义圆的顶点数
	const int numSegments = 100;

	// 定义圆的半径和中心位置
	float radius = 0.5f;
	float centerX = 0.0f;
	float centerY = 0.0f;

	// 顶点数据
	GLfloat vertices[numSegments * 2];

	// 计算圆上的顶点位置
	float theta = 2.0f * 3.1415926f / float(numSegments);
	float c = cos(theta); // 圆的半径投影到X轴上的分量
	float s = sin(theta); // 圆的半径投影到Y轴上的分量
	float x = radius; // 圆上第一个顶点的X坐标
	float y = 0.0f; // 圆上第一个顶点的Y坐标

	for (int i = 0; i < numSegments * 2; i += 2)
	{
		vertices[i] = x + centerX;
		vertices[i + 1] = y + centerY;

		// 应用旋转变换
		float t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	// 创建顶点缓冲对象
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// 创建顶点数组对象
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
	glEnableVertexAttribArray(0);

	// 解绑顶点数组对象和顶点缓冲对象
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	while (!glfwWindowShouldClose(window))
	{
		// 清空颜色缓冲区
		glClear(GL_COLOR_BUFFER_BIT);

		// 使用着色器程序
		glUseProgram(shaderProgram);

		// 绑定顶点数组对象
		glBindVertexArray(VAO);

		// 绘制圆
		glDrawArrays(GL_LINE_LOOP, 0, numSegments);

		// 解绑顶点数组对象
		glBindVertexArray(0);

		// 交换前后缓冲区
		glfwSwapBuffers(window);

		// 处理事件
		glfwPollEvents();
	}
	// 删除顶点缓冲对象和顶点数组对象
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);

	// 删除着色器程序
	glDeleteProgram(shaderProgram);

	// 终止GLFW
	glfwTerminate();
}
