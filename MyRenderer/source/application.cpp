#include "application.h"
#include <glfw\glfw3.h>
#include <glad\glad.h>
#include <AIEutilities\Gizmos.h>
#include <glm\glm.hpp>
#include <glm\ext.hpp>

MyWindow myWindow;

application::application()
{
}


application::~application()
{
}

bool application::run()
{

	glClearColor(0.25f, 0.25f, 0.25f, 1);
	
	while (glfwWindowShouldClose(p_myWindow) == false &&
		glfwGetKey(p_myWindow, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		// our game logic and update code goes here!
		// so does our render code!

		











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
