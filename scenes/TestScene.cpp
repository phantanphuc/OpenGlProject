#include "TestScene.h"

TestScene::TestScene(){

}

TestScene::~TestScene(){

}

void TestScene::createScene()
{


	//addTestObject2(0.1f);
	//addTestObject2(0.5f);

	//addCube(0.5f, 1.0f);
	//addCube(0.5f, 2.0f);
	//addCube(0.5f, 3.0f);
	//addCube(0.5f, 4.0f);
	//addCube(0.5f, 5.0f);
	//addCube(0.5f, 6.0f);
	//addCubeTexture(0.5f);

	addOrb(0.5f, 10, 20);

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
	objShaderHelper->useShaderFromFile("Resource/Shaders/LightPS.glsl", ShaderType::FRAGMENTSHADER);


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

void TestScene::addOrb(float size, int h_slice, int v_slice)
{
	//GLfloat* vertices;
	float tx = 1.0f;
	float a = 0.5f;

	VertexBufferHelper* bufferHelper = new VertexBufferHelper;
	
	
	
	
	bufferHelper->generateBuffer(3, 36, Section::POSITION, Section::TEXTURE);

	bufferHelper->setVertexPosition(-a, a, -a, 0);
	bufferHelper->setVertexPosition(-a, a, a, 1);
	bufferHelper->setVertexPosition(a, a, a, 2);
	bufferHelper->setVertexPosition(-a, a, -a, 3);
	bufferHelper->setVertexPosition(a, a, a, 4);
	bufferHelper->setVertexPosition(a, a, -a, 5);
	bufferHelper->setVertexPosition(-a, -a, -a, 6);
	bufferHelper->setVertexPosition(-a, -a, a, 7);
	bufferHelper->setVertexPosition(a, -a, a, 8);
	bufferHelper->setVertexPosition(-a, -a, -a, 9);
	bufferHelper->setVertexPosition(a, -a, a, 10);
	bufferHelper->setVertexPosition(a, -a, -a, 11);
	bufferHelper->setVertexPosition(-a, -a, -a, 12);
	bufferHelper->setVertexPosition(-a, -a, a, 13);
	bufferHelper->setVertexPosition(-a, a, a, 14);
	bufferHelper->setVertexPosition(-a, -a, -a, 15);
	bufferHelper->setVertexPosition(-a, a, a, 16);
	bufferHelper->setVertexPosition(-a, a, -a, 17);
	bufferHelper->setVertexPosition(a, -a, -a, 18);
	bufferHelper->setVertexPosition(a, -a, a, 19);
	bufferHelper->setVertexPosition(a, a, a, 20);
	bufferHelper->setVertexPosition(a, -a, -a, 21);
	bufferHelper->setVertexPosition(a, a, a, 22);
	bufferHelper->setVertexPosition(a, a, -a, 23);
	bufferHelper->setVertexPosition(-a, -a, -a, 24);
	bufferHelper->setVertexPosition(a, -a, -a, 25);
	bufferHelper->setVertexPosition(a, a, -a, 26);
	bufferHelper->setVertexPosition(-a, -a, -a, 27);
	bufferHelper->setVertexPosition(a, a, -a, 28);
	bufferHelper->setVertexPosition(-a, a, -a, 29);
	bufferHelper->setVertexPosition(-a, -a, a, 30);
	bufferHelper->setVertexPosition(a, -a, a, 31);
	bufferHelper->setVertexPosition(a, a, a, 32);
	bufferHelper->setVertexPosition(-a, -a, a, 33);
	bufferHelper->setVertexPosition(a, a, a, 34);
	bufferHelper->setVertexPosition(-a, a, a, 35);

	bufferHelper->setVertexTexture(0.0f, 1.0f, 0);
	bufferHelper->setVertexTexture(0.0f, 0.0f, 1);
	bufferHelper->setVertexTexture(1.0f, 0.0f, 2);
	bufferHelper->setVertexTexture(0.0f, 1.0f, 3);
	bufferHelper->setVertexTexture(1.0f, 0.0f, 4);
	bufferHelper->setVertexTexture(1.0f, 1.0f, 5);
	bufferHelper->setVertexTexture(0.0f, 1.0f, 6);
	bufferHelper->setVertexTexture(0.0f, 0.0f, 7);
	bufferHelper->setVertexTexture(1.0f, 0.0f, 8);
	bufferHelper->setVertexTexture(0.0f, 1.0f, 9);
	bufferHelper->setVertexTexture(1.0f, 0.0f, 10);
	bufferHelper->setVertexTexture(1.0f, 1.0f, 11);
	bufferHelper->setVertexTexture(0.0f, 1.0f, 12);
	bufferHelper->setVertexTexture(0.0f, 0.0f, 13);
	bufferHelper->setVertexTexture(1.0f, 0.0f, 14);
	bufferHelper->setVertexTexture(0.0f, 1.0f, 15);
	bufferHelper->setVertexTexture(1.0f, 0.0f, 16);
	bufferHelper->setVertexTexture(1.0f, 1.0f, 17);
	bufferHelper->setVertexTexture(0.0f, 1.0f, 18);
	bufferHelper->setVertexTexture(0.0f, 0.0f, 19);
	bufferHelper->setVertexTexture(1.0f, 0.0f, 20);
	bufferHelper->setVertexTexture(0.0f, 1.0f, 21);
	bufferHelper->setVertexTexture(1.0f, 0.0f, 22);
	bufferHelper->setVertexTexture(1.0f, 1.0f, 23);
	bufferHelper->setVertexTexture(0.0f, 1.0f, 24);
	bufferHelper->setVertexTexture(1.0f, 1.0f, 25);
	bufferHelper->setVertexTexture(1.0f, 0.0f, 26);
	bufferHelper->setVertexTexture(0.0f, 1.0f, 27);
	bufferHelper->setVertexTexture(1.0f, 0.0f, 28);
	bufferHelper->setVertexTexture(1.0f, 1.0f, 29);
	bufferHelper->setVertexTexture(0.0f, 1.0f, 30);
	bufferHelper->setVertexTexture(1.0f, 1.0f, 31);
	bufferHelper->setVertexTexture(1.0f, 0.0f, 32);
	bufferHelper->setVertexTexture(0.0f, 1.0f, 33);
	bufferHelper->setVertexTexture(1.0f, 0.0f, 34);
	bufferHelper->setVertexTexture(0.0f, 0.0f, 35);


	GLuint indices[36];
	for (int i = 0; i < sizeof(indices) / 4; ++i) {
		indices[i] = i;
	}

	bufferHelper->setIndexBufferRef((int*)indices, sizeof(indices));

	ShaderHelper* objShaderHelper = new  ShaderHelper;
	objShaderHelper->useShaderFromFile("Resource/Shaders/TextureVS.glsl", ShaderType::VERTEXSHADER);
	objShaderHelper->useShaderFromFile("Resource/Shaders/LightPS.glsl", ShaderType::FRAGMENTSHADER);


	GraphicObject* obj = ObjectHelper::createSimpleMesh3dObject(
		objShaderHelper,
		bufferHelper

	);

	delete objShaderHelper;
	addChildObj(obj);
	testObj = obj;

	//////////////////////////////////////////

	GLuint texID = addTexture("Resource/Image/vy.jpg");

	obj->setTranslate(tx, 0.0f, 0.0f);
	obj->getComponent<Mesh3d>()->setTextureID(texID);
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

