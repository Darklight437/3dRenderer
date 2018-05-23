

#include<glad\glad.h>
#define GLFW_INCLUDE_NONE
#include<glfw\glfw3.h>


int main()
{
	if (glfwInit() == false)
	{
		return -1;
	}
	//code!

	GLFWwindow* window = glfwCreateWindow(1280, 720, "hella sick graphics", nullptr, nullptr);
	if (true)
	{

	}
	
	if (window == nullptr)
	{
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}

	
	//render loop
	while (glfwWindowShouldClose(window) == false &&
		glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		// our game logic and update code goes here!
		// so does our render code!











		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}






	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}