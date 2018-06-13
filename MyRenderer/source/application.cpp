#include "application.h"
#include <glfw\glfw3.h>
#include <glad\glad.h>
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include <Windows.h>
#include <iostream>



using glm::vec3;
using glm::vec4;
using glm::mat4;

MyWindow myWindow;

application::application()
{
}


application::~application()
{
}

bool application::run()
{
	//initialising stuff
	glClearColor(0.22f, 0.22f, 0.22f, 1);
	glEnable(GL_DEPTH_TEST); // enables the depth buffer

	

	//frameloop
	while (glfwWindowShouldClose(p_myWindow) == false &&
		glfwGetKey(p_myWindow, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		//clear stuff at the start of rendering
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		aie::Gizmos::clear();

		//update the matrix
		
		
		
		

		//bind the shader
		m_shader.bind();

		//bind the transform (this handles the position of everything
		auto pvm = m_Camera.getProjectionView() * m_CRASHTransform;
		m_shader.bindUniform("ProjectionViewModel", pvm);


		//create a grid 
		
		vec4 white(1);
		vec4 black(0, 0, 0, 1);


		for (int i = 0; i < 21; ++i) {
			aie::Gizmos::addLine(vec3(-10 + i, 0, 10),
				vec3(-10 + i, 0, -10),
				i == 10 ? white : black);
			aie::Gizmos::addLine(vec3(10, 0, -10 + i),
				vec3(-10, 0, -10 + i),
				i == 10 ? white : black);
		}
		


		aie::Gizmos::draw(m_Camera.getProjectionView());

		//draw quad
		
		m_CRASH.draw();

		


		glfwSwapBuffers(p_myWindow);
		glfwPollEvents();
	}


	aie::Gizmos::destroy();
	windowhandler.destroyWindow();
	glfwTerminate();
	return false;
}

bool application::start(int sizeX, int sizeY, std::string windowName)
{
//create window
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

	if (!myWindow.createWindow(sizeX, sizeY, windowName))
	{
		std::cout << "window failed to create \n";
		return false;
	}
	
	
	p_myWindow = myWindow.getWindowptr();
	aie::Gizmos::create(10000, 10000, 10000, 10000);
//camera
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

	
	m_viewMatrix = glm::lookAt(vec3(10), vec3(0), vec3(0, 1, 0));
	

	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f,
		16.0f / 9.0f,0.1f, 1000.f);

//loading shaders
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


	//load vertex shader from file
	m_shader.loadShader(aie::eShaderStage::VERTEX, ( getExePath() + "/resources/shaders/simple.vert").c_str());

	//load fragment shader from file
	m_shader.loadShader(aie::eShaderStage::FRAGMENT, ( getExePath()+ "/resources/shaders/simple.frag").c_str());

	if (m_shader.link() == false)
	{
		std::cout << "shader error" << m_shader.getLastError() << std::endl;
	}


//load a mesh
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

	if (m_CRASH.load((getExePath() + "/resources/Crash Bandicoot/crash.obj").c_str(), true, true) == false)
	{
		std::cout << "mesh load failed \n";
		return false;
	}

	m_CRASHTransform = glm::mat4(1);
	

	return false;

}

std::string application::getExePath()
{
	{
		char buffer[MAX_PATH];
		GetModuleFileName(NULL, buffer, MAX_PATH);
		char *pos;

		if (pos = strrchr(buffer, '\\'))
		{
			*pos = 0;
		}

		return buffer;
	}

}
