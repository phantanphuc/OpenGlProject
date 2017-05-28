#version 330 core
in vec2 texcoord;

out vec4 color;

uniform sampler2D ourTexture1;

void main()
{
    //color = vec4(ourColor, 1.0f);
	color = texture2D(ourTexture1, texcoord);
	//color = vec4(texcoord.x,texcoord.y,0.0f,1.0f);
}