#include "Mesh3d.h"

Mesh3d::Mesh3d(){

}

Mesh3d::~Mesh3d(){
	glDeleteProgram(shaderProgram);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
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

void Mesh3d::generateVAO_VBO_EBO()
{
	generateVAO();
	generateVBO();
	generateEBO();
}

void Mesh3d::generateVAO()
{
	glGenVertexArrays(1, &VAO);
}

void Mesh3d::generateVBO()
{
	glGenBuffers(1, &VBO);
}

void Mesh3d::generateEBO()
{
	glGenBuffers(1, &EBO);
}

GLuint Mesh3d::getVAO()
{
	return VAO;
}

GLuint Mesh3d::getVBO()
{
	return VBO;
}

GLuint Mesh3d::getEBO()
{
	return EBO;
}

void Mesh3d::setVertexNum(int num)
{
	num_of_vertex = num;
}

void Mesh3d::setDrawType(GLenum type)
{
	draw_mode = type;
}

void Mesh3d::render()
{
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawElements(draw_mode, num_of_vertex, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
