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

		default:
			break;
		}
	}
}

SubComponentMMatrix * GraphicObject::getSubComponentModel()
{
	return M_matrix;
}
