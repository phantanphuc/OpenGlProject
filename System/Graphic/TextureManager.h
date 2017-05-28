#ifndef __TEXTUREMANAGER_H__
#define __TEXTUREMANAGER_H__

#include <memory.h>
#include "DeviL\IL\il.h"

struct TextureNode {
	char* path[64];
	int TextureID;
	TextureNode* nextnode = nullptr;

};

class TextureManager {
public:
	TextureManager();
	~TextureManager();

	void addTexture(char* path);

	static bool compareString(char* str1, char* str2);

private:
	TextureNode* texture_list;
};
#endif
