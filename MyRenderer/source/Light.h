#pragma once
#include <glm\glm.hpp>

class Light
{
public:
	Light();
	Light(glm::mat4 lightpos, glm::vec4 lightColour, float lightstrength);

	~Light();
	void setStrength(float lightstrength) { m_lightStrength = lightstrength; }
	float getStrength() { return m_lightStrength; }

	void setColour(glm::vec4 lightColour) { m_lightColour = lightColour; }
	glm::vec4 getColour() { return m_lightColour; }

	void setTransform(glm::mat4 newTransform) { m_lightTransform = newTransform; }
	glm::mat4 getTransform() { return m_lightTransform; }



private:
	glm::vec4 m_lightColour;
	glm::mat4 m_lightTransform;
	float m_lightStrength;
};

