#include "Light.h"



Light::Light()
{
}

Light::Light(glm::mat4 lightpos, glm::vec4 lightColour, float lightstrength)
{
	m_lightTransform = lightpos;
	m_lightColour = lightColour;
	m_lightStrength = lightstrength;
}


Light::~Light()
{
}
