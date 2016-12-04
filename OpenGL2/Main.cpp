#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "ShaderProgram.h"
#include "VertexBuffer.h"
#include "Util.h"
using namespace std;

GLFWwindow* m_Window;

/*
/ Author: Brett L
/ Param: Width of window, Height of window, Title of window
/ Returns: void
/ Inits this programs shaders, buffers, and window
*/
void init(int width, int height, char* title)
{
	//Init GLFW and GLEW
	glfwInit();
	m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(m_Window);
	glewInit();

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	const char* shaderSources[] = { "triangle.vert", "triangle.frag"};
	ShaderProgram program = shaderSources;
	GLfloat data[] = {
		//left triangle
		-1.0f, -1.0f, 0.0f, 1.0f ,0.0f ,0.0f, 0.0f, 0.0f,// Left  
  		1.0f, -1.0f, 0.0f, 0.0f ,1.0f ,0.0f, 1.0f, 0.0f,// Right 
		-1.0f, 1.0f, 0.0f, 0.0f ,0.0f ,1.0f, 0.0f, 1.0f,// Left  

		//right triangl
		-1.0f, 1.0f, 0.0f, 0.0f ,0.0f ,1.0f, 0.0f, 1.0f,// Left  
		1.0f, 1.0f, 0.0f, 1.0f ,0.0f ,1.0f, 1.0f, 1.0f,// Left  
  		1.0f, -1.0f, 0.0f, 0.0f ,1.0f ,0.0f, 1.0f, 0.0f,// Right 
	};

	VertexBuffer buffer(data , 48, GL_ARRAY_BUFFER);
	buffer.addAttribPointer(0, 0, 8 ,3);
	buffer.addAttribPointer(1, 3, 8 ,3);
	buffer.addAttribPointer(2, 6, 8, 2);
	buffer.setupAttribPointers();
	buffer.enableAttribPointers();
	buffer.setTexture("wall.jpg", 512, 512);
	program.useProgram();

	while(!glfwWindowShouldClose(m_Window))
	{
		glfwPollEvents();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 6);
		glfwSwapBuffers(m_Window);
	}
}

int main() 
{
	init(640, 480, "Open GL");
	glfwTerminate();
	return 0;
}