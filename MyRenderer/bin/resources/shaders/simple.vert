// a simple shader
#version 410
layout( location = 0 ) in vec4 Position;
layout( location = 1 ) in vec4 Normal;
layout( location = 2 ) in vec2 TexCoord;

out vec4 normal;
out vec2 texCoord;
uniform mat4 ProjectionViewModel;


void main()
 {
	normal = Normal;
	texCoord = TexCoord;
	gl_Position = ProjectionViewModel * Position;
 }