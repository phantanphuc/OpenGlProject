#include "ComponentManager.h"

ComponentManager::ComponentManager(){
	
}

ComponentManager::~ComponentManager(){

}

baseComponent::baseComponent()
{
	
}

baseComponent::~baseComponent()
{
}

ComponentType baseComponent::getType()
{
	return m_type;
}

SubComponentMMatrix * baseComponent::getSubComponentModel()
{
	return M_matrix_ref;
}

void baseComponent::setSubComponentModel(SubComponentMMatrix * model)
{
	M_matrix_ref = model;
}
