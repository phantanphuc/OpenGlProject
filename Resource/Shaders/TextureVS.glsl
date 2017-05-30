#version 330 core

uniform float myvar;

uniform mat4 Matrix_PVM; 

out vec2 texcoord;

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 TexCoord;
void main(){
	
	vec4 pos = vec4(position, 1.0);
	pos = Matrix_PVM * pos;
	



	gl_Position = pos;
	texcoord = TexCoord;
	
}