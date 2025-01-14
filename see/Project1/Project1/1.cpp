#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include<cmath>
using namespace std;
int main()
{
	// ��ʼ��GLFW
	glfwInit();

	// ����һ������
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Circle", nullptr, nullptr);
	if (window == nullptr)
	{
		// ���ڴ���ʧ��
		glfwTerminate();
		return -1;
	}

	// ���ô���������
	glfwMakeContextCurrent(window);
	// ��ʼ��GLEW
	if (glewInit() != GLEW_OK)
	{
		// GLEW��ʼ��ʧ��
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
	// ����������ɫ������
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);

	// ����Ƭ����ɫ������
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);

	// ������ɫ������
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// ɾ����ɫ������
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	// ����Բ�Ķ�����
	const int numSegments = 100;

	// ����Բ�İ뾶������λ��
	float radius = 0.5f;
	float centerX = 0.0f;
	float centerY = 0.0f;

	// ��������
	GLfloat vertices[numSegments * 2];

	// ����Բ�ϵĶ���λ��
	float theta = 2.0f * 3.1415926f / float(numSegments);
	float c = cos(theta); // Բ�İ뾶ͶӰ��X���ϵķ���
	float s = sin(theta); // Բ�İ뾶ͶӰ��Y���ϵķ���
	float x = radius; // Բ�ϵ�һ�������X����
	float y = 0.0f; // Բ�ϵ�һ�������Y����

	for (int i = 0; i < numSegments * 2; i += 2)
	{
		vertices[i] = x + centerX;
		vertices[i + 1] = y + centerY;

		// Ӧ����ת�任
		float t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	// �������㻺�����
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// ���������������
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
	glEnableVertexAttribArray(0);

	// ��󶥵��������Ͷ��㻺�����
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	while (!glfwWindowShouldClose(window))
	{
		// �����ɫ������
		glClear(GL_COLOR_BUFFER_BIT);

		// ʹ����ɫ������
		glUseProgram(shaderProgram);

		// �󶨶����������
		glBindVertexArray(VAO);

		// ����Բ
		glDrawArrays(GL_LINE_LOOP, 0, numSegments);

		// ��󶥵��������
		glBindVertexArray(0);

		// ����ǰ�󻺳���
		glfwSwapBuffers(window);

		// �����¼�
		glfwPollEvents();
	}
	// ɾ�����㻺�����Ͷ����������
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);

	// ɾ����ɫ������
	glDeleteProgram(shaderProgram);

	// ��ֹGLFW
	glfwTerminate();
}
