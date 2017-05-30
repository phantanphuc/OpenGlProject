#version 330

in vec2 texcoord;

out vec4 color;

uniform sampler2D ourTexture1;

layout(std140) uniform BlobSettings {
    vec4 InnerColor;
    vec4 OuterColor;
    float RadiusInner;
    float RadiusOuter;
};

void main()
{
	color = texture2D(ourTexture1, texcoord);
	//color = vec4(InnerColor.xyz, 1.0f);
}