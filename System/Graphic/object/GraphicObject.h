#ifndef __GRAPHICOBJECT_H__
#define __GRAPHICOBJECT_H__

#include <glew.h>

#include "component\ComponentHeader.h"
#include <vector>
#include <type_traits>

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

private:
	std::vector<ComponentNode> ComponentList;
};


template<typename component_Type>
inline component_Type * GraphicObject::getComponent()
{
	ComponentType expected_type;

	if (std::is_same<component_Type, Mesh3d>::value) {
		expected_type = ComponentType::MESH3D;
	}

	for (std::vector<ComponentNode>::iterator it = ComponentList.begin(); it != ComponentList.end(); ++it) {
		if (it->type == expected_type) {
			return (component_Type*)(it->Component);
		}
	}

	return NULL;
}

template<typename component_Type>
inline void GraphicObject::addComponent(component_Type * component)
{
	ComponentNode newnode;

	if (std::is_same<component_Type, Mesh3d>::value) {
		newnode.type = ComponentType::MESH3D;
	}

	newnode.Component = (void*)component;
	ComponentList.push_back(newnode);
}

template<typename component_Type>
inline void GraphicObject::addComponent()
{
	ComponentNode newnode;

	if (std::is_same<component_Type, Mesh3d>::value) {
		newnode.type = ComponentType::MESH3D;
		newnode.Component = (void*) new Mesh3d();
	}

	ComponentList.push_back(newnode);
}

#endif