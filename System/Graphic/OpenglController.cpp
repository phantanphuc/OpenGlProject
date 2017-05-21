#include "OpenglController.h"



OpenglController* m_instance_controller = nullptr;

OpenglController::OpenglController(){
	glGenVertexArrays(1, &VAO);
}

OpenglController::~OpenglController(){

}

OpenglController * OpenglController::getInstance()
{
	if (m_instance_controller == nullptr) {
		m_instance_controller = new OpenglController;
	}
	return m_instance_controller;
}

GLuint OpenglController::CompileVertexShader(GLchar* source)
{
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &source, nullptr);
	glCompileShader(vertexShader);
	// Check for compile time errors
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
	}
	return vertexShader;
}

GLuint OpenglController::CompileFragmentShader(GLchar* source)
{
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &source, nullptr);
	glCompileShader(fragmentShader);
	
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
	}
	return fragmentShader;
}

void OpenglController::createShaderProgram(Mesh3d * mesh3dComponent)
{
	GLint success;
	GLchar infoLog[512];

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, mesh3dComponent->getVertexShaderId());
	glAttachShader(shaderProgram, mesh3dComponent->getFragmentShaderId());
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
	}
	glDeleteShader(mesh3dComponent->getVertexShaderId());
	glDeleteShader(mesh3dComponent->getFragmentShaderId());

	mesh3dComponent->setShaderProgramId(shaderProgram);

}

void OpenglController::bindBuffer(GLuint VBO, GLuint EBO, VertexBufferHelper* bufferHelper)
{



	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 
		bufferHelper->getVertexBufferSize(), 
		bufferHelper->getVertexBuffer(), 
		GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 
		bufferHelper->getIndexBufferSize(), 
		bufferHelper->getIndexBuffer(), 
		GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs), remember: do NOT unbind the EBO, keep it bound to this VAO

}

GLuint OpenglController::getVAO()
{
	return VAO;
}
