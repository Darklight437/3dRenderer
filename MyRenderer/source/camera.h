#pragma once
#include <glm\matrix.hpp>
#include <glm\vec3.hpp>
using namespace glm;
class Camera
{
public:
	Camera();
	~Camera();
	void update();
	void setPerspective();
	void setLookAt();
	void setPosition();
	void setWorldTransform();
	mat4 getView();
	mat4 getProjection();
	mat4 getProjectionView();


private:
	mat4 worldTransform = mat4(0);
	mat4 viewTransform = mat4(0);
	mat4 positionTransform = mat4(0);
	mat4 projectionViewTransform = mat4(0);
	void updateProjectionViewTransform();
};

