#version 330 core

uniform float Scale;
uniform float myvar;

out vec3 ourColor;

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
void main(){
	gl_Position = vec4(position.x + myvar, position.y, position.z, 1.0);
	ourColor = color;
}