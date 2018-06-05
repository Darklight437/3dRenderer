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
	float getWindowWidth() { return m_width; }
	float getWindowheight() { return m_height; }

private:
	GLFWwindow* mainWindow = nullptr;
	float m_width = 0.0f;
	float m_height = 0;
	 
};

