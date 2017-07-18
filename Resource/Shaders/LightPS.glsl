#version 420

in vec2 texcoord;
out vec4 color;

uniform sampler2D ourTexture1;


struct LightStructure{
	vec4 position;
	vec4 color;
	float ambientPow;
	float diffusePow;
	float spectularPow;
	bool enable;
};


layout(std140) uniform LightSystem {
    LightStructure light[9];
};



void main()
{
	color = texture2D(ourTexture1, texcoord);
	//color = vec4(aOuterColor.xyz, 1.0f);
	//color = light[0].position;
}