#include "TestScene.h"

TestScene::TestScene(){

}

TestScene::~TestScene(){

}

void TestScene::createScene()
{


	addTestObject2(0.1f);
	addTestObject2(0.9f);
}

void TestScene::addTestObject(float testvalue = 0.0f)
{
	GraphicObject* obj;
	obj = new GraphicObject;
	obj->addComponent<Mesh3d>();
	Mesh3d* mesh3dref = obj->getComponent<Mesh3d>();

	ShaderHelper* objShaderHelper = new  ShaderHelper;

	GLfloat vertices[] = {
		0.5f,  1.0f - testvalue, 0.0f,  // Top Right
		0.5f, 0.5f - testvalue, 0.0f,  // Bottom Right
		-0.5f, 0.5f - testvalue, 0.0f
	};
	GLuint indices[] = {
		0, 1, 2
	};

	objShaderHelper->useShaderFromFile("Resource/Shaders/FirstVertexShader.glsl", ShaderType::VERTEXSHADER);
	objShaderHelper->useShaderFromFile("Resource/Shaders/FirstFragmentShader.glsl", ShaderType::FRAGMENTSHADER);


	mesh3dref->setVertexShaderId(OpenglController::getInstance()->
		CompileVertexShader(objShaderHelper->getVertexShader()));
	mesh3dref->setFragmentShaderId(OpenglController::getInstance()->
		CompileFragmentShader(objShaderHelper->getFragmentShader()));
	OpenglController::getInstance()->createShaderProgram(mesh3dref);


	mesh3dref->generateVAO_VBO_EBO();

	VertexBufferHelper helper = VertexBufferHelper();

	helper.setVertexBufferRef((float*)vertices, sizeof(vertices));
	//helper.setSection_Arg(1, Section::POSITION);
	
	Section arr[] = { POSITION };
	helper.setSection_Arr(1, arr);

	helper.setIndexBufferRef((int*)indices, sizeof(indices));

	OpenglController::getInstance()->bindBuffer(mesh3dref, &helper);

	delete objShaderHelper;

	objectManager->addNode(obj);
}

void TestScene::addTestObject2(float testvalue)
{
	GLfloat vertices[] = {
		0.5f,  1.0f - testvalue, 0.0f,  // Top Right
		0.5f, 0.5f - testvalue, 0.0f,  // Bottom Right
		-0.5f, 0.5f - testvalue, 0.0f
	};
	GLuint indices[] = {
		0, 1, 2
	};

	Section arr[] = { POSITION };

	ShaderHelper* objShaderHelper = new  ShaderHelper;
	objShaderHelper->useShaderFromFile("Resource/Shaders/FirstVertexShader.glsl", ShaderType::VERTEXSHADER);
	objShaderHelper->useShaderFromFile("Resource/Shaders/FirstFragmentShader.glsl", ShaderType::FRAGMENTSHADER);

	GraphicObject* obj = ObjectHelper::createSimpleMesh3dObject(
		objShaderHelper,
		(float*)vertices, sizeof(vertices),
		(int*)indices, sizeof(indices),
		arr, sizeof(arr) / 4

	);

	delete objShaderHelper;

	objectManager->addNode(obj);

}

