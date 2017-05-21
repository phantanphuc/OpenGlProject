#ifndef __VERTEXBUFFERHELPER_H__
#define __VERTEXBUFFERHELPER_H__

#include <stdarg.h> 
#include <memory.h>

enum Section {
	NONE, POSITION, COLOR, NORMAL, TEXTURE
};

class VertexBufferHelper {
public:
	VertexBufferHelper();
	~VertexBufferHelper();

	////////////////////////////////////////////////
	/// generateBuffet(n, numofvertext, Section 1, section 2, ...)
	////////////////////////////////////////////////
	void generateBuffer(int n, ...);

	

	void setIndexBufferRef(int* reference, int size);
	void setVertexBufferRef(float* reference, int size);
	float* getVertexBuffer();
	int* getIndexBuffer();

	int getVertexBufferSize();
	int getIndexBufferSize();

	/////////////////////////////////////////////////////////////////
	////////////////// BUFFER MANIPULATION METHODS //////////////////
	/////////////////////////////////////////////////////////////////

	void setVertexPosition(float* src, int n);
	void setVertexColor(float* src, int n);
	void setVertexNorm(float* src, int n);
	void setVertexTexture(float* src, int n);

private:
	float* vertexBuffer;
	int* indexBuffer;

	int offset_position;
	int offset_color;
	int offset_normal;
	int offset_texture;

	int stride;

	int vertexBufferSize;
	int indexBufferSize;
	
};
#endif
