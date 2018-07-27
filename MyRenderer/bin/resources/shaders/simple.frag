// ambiently lit shader
#version 410

in vec4 normal;
in vec2 texCoord;
in vec4 lightDir;
in float spec;
out vec4 FragColour;


uniform sampler2D Kd;
uniform vec4 lightColour;


void main()
 {
	
	
	float ambientStrength = 0.2;
	float specularStrength = 0.9;
	
	
	//ambient light
	vec4 ambient = ambientStrength * lightColour;
	
	//diffuse light
	float lambert = max(dot(normal, lightDir), 0.0);
	vec4 diffuse = lambert * lightColour;
	
	//directional light
	vec4 directional = vec4(3.0, 1.0, 1.0, 0.0);
	
	lambert = max(dot(normal, directional), 0.0);
	
	//diffuse adds both diffuse lights together
	diffuse = diffuse + (lambert * lightColour * ambientStrength);
	
	//specular
	vec4 specular =(specularStrength * spec * lightColour);
	
	
	
	//texture transparency
	vec4 tex = texture(Kd, texCoord);
	if(tex.a < 0.1)
	{
		discard;
	}
	
 
	FragColour = texture(Kd, texCoord) * (ambient + diffuse + specular);
 }
