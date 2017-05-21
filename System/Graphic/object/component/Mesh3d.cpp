#include "Mesh3d.h"

Mesh3d::Mesh3d(){

}

Mesh3d::~Mesh3d(){

}

void Mesh3d::setVertexShaderId(GLuint id)
{
	vertexShader = id;
}

void Mesh3d::setFragmentShaderId(GLuint id)
{
	fragmentShader = id;
}

void Mesh3d::setShaderProgramId(GLuint id)
{
	shaderProgram = id;
}

GLuint Mesh3d::getVertexShaderId()
{
	return vertexShader;
}

GLuint Mesh3d::getFragmentShaderId()
{
	return fragmentShader;
}

GLuint Mesh3d::getShaderProgramId()
{
	return shaderProgram;
}

void Mesh3d::generateVBO()
{
	glGenBuffers(1, &VBO);
}

void Mesh3d::generateEBO()
{
	glGenBuffers(1, &EBO);
}

GLuint Mesh3d::getVBO()
{
	return VBO;
}

GLuint Mesh3d::getEBO()
{
	return EBO;
}
