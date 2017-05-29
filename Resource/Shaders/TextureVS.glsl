#version 330 core

uniform float myvar;

uniform mat4 Matrix_Translate; 
uniform mat4 Matrix_View; 
uniform mat4 Matrix_Projection; 

out vec2 texcoord;

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 TexCoord;
void main(){
	
	vec4 pos = Matrix_Translate * vec4(position, 1.0);
	

	pos = Matrix_Projection * Matrix_View *   pos;


	gl_Position = pos;
	texcoord = TexCoord;
	
}