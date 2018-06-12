// a simple flat colour shader
#version 410

in vec4 normal;
in vec2 texCoord;
out vec4 FragColour;


uniform sampler2D Kd;


void main()
 {
	FragColour = texture(Kd, texCoord);
 }
