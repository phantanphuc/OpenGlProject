#include "TextureManager.h"

TextureManager::TextureManager(){

}

TextureManager::~TextureManager(){
	for (TextureNode* ptr = texture_list; ; ptr = ptr->nextnode) {
		TextureNode* delnode = ptr;
		ptr = ptr->nextnode;
		glDeleteTextures(1, &(delnode->TextureID));
		delete delnode;
	}
}

int TextureManager::addTexture(char * path)
{

	for (TextureNode* ptr = texture_list;; ptr = ptr->nextnode) {
		if (ptr == nullptr) break;
		if (compareString(path, ptr->path)) {
			return ptr->TextureID;
		}
	}

	//////////////////////////////////////

	ILboolean result = ilLoadImage(path);

	if (!result)
	{
		ILenum err = ilGetError();
		printf("the error %d\n", err);
		printf("string is %s\n", ilGetString(err));
	}


	int width = ilGetInteger(IL_IMAGE_WIDTH);
	int height = ilGetInteger(IL_IMAGE_HEIGHT);

	int size = ilGetInteger(IL_IMAGE_SIZE_OF_DATA);
	ILubyte * image = ilGetData();



	glBindTexture(GL_TEXTURE_2D, 0);
	GLuint texture_id;

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
											// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0); 
	ilDeleteImage(1);

	//////////////////////////////////////


	TextureNode* newnode = new TextureNode;
	copyString(path, newnode->path);
	newnode->TextureID = texture_id;

	if (texture_list == nullptr) {
		texture_list = newnode;
	}
	else {
		newnode->nextnode = texture_list;
		texture_list = newnode;
	}
	return texture_id;
}

bool TextureManager::compareString(char * str1, char * str2)
{
	while (true) {
		if (*str1++ != *str2++) return false;
		if (*str1 == '\0') return true;
	}
	return false;
}

void TextureManager::copyString(char * src, char * dest)
{
	while (true) {
		
		*dest++ = *src++;
		if (*src == '\0') {
			*dest = '\0';
			return;
		}
	}
}
