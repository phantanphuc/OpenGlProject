#ifndef __GRAPHICCLASS_H__
#define __GRAPHICCLASS_H__

#include <windows.h>


#include <glew.h>
#include "object\GraphicObject.h"
#include "utils\ShaderHelper.h"

class GraphicClass {
public:
	GraphicClass();
	~GraphicClass();

	void init(HWND hwnd);

	HDC* getHDC();
	HGLRC* getHGLRC();
private:
	HWND		m_hwnd;
	int         pf;
	HDC         hDC;
	HGLRC		hRC;
	PIXELFORMATDESCRIPTOR pfd;
	
	void initOpenGl();
	void render();
};
#endif
