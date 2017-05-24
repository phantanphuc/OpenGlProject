#version 330 core

uniform float Scale;
uniform float myvar;

layout (location = 0) in vec3 position;
void main(){
	gl_Position = vec4(position.x + myvar, position.y, position.z, 1.0);
}