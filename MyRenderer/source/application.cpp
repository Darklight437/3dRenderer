#include "application.h"
#include <glfw\glfw3.h>
#include <glad\glad.h>

#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include <Windows.h>
#include "Shader.h"
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
	//glClearColor(0.988f, 0.414f, 0.007f, 1);
	glEnable(GL_DEPTH_TEST); // enables the depth buffer

	mat4 view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);


	//frameloop
	while (glfwWindowShouldClose(p_myWindow) == false &&
		glfwGetKey(p_myWindow, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		//clear stuff at the start of rendering
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		aie::Gizmos::clear();


		

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
		//create a disk
		aie::Gizmos::addDisk(glm::vec3(0), 20.0f, 30, glm::vec4(255, 215, 0, 1));

		aie::Gizmos::draw(projection * view);





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
	myWindow.createWindow(sizeX, sizeY, windowName);
	p_myWindow = myWindow.getWindowptr();
	aie::Gizmos::create(10000, 10000, 10000, 10000);

	m_viewMatrix = glm::lookAt(vec3(10), vec3(0), vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f,
		windowhandler.getWindowWidth() / (float)windowhandler.getWindowheight(),0.1f, 1000.f); 



	//loading shaders
	//load vertex shader from file
	shader.loadShader(aie::eShaderStage::VERTEX, getExePath().c_str + "resources/shaders/simple.vert");

	//load fragment shader from file
	shader.loadShader(aie::eShaderStage::FRAGMENT, getExePath().c_str + "resources/shaders/simple.frag");

	if (shader.link() == false)
	{
		std::cout << "shader error" << shader.getLastError() << std::endl;
	}







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
