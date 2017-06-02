#include "TestScene.h"

TestScene::TestScene(){

}

TestScene::~TestScene(){

}

void TestScene::createScene()
{


	//addTestObject2(0.1f);
	//addTestObject2(0.5f);

	addCube(0.5f, 1.0f);
	//addCube(0.5f, 2.0f);
	//addCube(0.5f, 3.0f);
	//addCube(0.5f, 4.0f);
	//addCube(0.5f, 5.0f);
	//addCube(0.5f, 6.0f);
	//addCubeTexture(0.5f);
	addLight();
	commenceScene();
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

void TestScene::addCube(float a, float tx)
{
	GLfloat vertices[] = {
		-a,   a, -a,   0.0f, 1.0f,
		-a,   a, a,   0.0f, 0.0f,
		a,   a, a,   1.0f, 0.0f,
		-a,   a, -a,   0.0f, 1.0f,
		a,   a, a,   1.0f, 0.0f,
		a,   a, -a,   1.0f, 1.0f,

		-a,   -a, -a,   0.0f, 1.0f, 
		-a,   -a, a,   0.0f, 0.0f, 
		a,   -a, a,   1.0f, 0.0f, 
		-a,   -a, -a,   0.0f, 1.0f, 
		a,   -a, a,   1.0f, 0.0f, 
		a,   -a, -a,   1.0f, 1.0f, 

		-a,   -a, -a,   0.0f, 1.0f, 
		-a,   -a, a,   0.0f, 0.0f,
		-a,   a, a,   1.0f, 0.0f,
		-a,   -a, -a,   0.0f, 1.0f,
		-a,   a, a,   1.0f, 0.0f, 
		-a,   a, -a,   1.0f, 1.0f,

		a,   -a, -a,   0.0f, 1.0f,
		a,   -a, a,   0.0f, 0.0f,
		a,   a, a,   1.0f, 0.0f,
		a,   -a, -a,   0.0f, 1.0f,
		a,   a, a,   1.0f, 0.0f,
		a,   a, -a,   1.0f, 1.0f,

		-a,   -a, -a,   0.0f, 1.0f,
		a,   -a, -a,   1.0f, 1.0f,
		a,   a, -a,   1.0f, 0.0f, 
		-a,   -a, -a,   0.0f, 1.0f,
		a,   a, -a,   1.0f, 0.0f, 
		-a,   a, -a,   1.0f, 1.0f, 

		-a,   -a, a,   0.0f, 1.0f, 
		a,   -a, a,   1.0f, 1.0f, 
		a,   a, a,   1.0f, 0.0f, 
		-a,   -a, a,   0.0f, 1.0f, 
		a,   a, a,   1.0f, 0.0f,
		-a,   a, a,   0.0f, 0.0f

	};

	GLuint indices[36];
	for (int i = 0; i < sizeof(indices) / 4; ++i) {
		indices[i] = i;
	}

	Section arr[] = { POSITION, TEXTURE };

	ShaderHelper* objShaderHelper = new  ShaderHelper;
	objShaderHelper->useShaderFromFile("Resource/Shaders/TextureVS.glsl", ShaderType::VERTEXSHADER);
	objShaderHelper->useShaderFromFile("Resource/Shaders/TexturePS.glsl", ShaderType::FRAGMENTSHADER);


	GraphicObject* obj = ObjectHelper::createSimpleMesh3dObject(
		objShaderHelper,
		(float*)vertices, sizeof(vertices),
		(int*)indices, sizeof(indices),
		arr, sizeof(arr) / 4

	);

	delete objShaderHelper;
	addChildObj(obj);
	testObj = obj;

	//////////////////////////////////////////

	GLuint texID = addTexture("Resource/Image/bh.jpg");

	obj->setTranslate(tx, 0.0f, 0.0f);
	obj->getComponent<Mesh3d>()->setTextureID(texID);


}

void TestScene::addCubeTexture(float a)
{
	GLfloat vertices[] = {
		-a,   a, -a,   1.0f, 0.0f, 0.0f,
		-a,   a, a,   1.0f, 0.0f, 0.0f,
		a,   a, a,   1.0f, 0.0f, 0.0f,
		-a,   a, -a,   1.0f, 0.0f, 0.0f,
		a,   a, a,   1.0f, 0.0f, 0.0f,
		a,   a, -a,   1.0f, 0.0f, 0.0f,

		-a,   -a, -a,   1.0f, 1.0f, 0.0f,
		-a,   -a, a,   1.0f, 1.0f, 0.0f,
		a,   -a, a,   1.0f, 1.0f, 0.0f,
		-a,   -a, -a,   1.0f, 1.0f, 0.0f,
		a,   -a, a,   1.0f, 1.0f, 0.0f,
		a,   -a, -a,   1.0f, 1.0f, 0.0f,

		-a,   -a, -a,   0.0f, 1.0f, 0.0f,
		-a,   -a, a,   0.0f, 1.0f, 0.0f,
		-a,   a, a,   0.0f, 1.0f, 0.0f,
		-a,   -a, -a,   0.0f, 1.0f, 0.0f,
		-a,   a, a,   0.0f, 1.0f, 0.0f,
		-a,   a, -a,   0.0f, 1.0f, 0.0f,

		a,   -a, -a,   0.0f, 0.0f, 1.0f,
		a,   -a, a,   0.0f, 0.0f, 1.0f,
		a,   a, a,   0.0f, 0.0f, 1.0f,
		a,   -a, -a,   0.0f, 0.0f, 1.0f,
		a,   a, a,   0.0f, 0.0f, 1.0f,
		a,   a, -a,   0.0f, 0.0f, 1.0f,

		-a,   -a, -a,   1.0f, 1.0f, 1.0f,
		a,   -a, -a,   1.0f, 1.0f, 1.0f,
		a,   a, -a,   1.0f, 1.0f, 1.0f,
		-a,   -a, -a,   1.0f, 1.0f, 1.0f,
		a,   a, -a,   1.0f, 1.0f, 1.0f,
		-a,   a, -a,   1.0f, 1.0f, 1.0f,

		-a,   -a, a,   0.0f, 0.0f, 0.0f,
		a,   -a, a,   0.0f, 0.0f, 0.0f,
		a,   a, a,   0.0f, 0.0f, 0.0f,
		-a,   -a, a,   0.0f, 0.0f, 0.0f,
		a,   a, a,   0.0f, 0.0f, 0.0f,
		-a,   a, a,   0.0f, 0.0f, 0.0f,

	};

	GLuint indices[36];
	for (int i = 0; i < sizeof(indices) / 4; ++i) {
		indices[i] = i;
	}

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

void TestScene::addLight()
{
	GraphicObject* obj = new GraphicObject;

	ComponentLightSource* light = new ComponentLightSource;
	obj->addComponent<ComponentLightSource>(light);

	light->setId(0);
	addChildObj(obj);

	light->setEnableState(true);

	

	obj->setTranslate(1.0f, 0.0f, 1.0f);

	
}

void TestScene::updateScene()
{
	//testObj->getComponent<Mesh3d>()->getSubComponentModel()
	//	->translate( sin(testFloat), 0.0f, 0.0f);
	//testFloat += 3.1415926535f / 180.0f;

	camera_ref->lookat_orbital(R, glm::radians(angle_Oxz), glm::radians(angle_Oy));
	camera_ref->apply();

}

void TestScene::listenKeyboard(keymap * Keymap)
{
	/*
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
	*/
	if (Keymap->getKeyState(VK_UP)) {
		angle_Oy -= 1;
	}
	if (Keymap->getKeyState(VK_DOWN)) {
		angle_Oy += 1;
	}
	if (Keymap->getKeyState(VK_LEFT)) {
		angle_Oxz -= 1;
	}
	if (Keymap->getKeyState(VK_RIGHT)) {
		angle_Oxz += 1;
	}
}

