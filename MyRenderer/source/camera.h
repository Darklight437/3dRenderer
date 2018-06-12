#pragma once
#include <glm\glm.hpp>
#include "Clock.h"
using namespace glm;
class Camera
{
public:
	Camera();
	~Camera();
	virtual void update(float deltaTime) = 0;
	void setPerspective(float FOV, float aspectRatio, float nearClip, float farClip);
	void setLookAt(vec3 from, vec3 to, vec3 up);
	void setPosition(vec3 pos);
	mat4 getWorldTransform();
	mat4 getView();
	mat4 getProjection();
	mat4 getProjectionView();


protected:
	mat4 m_position = mat4(0);
	mat4 m_viewTransform = mat4(0);
	mat4 m_projectionTransform = mat4(0);
	mat4 m_projectionViewTransform = mat4(0);
	void updateProjectionViewTransform();
	void updateViewMatrix();
};

