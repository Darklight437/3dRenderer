#pragma once
#include "Camera.h"
#include "glfw\glfw3.h"


enum class Camera_Movement
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};



class FlyCamera :public Camera
{
public:
	FlyCamera();
	~FlyCamera();


	bool m_running = false;


	void setPosition(const glm::vec3 position);

	void processKeyboard(Camera_Movement direction);
	void processMouseMovement(float xoffset, float yoffset);


	

private:
	float m_speed;
	vec3 up;

	void updateViewMatrix();

	vec3 m_front = vec3(0, 0, 1);
	vec3 m_right = vec3(1, 0, 0);
	vec3 m_up = vec3(0, 1, 0);



	float m_pitch = -45.0f;
	float m_yaw = -45.0f;

	float m_moveSpeed = 10.0f;
	float m_fastSpeed = 50.0f;

	float m_lookSensitivity = 0.1f;
};

