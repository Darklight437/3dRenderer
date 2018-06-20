#include "Camera.h"
#include <glm\gtc\matrix_transform.hpp>


Camera::Camera()
{
	updateProjectionMatrix();
	updateViewMatrix();
	updateProjectionViewMatrix();
}


Camera::~Camera()
{
}

void Camera::setPerspective(float FOV, float aspectRatio, float nearClip, float farClip)
{
	m_projectionMatrix = perspective(FOV, aspectRatio, nearClip, farClip);

}

void Camera::setLookAt(const vec3 lookAt)
{
	m_targetPosition = lookAt;
	updateViewMatrix();
	updateProjectionViewMatrix();

}

void Camera::setPosition(vec3 pos)
{
	m_position = vec4(pos, 1.0f);
	updateViewMatrix();
	updateProjectionViewMatrix();
}

void Camera::updateProjectionViewMatrix()
{
	m_projectionViewMatrix = m_projectionMatrix * m_viewMatrix;

}

void Camera::updateViewMatrix()
{
	m_viewMatrix = lookAt(vec3(m_position), vec3(m_targetPosition), glm::vec3(0, 1, 0));
		
}

void Camera::updateProjectionMatrix()
{
	m_projectionMatrix = glm::perspective(m_fieldOfView, 16.0f / 9.0f, m_nearPlane, m_farPlane);
}
