#include "GraphicClass.h"

GraphicClass::GraphicClass(){

}

GraphicClass::~GraphicClass(){

}


void GraphicClass::init(HWND hwnd)
{
	
	m_hwnd = hwnd;
	
	hDC = GetDC(m_hwnd);

	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;



	pf = ChoosePixelFormat(hDC, &pfd);
	if (pf == 0) {
		MessageBox(NULL, "ChoosePixelFormat() failed:  "
			"Cannot find a suitable pixel format.", "Error", MB_OK);
		return;
	}

	if (SetPixelFormat(hDC, pf, &pfd) == FALSE) {
		MessageBox(NULL, "SetPixelFormat() failed:  "
			"Cannot set format specified.", "Error", MB_OK);
		return;
	}

	//DescribePixelFormat(hDC, pf, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
	
	hRC = wglCreateContext(hDC);

	wglMakeCurrent(hDC, hRC);
	glewInit();
	ReleaseDC(m_hwnd, hDC);
	
	initOpenGl();

}

HDC* GraphicClass::getHDC()
{
	return &hDC;
}

HGLRC* GraphicClass::getHGLRC()
{
	return &hRC;
}

void GraphicClass::initOpenGl()
{
	glEnable(GL_DEPTH_TEST);
	ilInit();
}

void GraphicClass::render()
{
	SceneManager::getInstance()->renderCurrentScene();

}

void GraphicClass::start()
{
}

