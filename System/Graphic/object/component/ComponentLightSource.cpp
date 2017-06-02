#include "ComponentLightSource.h"

LightManager* current_light_manager;

ComponentLightSource::ComponentLightSource(){
	m_type = ComponentType::LIGHT_SOURCE;
}

ComponentLightSource::ComponentLightSource(int id)
{
	light_id = id;
}

ComponentLightSource::~ComponentLightSource(){

}

void ComponentLightSource::setId(int id)
{
	light_id = id;
}

int ComponentLightSource::getId()
{
	return light_id;
}

void ComponentLightSource::setLightDataRef(LightStructure * reference)
{
	light_data = reference;
}

void ComponentLightSource::setEnableState(bool state)
{
	light_data->enable = state;
}

void ComponentLightSource::setLightPos(float x, float y, float z)
{
	light_data->position = glm::vec4(x, y, z, 1.0f);
}

void ComponentLightSource::setLightPos(glm::vec3 pos)
{
	light_data->position = glm::vec4(pos, 1.0f);
}

LightManager::LightManager()
{
	light_list = nullptr;
	init();
}

LightManager::~LightManager()
{
	while (light_list != nullptr) {
		LightNode* delnode = light_list;
		light_list = light_list->nextnode;
		delete delnode;
	}
}

void LightManager::addLightToList(ComponentLightSource * src)
{
	LightNode* newnode = new LightNode;
	newnode->light_source = src;
	
	if (light_list == nullptr) {
		light_list = newnode;
	}
	else {
		newnode->nextnode = light_list;
		light_list = newnode;
	}

}

void LightManager::setCurrentLightSystem(LightManager * lightSys)
{
	current_light_manager = lightSys;
}

LightManager* LightManager::getCurrentLightSystem()
{
	return current_light_manager;
}

LightStructure * LightManager::getLightSystemSlot(int slot)
{
	if (slot > MAX_POSIBLE_LIGHT) return nullptr;
	return &light_system[slot];
}

void LightManager::apply()
{
	glBindBufferBase(GL_UNIFORM_BUFFER, INDEX_LIGHTSYSTEM, lightSystemUniformBuffer);

	glBufferData(GL_UNIFORM_BUFFER, sizeof(light_system), light_system, GL_STATIC_DRAW);

	
}

void LightManager::bindLightUniformBuffer(GLuint shader_id)
{
	GLuint idx = glGetUniformBlockIndex(shader_id, "LightSystem");
	glUniformBlockBinding(shader_id, idx, INDEX_LIGHTSYSTEM);



}

void LightManager::init()
{
	memset(light_system, 0, sizeof(light_system));
	glGenBuffers(1, &lightSystemUniformBuffer);
}
