#pragma once
#include <glm\glm.hpp>

class Light
{
public:
	Light();
	~Light();

private:
	glm::vec4 lightColour;
	glm::mat4 loghtTransform;
	float lightStrength;
};

