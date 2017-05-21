#ifndef __OPENGLCONTROLLER_H__
#define __OPENGLCONTROLLER_H__

#include <glew.h>
#include "object\component\ComponentHeader.h"
#include "utils\VertexBufferHelper.h"

class OpenglController {
public:
	OpenglController();
	~OpenglController();
	
	static OpenglController* getInstance();

	GLuint CompileVertexShader(GLchar* source);
	GLuint CompileFragmentShader(GLchar* source);

	void createShaderProgram(Mesh3d* mesh3dComponent);

	void bindBuffer(GLuint VBO, GLuint EBO, VertexBufferHelper* bufferHelper);
	GLuint getVAO();
private:
	GLuint VAO;
};
#endif
