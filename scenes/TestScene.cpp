#include "TestScene.h"

TestScene::TestScene(){

}

TestScene::~TestScene(){

}

void TestScene::createScene()
{


	//addTestObject2(0.1f);
	addTestObject2(0.5f);

	useDefaultCamera();
}

void TestScene::addTestObject2(float testvalue)
{


	GLfloat vertices[] = {
		// Positions         // Colors
		0.5f,   1.0f - testvalue, 0.0f,   1.0f, 0.0f, 0.0f,  // Bottom Right
		-0.5f, 0.0f - testvalue, 0.0f,   0.0f, 1.0f, 0.0f,  // Bottom Left
		1.0f,   0.0f - testvalue, 0.0f,   0.0f, 0.0f, 1.0f   // Top 
	};

	GLuint indices[] = {
		0, 1, 2
	};

	Section arr[] = { POSITION, COLOR };

	ShaderHelper* objShaderHelper = new  ShaderHelper;
	objShaderHelper->useShaderFromFile("Resource/Shaders/VertexShaderColor.glsl", ShaderType::VERTEXSHADER);
	objShaderHelper->useShaderFromFile("Resource/Shaders/FragmentShaderColor.glsl", ShaderType::FRAGMENTSHADER);

	GraphicObject* obj = ObjectHelper::createSimpleMesh3dObject(
		objShaderHelper,
		(float*)vertices, sizeof(vertices),
		(int*)indices, sizeof(indices),
		arr, sizeof(arr) / 4

	);

	delete objShaderHelper;

	addChildObj(obj);

	testObj = obj;

}

void TestScene::updateScene()
{
	//testObj->getComponent<Mesh3d>()->getSubComponentModel()
	//	->translate( sin(testFloat), 0.0f, 0.0f);
	//testFloat += 3.1415926535f / 180.0f;

}

void TestScene::listenKeyboard(keymap * Keymap)
{
	if (Keymap->getKeyState(VK_UP)) {
		testObj->getComponent<Mesh3d>()->getSubComponentModel()
			->translate( 0.0f, 0.05f, 0.0f);
	}
	if (Keymap->getKeyState(VK_DOWN)) {
		testObj->getComponent<Mesh3d>()->getSubComponentModel()
			->translate(0.0f, -0.05f, 0.0f);
	}
	if (Keymap->getKeyState(VK_LEFT)) {
		testObj->getComponent<Mesh3d>()->getSubComponentModel()
			->translate(-0.05f, 0.0f, 0.0f);
	}
	if (Keymap->getKeyState(VK_RIGHT)) {
		testObj->getComponent<Mesh3d>()->getSubComponentModel()
			->translate(0.05f, 0.0f, 0.0f);
	}
}

