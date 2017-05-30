#include "ShaderHelper.h"

ShaderHelper::ShaderHelper(){

}

ShaderHelper::~ShaderHelper(){

}

void ShaderHelper::useShaderFromFile(char * path, ShaderType type)
{
	int file_size = 0;
	char** current_shader_ref = nullptr;
	switch (type)
	{
	case VERTEXSHADER:
		current_shader_ref = &VertexShader;
		break;
	case FRAGMENTSHADER:
		current_shader_ref = &FragmentShader;
		break;
	default:
		break;
	}


	FILE* reader;
	fopen_s(&reader, path, "r");
	fseek(reader, 0, SEEK_END);

	file_size = ftell(reader);
	fseek(reader, 0, SEEK_SET);

	*current_shader_ref = new char[file_size + 1];

	fread(*current_shader_ref, 1, file_size, reader);
	//(*current_shader_ref)[file_size + 1] = 'a';

	for (int i = 0; ; ++i) {
		if ((*current_shader_ref)[file_size - i] == '}') {
			(*current_shader_ref)[file_size - i + 1] = '\0';
			break;
		}
	}
	
}

char * ShaderHelper::getVertexShader()
{
	return VertexShader;
}

char * ShaderHelper::getFragmentShader()
{
	return FragmentShader;
}

void ShaderHelper::releaseAll()
{
	if (VertexShader != nullptr) {
		releaseVertexShader();
	}
	if (FragmentShader != nullptr) {
		releaseFragmentShader();
	}
}

void ShaderHelper::releaseVertexShader()
{
	delete[] VertexShader;
}

void ShaderHelper::releaseFragmentShader()
{
	delete[] FragmentShader;
}
