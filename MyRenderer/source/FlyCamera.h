#pragma once
#include "Camera.h"
#include "glfw\glfw3.h"


enum Camera_Movement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UPWARD,
	DOWNWARD
};



class FlyCamera :public Camera
{
public:
	FlyCamera();
	~FlyCamera();


	bool m_running = false;

	void setSpeed(float normalSpeed, float fastSpeed);
	void setPosition(const glm::vec3 position);

	void processKeyboard(Camera_Movement direction);
	void processMouseMovement(float xoffset, float yoffset);


	

private:

	vec3 up;

	void updateViewMatrix();

	vec3 m_front = vec3(0, 0, 1);
	vec3 m_right = vec3(1, 0, 0);
	vec3 m_up = vec3(0, 1, 0);



	float m_pitch = -45.0f;
	float m_yaw = -45.0f;

	float m_moveSpeed = 500.0f;
	float m_fastSpeed = 800.0f;

	float m_lookSensitivity = 0.1f;
};

