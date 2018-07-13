// a simple vertex shader
#version 410

layout( location = 0 ) in vec4 Position;
layout( location = 1 ) in vec4 Normal;
layout( location = 2 ) in vec2 TexCoord;


//broken one
uniform vec4 lightPos;
uniform mat4 model;

//used to find the modelspace position of the vertex
uniform mat4 ProjectionViewModel;


out vec4 normal;
out vec2 texCoord;
out vec4 lightDir;


void main()
 {

	normal = normalize(Normal);
	texCoord = TexCoord;
	vec4 fragpos = vec4( model * Position);
	lightDir = normalize(lightPos - fragpos);
	gl_Position = ProjectionViewModel * Position;
 }