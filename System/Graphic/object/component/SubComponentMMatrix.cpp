#include "SubComponentMMatrix.h"

SubComponentMMatrix::SubComponentMMatrix(){
	Model_matrix = glm::mat4x4(1.0f);

	translateVector = glm::vec3(0.0f, 0.0f, 0.0f);
	rotateVector = glm::vec3(0.0f, 0.0f, 0.0f);
	scaleVector = glm::vec3(0.0f, 0.0f, 0.0f);


	glm::mat4 ViewTranslate = glm::translate(glm::mat4(1.f), translateVector);

}

SubComponentMMatrix::~SubComponentMMatrix(){

}

glm::mat4x4 * SubComponentMMatrix::getModelMatrix()
{
	return &Model_matrix;
}

void SubComponentMMatrix::updateMMatrix()
{
	Model_matrix = glm::translate(glm::mat4(1.f), translateVector);
}

void SubComponentMMatrix::setTranslate(float x, float y, float z)
{
	translateVector = glm::vec3(x, y, z);
	updateMMatrix();
}

void SubComponentMMatrix::setTranslate(glm::vec3 trans)
{
	translateVector = trans;
	updateMMatrix();
}

void SubComponentMMatrix::translate(float x, float y, float z)
{
	translateVector += glm::vec3(x, y, z);
	updateMMatrix();
}

void SubComponentMMatrix::translate(glm::vec3 trans)
{
	translateVector += trans;
	updateMMatrix();
}

glm::mat4x4 SubComponentMMatrix::getTranslateMatrix()
{
	return glm::translate(glm::mat4(1.f), translateVector);
}
