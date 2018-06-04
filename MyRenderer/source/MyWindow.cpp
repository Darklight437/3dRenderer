#include "Mywindow.h"
#include<glad\glad.h>




MyWindow::MyWindow()
{
}


MyWindow::~MyWindow()
{
}



bool MyWindow::createWindow(int sizeX, int sizeY, std::string windowName)
{
	if (glfwInit() == false)
	{
		return false;
	}
	
	m_width = sizeX;
	m_height = sizeY;
	mainWindow = glfwCreateWindow(sizeX, sizeY, windowName.c_str() , nullptr, nullptr);
	

	if (mainWindow == nullptr)
	{
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(mainWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return false;
	}
	else
	{
	
		return true;
	}

}

bool MyWindow::destroyWindow()
{
	glfwDestroyWindow(mainWindow);
	if (mainWindow == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

GLFWwindow* MyWindow::getWindowptr()
{
	return mainWindow;
}
