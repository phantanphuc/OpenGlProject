#include "GraphicObject.h"

GraphicObject::GraphicObject(){

}

GraphicObject::~GraphicObject(){
	for (std::vector<ComponentNode>::iterator it = ComponentList.begin(); it != ComponentList.end(); ++it) {
		switch (it->type)
		{
		case ComponentType::MESH3D: {
			Mesh3d* mesh3dref = (Mesh3d*)it->Component;
			delete mesh3dref;
			break;
		}

		case ComponentType::CAMERA: {
			ComponentCamera* camera = (ComponentCamera*)it->Component;
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
	for (std::vector<ComponentNode>::iterator it = ComponentList.begin(); it != ComponentList.end(); ++it) {
		switch (it->type)
		{
		case ComponentType::MESH3D: {
			Mesh3d* mesh3dref = (Mesh3d*)it->Component;
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
