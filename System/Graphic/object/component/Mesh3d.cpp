#include "Mesh3d.h"

Mesh3d::Mesh3d(){
	M_matrix = new SubComponentMMatrix;
	isUseTexture = false;
	affectedByLight = true;
}

Mesh3d::~Mesh3d(){
	glDeleteProgram(shaderProgram);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	delete M_matrix;
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

void Mesh3d::setTextureID(GLuint id)
{
	Texture_ID = id;
	isUseTexture = true;
}

GLuint Mesh3d::getTextureID()
{
	return Texture_ID;
}



void Mesh3d::render()
{
	glUseProgram(shaderProgram);
	///////////////////////////////////////////////////////////////////////////////
	/////////////////////////////// BIND CAMERA ///////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	glm::mat4x4 PVM = glm::mat4x4(1.0f);

	ComponentCamera* camera = ComponentCamera::getCurrentCamera();
	if (camera != nullptr) {
		//camera->bindValue(shaderProgram);
		PVM = PVM * camera->getPV();
	}
	bindModelMatrix(PVM);

	//////// TEXTURE /////////////
	if (isUseTexture) {
		glBindTexture(GL_TEXTURE_2D, Texture_ID);
	}
	

	//////////////////////////////


	glBindVertexArray(VAO);
	glDrawElements(draw_mode, num_of_vertex, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	if (isUseTexture) {
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	

}

SubComponentMMatrix * Mesh3d::getSubComponentModel()
{
	return M_matrix;
}

void Mesh3d::setUsingTextureState(bool state)
{
	isUseTexture = state;
}

void Mesh3d::setLightAffection(bool state)
{
	affectedByLight = state;
}

void Mesh3d::bindModelMatrix(glm::mat4x4 PV)
{
	if (M_matrix != nullptr) {

		PV = PV * M_matrix->getTranslateMatrix();
	}

	glUniformMatrix4fv(
		glGetUniformLocation(shaderProgram, IDENTIFICATION_SHADER_PVM),
		1,
		false,								// transpose
		glm::value_ptr(PV));				// ptr
}

void Mesh3d::bindModelMatrix()
{
	if (M_matrix != nullptr) {
		glm::mat4x4 ModelMatrix = M_matrix->getTranslateMatrix();
		glUniformMatrix4fv(
			glGetUniformLocation(shaderProgram, IDENTIFICATION_SHADER_TRANSLATE_MATRIX),
			1, 
			false,								// transpose
			glm::value_ptr(ModelMatrix));		// ptr
	}
}
