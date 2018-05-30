#pragma once
#include "Camera.h"
class FlyCamera :
	public Camera
{
public:
	FlyCamera();
	~FlyCamera();

	void update(float deltaTime);
	void setspeed(float speed);

private:
	float m_speed;
	vec3 up;


};

