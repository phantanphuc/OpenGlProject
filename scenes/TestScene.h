#ifndef __TESTSCENE_H__
#define __TESTSCENE_H__

#include "System\Scene\BaseScene.h"

class TestScene : public BaseScene {
public:
	TestScene();
	~TestScene();

	void createScene();

	void addTestObject(float testvalue);
	void addTestObject2(float testvalue);

private:
	
};
#endif
