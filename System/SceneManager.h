#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

#include "Scene\BaseScene.h"

class SceneManager {
public:
	SceneManager();
	~SceneManager();
	
	static SceneManager* getInstance();

	void setCurrentScene(BaseScene* current);
	
	void renderCurrentScene();
	
	BaseScene* getCurrentScene();

private:
	BaseScene* current_scene;
};
#endif
