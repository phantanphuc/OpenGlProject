#include "ObjectHelper.h"

ObjectHelper::ObjectHelper(){

}

ObjectHelper::~ObjectHelper(){

}

GraphicObject * ObjectHelper::createSimpleMesh3dObject(
	ShaderHelper * objShaderHelper, 
	float * vertexBuffer, int vertexBufferSize, 
	int * indexBuffer, int indexBufferSize, 
	Section * listSection, int numSection)
{

	GraphicObject* obj = new GraphicObject;
	obj->addComponent<Mesh3d>();
	Mesh3d* mesh3dref = obj->getComponent<Mesh3d>();

	mesh3dref->setVertexShaderId(OpenglController::getInstance()->
		CompileVertexShader(objShaderHelper->getVertexShader()));
	mesh3dref->setFragmentShaderId(OpenglController::getInstance()->
		CompileFragmentShader(objShaderHelper->getFragmentShader()));
	OpenglController::getInstance()->createShaderProgram(mesh3dref);


	mesh3dref->generateVAO_VBO_EBO();


	VertexBufferHelper helper = VertexBufferHelper();
	helper.setVertexBufferRef(vertexBuffer, vertexBufferSize);

	helper.setSection_Arr(numSection, listSection);
	helper.setIndexBufferRef(indexBuffer, indexBufferSize);

	OpenglController::getInstance()->bindBuffer(mesh3dref, &helper);


	return obj;
}

GraphicObject * ObjectHelper::createSimpleMesh3dObject(
	ShaderHelper * objShaderHelper, 
	VertexBufferHelper * bufferHelper)
{
	GraphicObject* obj = new GraphicObject;
	obj->addComponent<Mesh3d>();
	Mesh3d* mesh3dref = obj->getComponent<Mesh3d>();

	mesh3dref->setVertexShaderId(OpenglController::getInstance()->
		CompileVertexShader(objShaderHelper->getVertexShader()));
	mesh3dref->setFragmentShaderId(OpenglController::getInstance()->
		CompileFragmentShader(objShaderHelper->getFragmentShader()));
	OpenglController::getInstance()->createShaderProgram(mesh3dref);


	mesh3dref->generateVAO_VBO_EBO();

	OpenglController::getInstance()->bindBuffer(mesh3dref, bufferHelper);

	return obj;
}
