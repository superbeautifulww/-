#pragma once

#ifndef SHADER_H
#define SHADER_H
#define GLEW_STATIC

#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
const char* vShaderCode = "#version 330 core                        \n"
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
const char * fShaderCode = "#version 330 core                              \n"
"out vec4 FragColor;                            \n"
"in vec3 ourColor;                              \n"
"in vec2 TexCoord;                              \n"
"uniform sampler2D ourTexture;                  \n"
"void main() {                                  \n"
"FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 0.5);\n"
"}                                              \n";
class Shader
{
public:
	unsigned int ID;
	// constructor generates the shader on the fly
	// ------------------------------------------------------------------------
	Shader()
	{
		
		// 2. Брвы
		unsigned int vertex, fragment;
		
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);
		
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);
		
		ID = glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);

		// delete the shaders as they're linked into our program now and no longer necessary
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}
	// activate the shader
	// ------------------------------------------------------------------------
	void use()
	{
		glUseProgram(ID);
	}
	// utility uniform functions
	// ------------------------------------------------------------------------
	
	
};
#endif
