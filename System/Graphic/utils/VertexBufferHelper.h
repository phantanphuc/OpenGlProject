#ifndef __VERTEXBUFFERHELPER_H__
#define __VERTEXBUFFERHELPER_H__

#include <stdarg.h> 
#include <memory.h>

#define MAX_SECTION_COUNT 5

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

	/*
	for setBuffer only, generateBuffer will automatically setSection
	*/
	void setSection_Arg(int n, ...);
	void setSection_Arr(int n, Section* arr);

	void setIndexBufferRef(int* reference, int size);
	void setVertexBufferRef(float* reference, int size);
	float* getVertexBuffer();
	int* getIndexBuffer();

	int getVertexBufferSize();
	int getIndexBufferSize();

	int getGetNumOfSection();
	int getStride();
	int getSectionSize(int sectionIndex);
	/////////////////////////////////////////////////////////////////
	////////////////// BUFFER MANIPULATION METHODS //////////////////
	/////////////////////////////////////////////////////////////////

	void setVertexPosition(float* src, int n);
	void setVertexColor(float* src, int n);
	void setVertexNorm(float* src, int n);
	void setVertexTexture(float* src, int n);

	void setVertexPosition(float x, float y, float z, int n);
	void setVertexColor(float x, float y, float z, int n);
	void setVertexNorm(float x, float y, float z, int n);
	void setVertexTexture(float x, float y, int n);

private:
	float* vertexBuffer;
	int* indexBuffer;

	bool using_dynamically_located_vertex_buffer = false;

	int offset_position;
	int offset_color;
	int offset_normal;
	int offset_texture;

	/*
	Stride: size of vertex in 4 byte (sizeof(float))
	*/
	int stride;

	int vertexBufferSize;
	int indexBufferSize;

	int sectionCount;
	
	Section sectionList[MAX_SECTION_COUNT];

};
#endif
