#include "ShaderProgram.h"
#include "Util.h"
#include <iostream>


ShaderProgram::ShaderProgram(const char* paths[])
{
	programID = glCreateProgram();

	//Vertex Shader Setup
	shaderIDs[VERTEX_SHADER] = glCreateShader(shaderTypes[VERTEX_SHADER]);
	string source = Util::readFile(paths[VERTEX_SHADER]);
	const char* vertSource = source.c_str();
	glShaderSource(shaderIDs[VERTEX_SHADER], 1, &vertSource, NULL);
	glCompileShader(shaderIDs[VERTEX_SHADER]);
	glAttachShader(programID, shaderIDs[VERTEX_SHADER]);
	
	shaderIDs[FRAGMENT_SHADER] = glCreateShader(shaderTypes[FRAGMENT_SHADER]);
	source = Util::readFile(paths[FRAGMENT_SHADER]);
	const char* fragSource = source.c_str();

	glShaderSource(shaderIDs[FRAGMENT_SHADER], 1, &fragSource, NULL);
	glCompileShader(shaderIDs[FRAGMENT_SHADER]);
	glAttachShader(programID, shaderIDs[FRAGMENT_SHADER]);

	glLinkProgram(programID);
}



void ShaderProgram::useProgram() {
	glUseProgram(programID);
}

ShaderProgram::~ShaderProgram() {
	glDeleteShader(shaderIDs[VERTEX_SHADER]);
	glDeleteShader(shaderIDs[FRAGMENT_SHADER]);
}