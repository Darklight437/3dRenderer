#include "FlyCamera.h"
#include "Clock.h"
#include <algorithm>
#include <glm\gtc\matrix_transform.hpp>


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
	//calculate the front vector
	vec3 front;
	front.x = cos(radians(m_yaw)) * cos(radians(m_pitch));
	front.y = sin(radians(m_pitch));
	front.z = sin(radians(m_yaw)) * cos(radians(m_pitch));

	m_front = normalize(front);

	//recalcualte the other direction vectors

	// Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	m_right = normalize(cross(m_front, vec3(0, 1, 0)));

	m_up = normalize(cross(m_right, m_front));

	m_viewMatrix = lookAt(m_position, m_position + m_front, m_up);

}


