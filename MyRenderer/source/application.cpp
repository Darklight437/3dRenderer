#include "application.h"
#include <glfw\glfw3.h>
#include <glad\glad.h>

#include <glm\glm.hpp>
#include <glm\ext.hpp>


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
	glClearColor(0.988f, 0.414f, 0.007f, 1);
	glEnable(GL_DEPTH_TEST); // enables the depth buffer

	mat4 view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);


	//frameloop
	while (glfwWindowShouldClose(p_myWindow) == false &&
		glfwGetKey(p_myWindow, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		//clear stuff at the start of rendering
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		


		
		
		vec4 white(1);
		vec4 black(0, 0, 0, 1);

		


		glfwSwapBuffers(p_myWindow);
		glfwPollEvents();
	}


	
	Windowhandler.destroyWindow();
	glfwTerminate();
	return false;
}

bool application::start(int sizeX, int sizeY, std::string windowName)
{
	myWindow.createWindow(sizeX, sizeY, windowName);
	p_myWindow = myWindow.getWindowptr();
	return false;
}
