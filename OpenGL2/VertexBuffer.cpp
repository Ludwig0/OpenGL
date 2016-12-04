#include "VertexBuffer.h"
#include <stdio.h>
#include <iostream>
#include <SOIL\SOIL.h>

extern float *verts;
extern std::vector<VertexBuffer::AttribPointer> bufferAttribs;
extern GLuint bufferID;

VertexBuffer::VertexBuffer(float bufferValues[], int bufferSize, GLenum bufferType)
{
	verts = bufferValues;
	glGenBuffers(1, &bufferID);
	glBindBuffer(bufferType, bufferID);
	glBufferData(bufferType, sizeof(bufferValues) * bufferSize, verts, GL_STATIC_DRAW);
}

float* VertexBuffer::getVerts() {
	return verts;
}

void VertexBuffer::addAttribPointer(int location, int offset, int stride, int numOfElementsPerStride) {
	AttribPointer newPointer;
	newPointer.location = location;
	newPointer.offset = offset;
	newPointer.stride = stride;
	newPointer.size = numOfElementsPerStride;

	bufferAttribs.push_back(newPointer);
}

void VertexBuffer::setupAttribPointers() {
	for each (auto pointer in bufferAttribs)
	{
		glVertexAttribPointer(pointer.location, pointer.size, GL_FLOAT, GL_FALSE, pointer.stride * sizeof(GLfloat), (char*)(sizeof(GLfloat) * pointer.offset));
	}
}

void VertexBuffer::enableAttribPointers() {
	for each(auto pointer in bufferAttribs) {
		glEnableVertexAttribArray(pointer.location);
	}
}

void VertexBuffer::setTexture(const char* imagePath, int width, int height)
{
	unsigned char* image = SOIL_load_image(imagePath, &width, &height, 0, SOIL_LOAD_AUTO);
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	textures.push_back(texture);

	SOIL_free_image_data(image);
}

VertexBuffer::~VertexBuffer()
{
}
