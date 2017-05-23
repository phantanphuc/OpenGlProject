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
	
}

void BaseScene::renderScene()
{
	objectManager->ExecuteObject();
}
