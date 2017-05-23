#include "VertexBufferHelper.h"

VertexBufferHelper::VertexBufferHelper(){
	offset_position = -1;
	offset_color = -1;
	offset_normal = -1;
	offset_texture = -1;

	for (int i = 0; i < MAX_SECTION_COUNT; ++i) {
		sectionList[i] = Section::NONE;
	}
}

VertexBufferHelper::~VertexBufferHelper(){
	if (using_dynamically_located_vertex_buffer) {
		delete[] vertexBuffer;
	}
}

void VertexBufferHelper::generateBuffer(int n, ...)
{
	int current_offset = 0;
	va_list vl;
	va_start(vl, n);

	int num_of_vertex = va_arg(vl, int);
	sectionCount = n - 1;

	for (int i = 0; i < n;i++)
	{
		Section val = va_arg(vl, Section);
		sectionList[i] = val;
		switch (val)
		{
		case POSITION:
			offset_position = current_offset;
			current_offset += 3;
			break;
		case COLOR:
			offset_color = current_offset;
			current_offset += 3;
			break;
		case NORMAL:
			offset_normal = current_offset;
			current_offset += 3;
			break;
		case TEXTURE:
			offset_texture = current_offset;
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
	using_dynamically_located_vertex_buffer = true;
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

void VertexBufferHelper::setSection_Arg(int n, ...)
{
	va_list vl;
	int current_offset = 0;
	va_start(vl, n);
	sectionCount = n;
	for (int i = 0; i < n;i++)
	{
		Section val = va_arg(vl, Section);
		sectionList[i] = val;
		switch (val)
		{
		case POSITION:
			offset_position = current_offset;
			current_offset += 3;
			break;
		case COLOR:
			offset_color = current_offset;
			current_offset += 3;
			break;
		case NORMAL:
			offset_normal = current_offset;
			current_offset += 3;
			break;
		case TEXTURE:
			offset_texture = current_offset;
			current_offset += 2;
			break;
		default:
			break;
		}
	}
	va_end(vl);
	stride = current_offset;
}

void VertexBufferHelper::setSection_Arr(int n, Section * arr)
{
	int current_offset = 0;
	sectionCount = n;
	for (int i = 0; i < n;i++)
	{
		Section val = arr[i];

		sectionList[i] = val;
		switch (val)
		{
		case POSITION:
			offset_position = current_offset;
			current_offset += 3;
			break;
		case COLOR:
			offset_color = current_offset;
			current_offset += 3;
			break;
		case NORMAL:
			offset_normal = current_offset;
			current_offset += 3;
			break;
		case TEXTURE:
			offset_texture = current_offset;
			current_offset += 2;
			break;
		default:
			break;
		}
	}
	stride = current_offset;
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

int VertexBufferHelper::getGetNumOfSection()
{
	return sectionCount;
}

int VertexBufferHelper::getStride()
{
	return stride;
}

int VertexBufferHelper::getSectionSize(int sectionIndex)
{
	if (sectionList[sectionIndex] == Section::TEXTURE) {
		return 2;
	}
	return 3;
}

