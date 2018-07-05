// ambiently lit shader
#version 410

in vec4 normal;
in vec2 texCoord;
out vec4 FragColour;


uniform sampler2D Kd;


void main()
 {
	float ambientStrength = 0.1;
	vec4 ambient = ambientStrength * vec4(1.0f, 1.0f, 1.0f, 1.0f);
	vec4 tex = texture(Kd, texCoord);
	if(tex.a < 0.1)
	{
		discard;
	}
	
 
	FragColour = texture(Kd, texCoord) * ambient;
 }
