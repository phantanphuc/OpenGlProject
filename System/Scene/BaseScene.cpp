#include "BaseScene.h"

BaseScene::BaseScene(){
	initScene();
}

BaseScene::~BaseScene(){
	delete objectManager;
}

void BaseScene::initScene()
{
	objectManager = new ObjectManager;
	GraphicObject* cameraObj = createCamera();
	objectManager->addNode(cameraObj);
}

void BaseScene::renderScene()
{
	
	objectManager->ExecuteObject();
}

GraphicObject * BaseScene::createCamera()
{
	GraphicObject* obj = new GraphicObject;

	obj->addComponent<ComponentCamera>();
	camera_ref = obj->getComponent<ComponentCamera>();

	camera_ref->init();
	camera_ref->lookat(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	camera_ref->perspective(1, 1, 0.1, 10);

	camera_ref->apply();

	return obj;
}

void BaseScene::setCameraRef(ComponentCamera * camera)
{
	camera_ref = camera;
}

void BaseScene::useDefaultCamera()
{
	ComponentCamera::setCurrentCamera(camera_ref);
}
