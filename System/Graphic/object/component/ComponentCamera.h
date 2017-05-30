#ifndef __COMPONENTCAMERA_H__
#define __COMPONENTCAMERA_H__

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glew.h>

#include "System\Graphic\GraphicDefinition.h"
#include "ComponentManager.h"

class ComponentCamera : public baseComponent {
public:
	ComponentCamera();
	~ComponentCamera();

	void lookat(
		glm::vec3 const & eye,
		glm::vec3 const & center,
		glm::vec3 const & up
	);

	void lookat_orbital(float R, float angle_Oxz, float angle_Oy);

	void perspective(float pfovy, float paspect, float pzNear, float pzFar);

	void init();
	void apply();

	void bindValue(GLuint shader_id);

	static void setCurrentCamera(ComponentCamera* camera);
	static ComponentCamera* getCurrentCamera();

	glm::mat4x4 getPV();

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
