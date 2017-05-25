#ifndef __BASESCENE_H__
#define __BASESCENE_H__

#include "System\Graphic\utils\ObjectHelper.h"

class BaseScene {
public:
	BaseScene();
	~BaseScene();

	void initScene();
	void renderScene();

	virtual void updateScene();

	virtual void createScene() = 0;

	GraphicObject* createCamera();
	void setCameraRef(ComponentCamera* camera);

	void useDefaultCamera();

protected:
	ComponentCamera* camera_ref;

	ObjectManager* objectManager;

	void addChildObj(GraphicObject* obj);
};
#endif
