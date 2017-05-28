#include "TestScene.h"

TestScene::TestScene(){

}

TestScene::~TestScene(){

}

void TestScene::createScene()
{


	//addTestObject2(0.1f);
	//addTestObject2(0.5f);

	addCubeTexture(0.5f);

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

void TestScene::addCube(float a)
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






	ILboolean result = ilLoadImage("Resource/Image/bh.jpg");

	if (result == true)
	{
		printf("the image loaded successfully\n");
	}
	else
	{
		printf("The image failed to load\n");

		ILenum err = ilGetError();
		printf("the error %d\n", err);
		printf("string is %s\n", ilGetString(err));
	}

	int width = ilGetInteger(IL_IMAGE_WIDTH);
	int height = ilGetInteger(IL_IMAGE_HEIGHT);

	int size = ilGetInteger(IL_IMAGE_SIZE_OF_DATA);
	printf("Data size:  %d\n", size);
	ILubyte * image = ilGetData();



	glBindTexture(GL_TEXTURE_2D, 0);
	GLuint texture1;

	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
											// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load, create texture and generate mipmaps
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, 0); 




	int i = 0;

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

