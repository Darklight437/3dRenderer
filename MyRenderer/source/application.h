#pragma once
#include "MyWindow.h"
#include <string.h>
#include "Clock.h"
#include"AIEutilities\Gizmos.h"
#include <string>


class application
{
public:
	application();
	~application();

	

	bool run();
	bool start(int sizeX, int sizeY, std::string windowName);
	std::string getExePath();

private:
	MyWindow Windowhandler;
	GLFWwindow* p_myWindow;
	
};

