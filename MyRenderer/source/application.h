#pragma once
#include "MyWindow.h"
#include <string.h>
#include "Clock.h"
#include"AIEutilities\Gizmos.h"

class application
{
public:
	application();
	~application();

	

	bool run();
	bool start(int sizeX, int sizeY, std::string windowName);

private:
	MyWindow Windowhandler;
	GLFWwindow* p_myWindow;
	
};

