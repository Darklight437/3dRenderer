#pragma once
#include "MyWindow.h"
#include <string.h>
#include "Clock.h"
#include"AIEutilities\Gizmos.h"
#include "OBJMesh.h"
#include "Shader.h"
#include <string>
#include "Mesh.h"
#include "glm\glm.hpp"
#include "FlyCamera.h"


class application
{
public:
	application();
	~application();

	

	bool run();
	bool start(int sizeX, int sizeY, std::string windowName);
	std::string getExePath();
	//updates time and handles repeating tasks such as input
	void update();

	glm::vec2 m_LastMousePos = glm::vec2(0);
	FlyCamera m_Camera;
private:

	void processInput();


	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;


	MyWindow windowhandler;
	GLFWwindow* p_myWindow = nullptr;
	aie::ShaderProgram m_shader;
	aie::OBJMesh m_CRASH;
	aie::OBJMesh m_box;

	glm::mat4 m_CRASHTransform;
	glm::mat4 m_boxTransform;
	//Mesh m_quadmesh;
	glm::mat4 m_quadTransform;
	
	
	
	
};

