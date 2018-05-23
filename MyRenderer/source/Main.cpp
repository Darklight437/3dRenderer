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




	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}