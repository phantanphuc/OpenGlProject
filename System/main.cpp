#include "MainWindow.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {
	MainWindow* executer = new MainWindow;
	executer->run();
	return 0;
}