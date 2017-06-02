#ifndef __COMPONENTLIGHTSOURCE_H__
#define __COMPONENTLIGHTSOURCE_H__

#include "glm\glm.hpp"
#include "glew.h"

#include "System\Graphic\GraphicDefinition.h"
#include "ComponentManager.h"

#define MAX_POSIBLE_LIGHT 9

struct LightStructure {
	glm::vec4 position;
	glm::vec4 color;
	float ambientPow;
	float diffusePow;
	float spectularPow;
	bool enable;
};

class ComponentLightSource : public baseComponent {
public:
	ComponentLightSource();
	ComponentLightSource(int id);
	~ComponentLightSource();

	void setId(int id);
	int getId();

	void setLightDataRef(LightStructure* reference);
	void setEnableState(bool state);

	void setLightPos(float x, float y, float z);
	void setLightPos(glm::vec3 pos);

private:
	int light_id;

	LightStructure* light_data;
};

struct LightNode {
	ComponentLightSource* light_source;
	LightNode* nextnode = nullptr;
};

class LightManager {
public:
	LightManager();
	~LightManager();

	void addLightToList(ComponentLightSource* src);

	static void setCurrentLightSystem(LightManager* lightSys);
	static LightManager* getCurrentLightSystem();

	LightStructure* getLightSystemSlot(int slot);

	void apply();

	void bindLightUniformBuffer(GLuint shader_id);

private:
	void init();

	LightNode* light_list;

	LightStructure light_system[MAX_POSIBLE_LIGHT];

	GLuint lightSystemUniformBuffer;
};


#endif
