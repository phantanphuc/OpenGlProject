#ifndef __SHADERHELPER_H__
#define __SHADERHELPER_H__

#include <stdio.h>

enum ShaderType {
	VERTEXSHADER, FRAGMENTSHADER
};

class ShaderHelper {
public:
	ShaderHelper();
	~ShaderHelper();

	void useShaderFromFile(char* path, ShaderType type);

	char* getVertexShader();
	char* getFragmentShader();

	void releaseAll();
	void releaseVertexShader();
	void releaseFragmentShader();

private:
	char* VertexShader = nullptr;
	char* FragmentShader = nullptr;
};
#endif
