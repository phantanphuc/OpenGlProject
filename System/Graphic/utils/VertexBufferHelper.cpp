#include "VertexBufferHelper.h"

VertexBufferHelper::VertexBufferHelper(){
	offset_position = -1;
	offset_color = -1;
	offset_normal = -1;
	offset_texture = -1;
}

VertexBufferHelper::~VertexBufferHelper(){

}

void VertexBufferHelper::generateBuffer(int n, ...)
{
	int current_offset = 0;
	va_list vl;
	va_start(vl, n);

	int num_of_vertex = va_arg(vl, int);

	for (int i = 0; i < n;i++)
	{
		Section val = va_arg(vl, Section);
		switch (val)
		{
		case POSITION:
			offset_position = current_offset;
			current_offset += 3;
			break;
		case COLOR:
			offset_position = current_offset;
			current_offset += 3;
			break;
		case NORMAL:
			offset_position = current_offset;
			current_offset += 3;
			break;
		case TEXTURE:
			offset_position = current_offset;
			current_offset += 2;
			break;
		default:
			break;
		}
	}
	va_end(vl);
	/////////////////////////////////////////////////////////
	////////////////////////// GENERATE /////////////////////
	/////////////////////////////////////////////////////////

	stride = current_offset;
	vertexBuffer = new float[num_of_vertex * current_offset];
	vertexBufferSize = num_of_vertex * current_offset * 4;
}

void VertexBufferHelper::setVertexPosition(float * src, int n)
{
	memcpy_s(
		vertexBuffer + offset_position + n * stride,
		12, 
		src,
		12);
}

void VertexBufferHelper::setVertexColor(float * src, int n)
{
	memcpy_s(
		vertexBuffer + offset_color + n * stride,
		12,
		src,
		12);
}

void VertexBufferHelper::setVertexNorm(float * src, int n)
{
	memcpy_s(
		vertexBuffer + offset_normal + n * stride,
		12,
		src,
		12);
}

void VertexBufferHelper::setVertexTexture(float * src, int n)
{
	memcpy_s(
		vertexBuffer + offset_texture + n * stride,
		8,
		src,
		8);
}

void VertexBufferHelper::setIndexBufferRef(int * reference, int size)
{
	indexBuffer = reference;
	indexBufferSize = size;
}

void VertexBufferHelper::setVertexBufferRef(float * reference, int size)
{
	vertexBuffer = reference;
	vertexBufferSize = size;
}

float * VertexBufferHelper::getVertexBuffer()
{
	return vertexBuffer;
}

int * VertexBufferHelper::getIndexBuffer()
{
	return indexBuffer;
}

int VertexBufferHelper::getVertexBufferSize()
{
	return vertexBufferSize;
}

int VertexBufferHelper::getIndexBufferSize()
{
	return indexBufferSize;
}

