#include "TextureManager.h"

TextureManager::TextureManager(){

}

TextureManager::~TextureManager(){

}

void TextureManager::addTexture(char * path)
{
	if (texture_list == nullptr) {
		texture_list = new TextureNode;
		
		return;
	}
	else {

	}
}

bool TextureManager::compareString(char * str1, char * str2)
{
	while (true) {
		if (*str1++ != *str2++) return false;
		if (*str1 == '\0') return true;
	}
	return false;
}
