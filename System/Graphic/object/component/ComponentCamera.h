#ifndef __COMPONENTCAMERA_H__
#define __COMPONENTCAMERA_H__

#include <glm/glm.hpp>

class ComponentCamera {
public:
	ComponentCamera();
	~ComponentCamera();

	void lookat(
		glm::vec3 const & eye,
		glm::vec3 const & center,
		glm::vec3 const & up
	);

	void perspective(float pfovy, float paspect, float pzNear, float pzFar);

	void init();
	void apply();
private:

	glm::vec3 camera_position;
	glm::vec3 camera_lookat;
	glm::vec3 upVector;

	glm::mat4x4 V;
	glm::mat4x4 P;

	float fovy;
	float aspect;
	float zNear;
	float zFar;
};
#endif
