#include "ComponentCamera.h"
#include <glm/gtc/matrix_transform.hpp>

ComponentCamera* current_using_camera = nullptr;

ComponentCamera::ComponentCamera(){

}

ComponentCamera::~ComponentCamera(){

}

void ComponentCamera::lookat(glm::vec3 const & eye, glm::vec3 const & center, glm::vec3 const & up)
{
	
	camera_position = eye;
	camera_lookat = center;
	upVector = up;
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
	glUniform1f(glGetUniformLocation(shader_program_id, "myvar"), -0.5f);
}

void ComponentCamera::setCurrentCamera(ComponentCamera * camera)
{
	current_using_camera = camera;
}

ComponentCamera * ComponentCamera::getCurrentCamera()
{
	return current_using_camera;
}
