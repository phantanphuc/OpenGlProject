#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#define FPS 55

#include <Windows.h>
#include "Graphic\GraphicClass.h"
#include "SceneManager.h"
#include "InputManager.h"

#include "FPSLimiter.h"

class MainWindow {
public:
	MainWindow();
	~MainWindow();

	void init();
	void run();
	void destroy();

	static MainWindow* getInstance();
	LRESULT m_wndproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
private:
	
	bool ready = false;

	HWND mainwindow_handle;
	HINSTANCE hinstance;

	RECT m_window_rect;
	LPCSTR m_class_name;
	LPCSTR m_window_name;

	void initAttribute();

	///////////////////////////////////////
	/////////// GRAPHIC ///////////////////
	///////////////////////////////////////

	GraphicClass* m_graphic;
	
	void render();

	FPSLimiter* limiter;

};

LRESULT WINAPI wndproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif
