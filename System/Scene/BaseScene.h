#ifndef __BASESCENE_H__
#define __BASESCENE_H__

#include "System\Graphic\utils\ObjectHelper.h"
#include "System\InputManager.h"
#include "System\Graphic\TextureManager.h"
#include "System\Graphic\object\component\ComponentLightSource.h"

class BaseScene {
public:
	BaseScene();
	~BaseScene();

	void initScene();
	void renderScene();


	GraphicObject* createCamera();
	void setCameraRef(ComponentCamera* camera);
	void useDefaultCamera();

	void useThisSceneLight();

	void commenceScene();

	////////////////////////////////////////////////
	//////////////// AWAIT OVERRIDE ////////////////
	////////////////////////////////////////////////

	virtual void updateScene();
	virtual void createScene() = 0;
	virtual void listenKeyboard(keymap* Keymap);

protected:
	ComponentCamera* camera_ref;

	ObjectManager* objectManager;
	TextureManager* texture_manager;
	LightManager* lightManager;
	
	GLuint addTexture(char* path);
	void addChildObj(GraphicObject* obj);

};
#endif
