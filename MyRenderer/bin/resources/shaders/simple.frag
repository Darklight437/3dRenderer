// ambiently lit shader
#version 410

in vec4 normal;
in vec2 texCoord;
in vec4 fragpos;

out vec4 FragColour;


uniform sampler2D Kd;
uniform vec4 lightColour;
uniform vec4 viewPos;
uniform vec4 lightPos;


void main()
 {
	float ambientStrength = 0.2;
	float diffuseStrength = 0.7;
	float specularStrength = 0.9;
	
	vec4 texturesample = texture(Kd, texCoord);
	
	//ambient light
	vec4 ambient = ambientStrength * lightColour * texturesample;
	
	//diffuse light
	vec4 lightDir = normalize(lightPos - fragpos);
	float lambert = max(dot(normal, lightDir), 0.0);
	vec4 diffuse = lambert * lightColour * texturesample;
	
	//specular light
	vec4 viewdir = normalize(viewPos - fragpos);
	vec4 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewdir, reflectDir), 0.0), 64);
	vec4 specular = spec * lightColour * specularStrength;
	
	//directional light
	//vec4 directional = vec4(3.0, 1.0, 1.0, 0.0);
	
	//lambert = max(dot(normal, directional), 0.0);
	
	//diffuse adds both diffuse lights together
	//diffuse = diffuse + (lambert * lightColour * ambientStrength);
	
	//specular
	//vec4 specular =(specularStrength * spec * lightColour);
	
	//texture transparency
	if(texturesample.a < 0.1)
	{
		discard;
	}
	
 
	FragColour = ambient + diffuse + specular;
 }
