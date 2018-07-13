// ambiently lit shader
#version 410

in vec4 normal;
in vec2 texCoord;
in vec4 lightDir;
out vec4 FragColour;


uniform sampler2D Kd;
uniform vec4 lightColour;


void main()
 {
	
	
	float ambientStrength = 0.2;
	
	//ambient light
	vec4 ambient = ambientStrength * lightColour;
	
	//diffuse light
	float lambert = max(dot(normal, lightDir), 0.0);
	vec4 diffuse = lambert * lightColour;
	
	vec4 tex = texture(Kd, texCoord);
	if(tex.a < 0.1)
	{
		discard;
	}
	
 
	FragColour = texture(Kd, texCoord) * (ambient + diffuse);
 }
