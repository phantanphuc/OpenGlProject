#include "MainWindow.h"

#include "scenes\TestScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	MainWindow::getInstance();

	///////////////////////////////////////////////////////
	//////////////// INIT /////////////////////////////////
	///////////////////////////////////////////////////////
	// Please set initial scene first

	TestScene* initScene = new TestScene;
	
	initScene->createScene();
	SceneManager::getInstance()->setCurrentScene(initScene);
	
	//
	////////////////////////////////////////////////////////


	MainWindow::getInstance()->run();
	return 0;
}