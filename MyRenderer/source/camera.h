#pragma once
#include <glm\glm.hpp>
#include "Clock.h"

// layour & naming adapted from https://github.com/andrewthenintendrone
using namespace glm;
class Camera
{
public:
	Camera();
	~Camera();
	void setPerspective(float FOV, float aspectRatio, float nearClip, float farClip);
	void setLookAt(const vec3 lookAt);
	void setPosition(vec3 pos);
	//mat4 getWorldTransform();
	mat4 getView();
	mat4 getProjection();
	mat4 getProjectionView();


protected:

	void updateProjectionViewMatrix();
	void updateViewMatrix();
	void updateProjectionMatrix();

	vec3 m_position =vec4(0, 0, 0, 1); // position in world space
	vec3 m_targetPosition = vec3(0); // position to look at in world space


	
	mat4 m_viewMatrix = mat4(1);
	mat4 m_projectionMatrix = mat4(1);
	mat4 m_projectionViewMatrix = mat4(1);

	// projection properties
	unsigned int m_screenWidth = 1280;
	unsigned int m_screenHeight = 720;
	float m_nearPlane = 0.1f;
	float m_farPlane = 1000.0f;
	float m_fieldOfView = 90.0f;

	
};

