#pragma once
#include "MyWindow.h"
#include <string.h>
#include "Clock.h"
#include"AIEutilities\Gizmos.h"
#include <string>
#include "Mesh.h"


class application
{
public:
	application();
	~application();

	

	bool run();
	bool start(int sizeX, int sizeY, std::string windowName);
	std::string getExePath();

private:

	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;


	MyWindow windowhandler;
	GLFWwindow* p_myWindow;
	//aie::ShaderProgram m_shader;
	Mesh m_quadmesh;
	//glm::mat4 m_quadTransform;
	
};

