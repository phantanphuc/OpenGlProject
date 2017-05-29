#include "BaseScene.h"

BaseScene::BaseScene(){
	initScene();
}

BaseScene::~BaseScene(){
	delete objectManager;
	delete texture_manager;
}

void BaseScene::initScene()
{
	objectManager = new ObjectManager;
	GraphicObject* cameraObj = createCamera();
	objectManager->addNode(cameraObj);

	texture_manager = new TextureManager;

}

void BaseScene::renderScene()
{
	listenKeyboard((InputManager::getInstance())->getKeyMap());
	updateScene();
	objectManager->ExecuteObject();
}

void BaseScene::updateScene(){}

void BaseScene::listenKeyboard(keymap * Keymap){}

GraphicObject * BaseScene::createCamera()
{
	GraphicObject* obj = new GraphicObject;

	obj->addComponent<ComponentCamera>();
	camera_ref = obj->getComponent<ComponentCamera>();

	camera_ref->init();
	camera_ref->lookat(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	camera_ref->perspective(glm::radians(45.0f), 640.0f/480.0f, 1, 2500);

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

void BaseScene::addChildObj(GraphicObject * obj)
{
	objectManager->addNode(obj);
}

GLuint BaseScene::addTexture(char * path)
{
	return texture_manager->addTexture(path);
}
