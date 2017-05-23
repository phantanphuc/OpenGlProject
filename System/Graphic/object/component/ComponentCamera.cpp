#include "ComponentCamera.h"
#include <glm/gtc/matrix_transform.hpp>

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
