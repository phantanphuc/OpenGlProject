#include "GraphicObject.h"

GraphicObject::GraphicObject(){
	M_matrix = new SubComponentMMatrix;
}

GraphicObject::~GraphicObject(){
	for (std::vector<baseComponent*>::iterator it = ComponentList.begin(); it != ComponentList.end(); ++it) {
		switch ((*it)->getType())
		{
		case ComponentType::MESH3D: {
			Mesh3d* mesh3dref = dynamic_cast<Mesh3d*>(*it);
			delete mesh3dref;
			break;
		}

		case ComponentType::CAMERA: {
			ComponentCamera* camera = dynamic_cast<ComponentCamera*>(*it);
			delete camera;
			break;
		}

		case ComponentType::LIGHT_SOURCE: {
			ComponentLightSource* lightsource = dynamic_cast<ComponentLightSource*>(*it);
			delete lightsource;
			break;
		}

		default:
			break;
		}
	}
}

void GraphicObject::Execute()
{
	for (std::vector<baseComponent*>::iterator it = ComponentList.begin(); it != ComponentList.end(); ++it) {
		switch ((*it)->getType())
		{
		case ComponentType::MESH3D: {
			Mesh3d* mesh3dref = dynamic_cast<Mesh3d*>(*it);
			mesh3dref->render();
			break;
		}

		case ComponentType::CAMERA: {
			//ComponentCamera* camera = (ComponentCamera*)it->Component;
			//camera->render();
			break;
		}

		case ComponentType::LIGHT_SOURCE: {
			//ComponentCamera* camera = (ComponentCamera*)it->Component;
			//camera->render();
			break;
		}

		default:
			break;
		}
	}
}

SubComponentMMatrix * GraphicObject::getSubComponentModel()
{
	return M_matrix;
}

void GraphicObject::setTranslate(float x, float y, float z)
{
	M_matrix->setTranslate(x, y, z);
	updatePosition();
}

void GraphicObject::setTranslate(glm::vec3 trans)
{
	M_matrix->setTranslate(trans);
	updatePosition();
}

void GraphicObject::translate(float x, float y, float z)
{
	M_matrix->translate(x, y, z);
	updatePosition();
}

void GraphicObject::translate(glm::vec3 trans)
{
	M_matrix->translate(trans);
	updatePosition();
}

void GraphicObject::updatePosition()
{
	for (std::vector<baseComponent*>::iterator it = ComponentList.begin(); it != ComponentList.end(); ++it) {
		switch ((*it)->getType())
		{
		case ComponentType::LIGHT_SOURCE: {
			ComponentLightSource* lightsource = dynamic_cast<ComponentLightSource*>(*it);
			lightsource->setLightPos(M_matrix->getTranslateVector());
			break;
		}

		default:
			break;
		}
	}
}
