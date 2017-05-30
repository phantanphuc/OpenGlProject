#version 400
in vec2 texcoord;

out vec4 color;

uniform sampler2D ourTexture1;



void main()
{
	color = texture2D(ourTexture1, texcoord);
}