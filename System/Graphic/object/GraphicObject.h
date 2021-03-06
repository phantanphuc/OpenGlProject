#ifndef __GRAPHICOBJECT_H__
#define __GRAPHICOBJECT_H__

#include <glew.h>

#include "component\ComponentHeader.h"
#include <vector>
#include <type_traits>

#include "component\SubComponentMMatrix.h"

class GraphicObject {
public:
	GraphicObject();
	~GraphicObject();

	template <typename component_Type>
	component_Type* getComponent();
	
	template <typename component_Type>
	void addComponent(component_Type* component);

	template <typename component_Type>
	void addComponent();

	void Execute();

	SubComponentMMatrix* getSubComponentModel();

	void setTranslate(float x, float y, float z);
	void setTranslate(glm::vec3 trans);

	void translate(float x, float y, float z);
	void translate(glm::vec3 trans);

private:
	std::vector<baseComponent*> ComponentList;
	SubComponentMMatrix* M_matrix = nullptr;

	void updatePosition();

};


template<typename component_Type>
inline component_Type * GraphicObject::getComponent()
{
	ComponentType expected_type;

	if (std::is_same<component_Type, Mesh3d>::value) {
		expected_type = ComponentType::MESH3D;
	} else
	if (std::is_same<component_Type, ComponentCamera>::value) {
		expected_type = ComponentType::CAMERA;
	} else
	if (std::is_same<component_Type, ComponentLightSource>::value) {
		expected_type = ComponentType::LIGHT_SOURCE;
	}

	for (std::vector<baseComponent*>::iterator it = ComponentList.begin(); it != ComponentList.end(); ++it) {
		if ((*it)->getType() == expected_type) {

			return dynamic_cast<component_Type*>(*it);
		}
	}

	return nullptr;
}

template<typename component_Type>
inline void GraphicObject::addComponent(component_Type * component)
{
	((baseComponent*)(component))->setSubComponentModel(this->M_matrix);
	ComponentList.push_back(component);
}

template<typename component_Type>
inline void GraphicObject::addComponent()
{
	baseComponent* newnode;

	if (std::is_same<component_Type, Mesh3d>::value) {
		newnode = new Mesh3d();
	}
	if (std::is_same<component_Type, ComponentCamera>::value) {
		newnode = new ComponentCamera();
	}
	if (std::is_same<component_Type, ComponentLightSource>::value) {
		newnode = new ComponentLightSource();
	}
	newnode->setSubComponentModel(this->M_matrix);
	ComponentList.push_back(newnode);
}

#endif