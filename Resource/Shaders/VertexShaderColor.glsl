#version 330 core

uniform mat4 Matrix_PVM; 

out vec3 ourColor;

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
void main(){
	vec4 pos = Matrix_PVM *  vec4(position.x + 0, position.y, position.z, 1.0);

	gl_Position = pos;
	ourColor = color;
}