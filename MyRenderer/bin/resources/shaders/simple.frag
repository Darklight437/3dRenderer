// ambiently lit shader
#version 410

in vec4 normal;
in vec2 texCoord;
in vec3 fragpos;
out vec4 FragColour;


uniform sampler2D Kd;
uniform vec3 lightPos;
uniform vec4 lightColour;

vec3 lightDir = normalize(lightPos - fragpos);
void main()
 {
	float ambientStrength = 0.1;
	vec4 ambient = ambientStrength * lightColour;
	vec4 tex = texture(Kd, texCoord);
	if(tex.a < 0.1)
	{
		discard;
	}
	
 
	FragColour = texture(Kd, texCoord) * ambient;
 }
