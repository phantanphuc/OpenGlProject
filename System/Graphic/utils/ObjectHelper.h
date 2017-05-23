#ifndef __OBJECTHELPER_H__
#define __OBJECTHELPER_H__

#include <glew.h>
#include "System\Graphic\utils\ShaderHelper.h"
#include "System\Graphic\OpenglController.h"
#include "System\Graphic\object\ObjectManager.h"

class ObjectHelper {
public:
	ObjectHelper();
	~ObjectHelper();

	static GraphicObject* createSimpleMesh3dObject(
		ShaderHelper* objShaderHelper, 
		float* vertexBuffer, int vertexBufferSize,
		int* indexBuffer, int indexBufferSize,
		Section* listSection, int numSection
		);

private:
};
#endif
