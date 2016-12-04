#ifndef SHADER_PROGRAM_HEADER
#define SHADER_PROGRAM_HEADER

#include <GL/glew.h>
#include <iostream>
#define NUM_OF_SHADERS 2
using namespace std;

class ShaderProgram {
public:
	const int VERTEX_SHADER = 0;
	const int FRAGMENT_SHADER = 1;
	GLenum shaderTypes[NUM_OF_SHADERS] = { GL_VERTEX_SHADER, GL_FRAGMENT_SHADER };
	GLuint shaderIDs[NUM_OF_SHADERS];
	/*
	param: {vertSource, fragSource, unknownSource}
	return: void
	*/
	ShaderProgram(const char* paths[]);
	void useProgram();
	~ShaderProgram();
private:
	GLuint programID;
};

#endif