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
	m_projectionTransform = perspective(FOV, aspectRatio, nearClip, farClip);

}

void Camera::setLookAt(vec3 from, vec3 to, vec3 up)
{
	
}

void Camera::setPosition(vec3 pos)
{
	m_position = vec4(pos, 1.0f);
}

mat4 Camera::getWorldTransform()
{
	return m_worldTransform;
}

mat4 Camera::getView()
{
	return m_viewTransform;
}

mat4 Camera::getProjection()
{
	return m_projectionTransform;
}

mat4 Camera::getProjectionView()
{
	return m_projectionViewTransform;
}

void Camera::updateProjectionViewTransform()
{
}

void Camera::updateViewMatrix()
{
	//m_viewTransform = lookAt(vec3(m_position), vec3(m_viewTransform), glm::vec3(0, 1, 0));
		
}
