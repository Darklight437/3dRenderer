// a simple vertex shader
#version 410

layout( location = 0 ) in vec4 Position;
layout( location = 1 ) in vec4 Normal;
layout( location = 2 ) in vec2 TexCoord;

out vec4 normal;
out vec2 texCoord;
out vec4 lightDir;

uniform vec4 lightPos;
uniform mat4 model;
uniform mat4 ProjectionViewModel;




void main()
 {
	
	normal = normalize(Normal);
	texCoord = TexCoord;
	vec4 fragpos = vec4( model * Position);
	vec4 lightDir = normalize(lightPos - fragpos);
	gl_Position = ProjectionViewModel * Position;
 }