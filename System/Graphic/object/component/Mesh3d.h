#ifndef __MESH3D_H__
#define __MESH3D_H__

#include <glew.h>

#include "ComponentManager.h"

class Mesh3d {
public:
	Mesh3d();
	~Mesh3d();

	void setVertexShaderId(GLuint id);
	void setFragmentShaderId(GLuint id);
	void setShaderProgramId(GLuint id);

	GLuint getVertexShaderId();
	GLuint getFragmentShaderId();
	GLuint getShaderProgramId();

	void generateVBO();
	void generateEBO();

	GLuint getVBO();
	GLuint getEBO();

private:
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;

	GLuint VBO;
	GLuint EBO;

	GLfloat* vertices;
	GLuint * indices;
};
#endif
