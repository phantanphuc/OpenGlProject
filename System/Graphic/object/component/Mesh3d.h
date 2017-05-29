#ifndef __MESH3D_H__
#define __MESH3D_H__

#include <glew.h>


#include "ComponentManager.h"
#include "ComponentCamera.h"
#include "SubComponentMMatrix.h"
#include "DeviL\IL\il.h"

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

	void generateVAO_VBO_EBO();
	void generateVAO();
	void generateVBO();
	void generateEBO();

	GLuint getVAO();
	GLuint getVBO();
	GLuint getEBO();

	void setVertexNum(int num);
	void setDrawType(GLenum type);

	void setTextureID(GLuint id);
	GLuint getTextureID();

	void render();

	SubComponentMMatrix* getSubComponentModel();

private:
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgram;

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

	GLuint Texture_ID;

	int num_of_vertex;
	GLenum draw_mode;

	SubComponentMMatrix* M_matrix = nullptr;

	void bindModelMatrix();

};
#endif
