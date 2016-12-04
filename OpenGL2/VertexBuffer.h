#ifndef VERTEX_BUFFER
#define VERTEX_BUFFER

#include <GL/glew.h>
#include <vector>

class VertexBuffer
{
public:
	static struct AttribPointer
	{
		int location;
		int offset;
		int stride;
		int size;
	};
	std::vector<AttribPointer> bufferAttribs;
	std::vector<GLuint> textures;

	VertexBuffer(float bufferValues[] , int bufferSize,  GLenum bufferType);
	void addAttribPointer(int location, int offset, int stride, int numOfElementsPerStride);
	void setupAttribPointers();
	void enableAttribPointers();
	void setTexture(const char* imagePath, int width, int height);
	float* getVerts();
	~VertexBuffer();
private:
	GLuint bufferID;
	float *verts;
};

#endif