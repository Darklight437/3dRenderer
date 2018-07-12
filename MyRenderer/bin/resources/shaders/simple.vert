// a simple vertex shader
#version 410

layout( location = 0 ) in vec4 Position;
layout( location = 1 ) in vec4 Normal;
layout( location = 2 ) in vec2 TexCoord;

out vec4 normal;
out vec2 texCoord;
out vec3 fragpos;
out vec3 lightposition;

uniform vec3 lightPos;
uniform vec4 lightColour;
uniform mat4 ProjectionViewModel;
uniform mat4 model;



void main()
 {
	lightposition = lightPos;
	normal = Normal;
	texCoord = TexCoord;
	vec3 fragpos = vec3( model * Position);
	gl_Position = ProjectionViewModel * Position;
 }