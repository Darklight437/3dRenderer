#include "Camera.h"
#include <glm\gtc\matrix_transform.hpp>


Camera::Camera()
{
	


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


mat4 Camera::getView()
{
	return m_viewMatrix;
}

mat4 Camera::getProjection()
{
	return m_projectionMatrix;
}

mat4 Camera::getProjectionView()
{
	return m_projectionViewMatrix;
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
}
