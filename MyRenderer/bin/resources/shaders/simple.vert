// a simple vertex shader
#version 410

layout( location = 0 ) in vec4 Position;
layout( location = 1 ) in vec4 Normal;
layout( location = 2 ) in vec2 TexCoord;

uniform mat4 model;

//used to find the modelspace position of the vertex
uniform mat4 ProjectionViewModel;
uniform mat3 NormalMatrix;

out vec4 normal;
out vec2 texCoord;
out vec4 fragpos;

void main()
 {
	normal = normalize(vec4(NormalMatrix * Normal.xyz, 0.0));
	texCoord = TexCoord;
	fragpos = vec4( model * Position);
	
	gl_Position = ProjectionViewModel * Position;
 }