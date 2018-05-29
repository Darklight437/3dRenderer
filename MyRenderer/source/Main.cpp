#include<glad\glad.h>
#define GLFW_INCLUDE_NONE
#include<glfw\glfw3.h>
#include "MyWindow.h"


int main()
{
	MyWindow windowHandler;
	

	//code!
	
	//windowHandler.start(1280, 720, "Hella Sick Graphics");
	GLFWwindow* window = windowHandler.getWindowptr();

	

	

	
	//render loop
	while (glfwWindowShouldClose(window) == false &&
		glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		// our game logic and update code goes here!
		// so does our render code!











		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}






	windowHandler.destroyWindow();
	glfwTerminate();
	return 0;
}