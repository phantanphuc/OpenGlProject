#include "ComponentCamera.h"
#include <glm/gtc/matrix_transform.hpp>

ComponentCamera* current_using_camera = nullptr;

ComponentCamera::ComponentCamera(){
	m_type = ComponentType::CAMERA;
}

ComponentCamera::~ComponentCamera(){

}

void ComponentCamera::lookat(glm::vec3 const & eye, glm::vec3 const & center, glm::vec3 const & up)
{
	
	camera_position = eye;
	camera_lookat = center;
	upVector = up;
}

void ComponentCamera::lookat_orbital(float R, float angle_Oxz, float angle_Oy)
{
	camera_lookat = glm::vec3(0.0f, 0.0f, 0.0f);


	camera_position = glm::vec3(
		R * cos(angle_Oxz) * sin(angle_Oy),
		R * cos(angle_Oy),
		R * sin(angle_Oxz) * sin(angle_Oy)
	);

	upVector = glm::vec3(0.0f, 1.0f, 0.0f);
}

void ComponentCamera::perspective(float pfovy, float paspect, float pzNear, float pzFar)
{
	fovy = pfovy;
	aspect = paspect;
	zNear = pzNear;
	zFar = pzFar;
}

void ComponentCamera::init()
{
	upVector = glm::vec3(0.0f, 1.0f, 0.0f);
}

void ComponentCamera::apply()
{
	V = glm::lookAt(camera_position, camera_lookat, upVector);
	P = glm::perspective(fovy, aspect, zNear, zFar);

}

void ComponentCamera::bindValue(GLuint shader_program_id)
{
	glUniformMatrix4fv(
		glGetUniformLocation(shader_program_id, IDENTIFICATION_SHADER_VIEW_MATRIX),
		1,
		false,								// transpose
		glm::value_ptr(V));		// ptr

	glUniformMatrix4fv(
		glGetUniformLocation(shader_program_id, IDENTIFICATION_SHADER_PROJECTION_MATRIX),
		1,
		false,								// transpose
		glm::value_ptr(P));		// ptr

}

void ComponentCamera::setCurrentCamera(ComponentCamera * camera)
{
	current_using_camera = camera;
}

ComponentCamera * ComponentCamera::getCurrentCamera()
{
	return current_using_camera;
}

glm::mat4x4 ComponentCamera::getPV()
{
	return P * V;
}
