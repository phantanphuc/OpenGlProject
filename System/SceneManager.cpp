#include "SceneManager.h"

SceneManager* m_scenemanager_instance = nullptr;

SceneManager::SceneManager(){

}

SceneManager::~SceneManager(){

}

SceneManager * SceneManager::getInstance()
{
	if (m_scenemanager_instance == nullptr) {
		m_scenemanager_instance = new SceneManager;
	}
	return m_scenemanager_instance;
}

void SceneManager::setCurrentScene(BaseScene * current)
{
	current_scene = current;
}

void SceneManager::renderCurrentScene()
{
	current_scene->renderScene();
}

BaseScene * SceneManager::getCurrentScene()
{
	return current_scene;
}
