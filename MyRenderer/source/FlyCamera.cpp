#include "FlyCamera.h"
#include "Clock.h"
#include <algorithm>

FlyCamera::FlyCamera()
{
	updateViewMatrix();
	updateProjectionMatrix();
	updateProjectionViewMatrix();


}


FlyCamera::~FlyCamera()
{
}

void FlyCamera::setPosition(const glm::vec3 position)
{
	m_position = position;

	updateViewMatrix();
	updateProjectionViewMatrix();
}

void FlyCamera::processKeyboard(Camera_Movement direction)
{
	float velocity = (m_running ? m_fastSpeed : m_moveSpeed) * Clock::getInstance().deltaTime();

	switch (direction)
	{
	case FORWARD:
		m_position += m_front * velocity;
		break;
	case BACKWARD:
		m_position -= m_front * velocity;
		break;
	case LEFT:
		m_position -= m_right * velocity;
		break;
	case RIGHT:
		m_position += m_right * velocity;
		break;
	default:
		break;
	}

	updateViewMatrix();
	updateProjectionViewMatrix();
}

void FlyCamera::processMouseMovement(float xoffset, float yoffset)
{
	xoffset *= m_lookSensitivity;
	yoffset *= m_lookSensitivity;

	m_pitch += yoffset;
	m_yaw += xoffset;

	m_pitch = std::min(89.0f, m_pitch);
}

void FlyCamera::updateViewMatrix()
{
}


