// a simple vertex shader
#version 410

layout( location = 0 ) in vec4 Position;
layout( location = 1 ) in vec4 Normal;
layout( location = 2 ) in vec2 TexCoord;


//broken one
uniform vec4 lightPos;
uniform mat4 model;
uniform vec4 viewPos;

//used to find the modelspace position of the vertex
uniform mat4 ProjectionViewModel;


out vec4 normal;
out vec2 texCoord;
out vec4 lightDir;
out float spec;

void main()
 {

	normal = normalize(Normal);
	texCoord = TexCoord;
	vec4 fragpos = vec4( model * Position);
	lightDir = normalize(lightPos - fragpos);
	
	//reflection calculations
	vec4 viewdir = normalize(viewPos - fragpos);
	vec4 reflectDir = reflect(-lightDir, normal);
	
	spec = pow(max(dot(viewdir, reflectDir), 0.0), 64);
	
	gl_Position = ProjectionViewModel * Position;
 }