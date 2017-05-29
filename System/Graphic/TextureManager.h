#ifndef __TEXTUREMANAGER_H__
#define __TEXTUREMANAGER_H__

#include <memory.h>
#include "DeviL\IL\il.h"
#include <glew.h>

struct TextureNode {
	char path[64];
	GLuint TextureID;

	//GLint texture_parameter; // GL_REPEAT
	//GLint texture_filtering;
	TextureNode* nextnode = nullptr;

	TextureNode() {
		//texture_parameter = GL_REPEAT;
		//texture_filtering = GL_LINEAR;
	}

};

class TextureManager {
public:
	TextureManager();
	~TextureManager();

	int addTexture(char* path);

	static bool compareString(char* str1, char* str2);

private:
	TextureNode* texture_list;
	static void copyString(char* src, char* dest);
};
#endif
