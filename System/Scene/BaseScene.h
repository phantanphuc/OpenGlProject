#ifndef __BASESCENE_H__
#define __BASESCENE_H__

#include "System\Graphic\utils\ObjectHelper.h"
#include "System\InputManager.h"

class BaseScene {
public:
	BaseScene();
	~BaseScene();

	void initScene();
	void renderScene();


	GraphicObject* createCamera();
	void setCameraRef(ComponentCamera* camera);
	void useDefaultCamera();

	////////////////////////////////////////////////
	//////////////// AWAIT OVERRIDE ////////////////
	////////////////////////////////////////////////

	virtual void updateScene();

	virtual void createScene() = 0;

	virtual void listenKeyboard(keymap* Keymap);

protected:
	ComponentCamera* camera_ref;

	ObjectManager* objectManager;

	void addChildObj(GraphicObject* obj);
};
#endif
