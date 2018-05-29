#pragma once
#define GLFW_INCLUDE_NONE
#include<glfw\glfw3.h>
#include "string"


class MyWindow
{
public:
	MyWindow();
	~MyWindow();

	
	bool createWindow(int sizeX, int sizeY, std::string windowName);
	bool destroyWindow();
	GLFWwindow* getWindowptr();


private:
	GLFWwindow* mainWindow = nullptr;
};

