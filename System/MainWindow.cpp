#include "MainWindow.h"


MainWindow* m_main_instance = nullptr;

void testeee() {
	GraphicObject* obj;
	obj = new GraphicObject;
	obj->addComponent<Mesh3d>();
	Mesh3d* mesh3dref = obj->getComponent<Mesh3d>();

	ShaderHelper* objShaderHelper = new  ShaderHelper;

	GLfloat vertices[] = {
		0.5f,  0.5f, 0.0f,  // Top Right
		0.5f, -0.5f, 0.0f,  // Bottom Right
		-0.5f, -0.5f, 0.0f,  // Bottom Left
		-0.5f,  0.5f, 0.0f   // Top Left 
	};
	GLuint indices[] = {  
		0, 1, 3, 
		1, 2, 3 
	};

	objShaderHelper->useShaderFromFile("Resource/Shaders/FirstVertexShader.glsl", ShaderType::VERTEXSHADER);
	objShaderHelper->useShaderFromFile("Resource/Shaders/FirstFragmentShader.glsl", ShaderType::FRAGMENTSHADER);


	mesh3dref->setVertexShaderId(OpenglController::getInstance()->
		CompileVertexShader(objShaderHelper->getVertexShader()));
	mesh3dref->setFragmentShaderId(OpenglController::getInstance()->
		CompileFragmentShader(objShaderHelper->getFragmentShader()));
	OpenglController::getInstance()->createShaderProgram(mesh3dref);

	
	mesh3dref->generateVAO_VBO_EBO();

	VertexBufferHelper helper = VertexBufferHelper();

	helper.generateBuffer(2, 4, Section::POSITION);
	helper.setVertexPosition(vertices, 0);
	helper.setVertexPosition(vertices + 3, 1);
	helper.setVertexPosition(vertices + 6, 2);
	helper.setVertexPosition(vertices + 9, 3);

	helper.setIndexBufferRef((int*)indices, sizeof(indices));

	OpenglController::getInstance()->bindBuffer(mesh3dref, &helper);

	ObjectManager::getInstance()->addNode(obj);


}

MainWindow::MainWindow() {

}

MainWindow::~MainWindow() {

}

void MainWindow::init()
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	initAttribute();

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hinstance;
	wc.lpfnWndProc = (WNDPROC)wndproc;
	wc.lpszClassName = m_class_name;
	wc.lpszMenuName = NULL;
	wc.style = CS_VREDRAW | CS_HREDRAW;

	RegisterClassEx(&wc);

	mainwindow_handle = CreateWindowA(
		m_class_name,
		m_window_name,
		WS_OVERLAPPEDWINDOW,
		100, 100,
		m_window_rect.right - m_window_rect.left,
		m_window_rect.bottom - m_window_rect.top,
		NULL, NULL,
		hinstance,
		NULL
	);

	m_graphic->init(mainwindow_handle);
	
	testeee();

	ShowWindow(mainwindow_handle, SW_SHOW);

}

void MainWindow::run()
{
	MSG msg;
	msg = { 0 };




	init();

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{



		}
	}

}

void MainWindow::destroy()
{
}

MainWindow * MainWindow::getInstance()
{
	if (m_main_instance == nullptr) {
		m_main_instance = new MainWindow;
	}
	return m_main_instance;
}

void MainWindow::initAttribute()
{
	m_window_rect = { 0, 0, 640, 480 };
	AdjustWindowRect(&m_window_rect, WS_OVERLAPPEDWINDOW, TRUE);

	m_class_name = "MainwindowClass";
	m_window_name = "demo";

	m_graphic = new GraphicClass;
}

void MainWindow::render()
{

	glClearColor(0.7f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	ObjectManager::getInstance()->ExecuteObject();
}



LRESULT MainWindow::m_wndproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static PAINTSTRUCT ps;

	switch (uMsg)
	{
	case WM_PAINT:
	{
		HDC hDC = BeginPaint(hWnd, &ps);


		render();

		SwapBuffers(hDC);

		EndPaint(hWnd, &ps);



		InvalidateRect(hWnd, NULL, false);

		break;
	}

	case WM_SIZE:
		glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));
		PostMessage(hWnd, WM_PAINT, 0, 0);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}

LRESULT WINAPI wndproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return MainWindow::getInstance()->m_wndproc(hWnd, uMsg, wParam, lParam);
}
