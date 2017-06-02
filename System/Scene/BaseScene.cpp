#include "BaseScene.h"

BaseScene::BaseScene(){
	initScene();
}

BaseScene::~BaseScene(){
	delete objectManager;
	delete texture_manager;
	delete lightManager;
}

void BaseScene::initScene()
{
	objectManager = new ObjectManager;
	GraphicObject* cameraObj = createCamera();
	objectManager->addNode(cameraObj);

	texture_manager = new TextureManager;

	lightManager = new LightManager;

}

void BaseScene::renderScene()
{
	listenKeyboard((InputManager::getInstance())->getKeyMap());
	lightManager->apply();
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

void BaseScene::useThisSceneLight()
{
	LightManager::setCurrentLightSystem(lightManager);
}

void BaseScene::commenceScene()
{
	useDefaultCamera();
	useThisSceneLight();
}

void BaseScene::addChildObj(GraphicObject * obj)
{
	objectManager->addNode(obj);

	ComponentLightSource* lightsource = obj->getComponent<ComponentLightSource>();
	if (lightsource != nullptr) {
		lightsource->setLightDataRef(lightManager->getLightSystemSlot(lightsource->getId()));
	}
}

GLuint BaseScene::addTexture(char * path)
{
	return texture_manager->addTexture(path);
}
