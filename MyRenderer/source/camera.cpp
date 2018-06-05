#include "Camera.h"



Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::setPerspective(float FOV, float aspectRatio, float nearClip, float farClip)
{


}

void Camera::setLookAt(vec3 from, vec3 to, vec3 up)
{
}

void Camera::setPosition(vec3 pos)
{
	
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
