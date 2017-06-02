#ifndef __SUBCOMPONENTMMATRIX_H__
#define __SUBCOMPONENTMMATRIX_H__

#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class SubComponentMMatrix {
public:
	SubComponentMMatrix();
	~SubComponentMMatrix();

	glm::mat4x4* getModelMatrix();

	void updateMMatrix();

	void setTranslate(float x, float y, float z);
	void setTranslate(glm::vec3 trans);

	void translate(float x, float y, float z);
	void translate(glm::vec3 trans);

	glm::mat4x4 getTranslateMatrix();

	glm::vec3 getTranslateVector();

private:

	glm::mat4x4 Model_matrix;

	glm::vec3 translateVector;
	glm::vec3 rotateVector;
	glm::vec3 scaleVector;

};
#endif
