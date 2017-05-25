#ifndef __TESTSCENE_H__
#define __TESTSCENE_H__

#include "System\Scene\BaseScene.h"

class TestScene : public BaseScene {
public:
	TestScene();
	~TestScene();

	void createScene();

	void addTestObject2(float testvalue);
	GraphicObject* testObj;
	float testFloat = 0;

	void updateScene();

	void listenKeyboard(keymap* Keymap);

private:
	
};
#endif
