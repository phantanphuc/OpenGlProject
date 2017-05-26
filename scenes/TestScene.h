#ifndef __TESTSCENE_H__
#define __TESTSCENE_H__

#include "System\Scene\BaseScene.h"

class TestScene : public BaseScene {
public:
	TestScene();
	~TestScene();

	void createScene();

	

	void updateScene();

	void listenKeyboard(keymap* Keymap);

private:
	
	void addTestObject2(float testvalue);
	GraphicObject* testObj;
	float testFloat = 0;

	float angle_Oxz = 45;
	float angle_Oy = 45;
	float R = 5;
};
#endif
