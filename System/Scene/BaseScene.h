#ifndef __BASESCENE_H__
#define __BASESCENE_H__

#include "System\Graphic\utils\ObjectHelper.h"

class BaseScene {
public:
	BaseScene();
	~BaseScene();

	void initScene();
	void renderScene();

	virtual void createScene() = 0;

protected:
	ObjectManager* objectManager;
};
#endif
