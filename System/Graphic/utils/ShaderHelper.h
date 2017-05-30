#ifndef __SHADERHELPER_H__
#define __SHADERHELPER_H__

#include <stdio.h>
#include <string>

enum ShaderType {
	VERTEXSHADER, FRAGMENTSHADER
};

struct VertexShaderStructure
{
	std::string header_uniform;
	std::string header_attribute;
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
