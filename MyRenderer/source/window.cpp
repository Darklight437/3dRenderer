#include "window.h"

#include<glad\glad.h>
#define GLFW_INCLUDE_NONE
#include<glfw\glfw3.h>



window::window()
{
}


window::~window()
{
}

bool Window::createwindow()
{
	GLFWwindow* window = glfwCreateWindow(1280, 720, "hella sick graphics", nullptr, nullptr);

}
