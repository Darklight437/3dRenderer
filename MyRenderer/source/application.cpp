#include "application.h"
#include <glfw\glfw3.h>
#include <glad\glad.h>
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include <Windows.h>
#include <iostream>
#include "input.h"


using glm::vec3;
using glm::vec4;
using glm::mat4;

MyWindow myWindow;
//callback declaration
void mouseCallback(GLFWwindow* window, double xpos, double ypos);
void framebufferSizeCallback(GLFWwindow* window, int width, int height);
application::application()
{
}


application::~application()
{
}

bool application::start(int sizeX, int sizeY, std::string windowName)
{
	//create window
	//////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////

	if (!myWindow.createWindow(sizeX, sizeY, windowName))
	{
		std::cout << "window failed to create \n";
		return false;
	}


	p_myWindow = myWindow.getWindowptr();
	aie::Gizmos::create(10000, 10000, 10000, 10000);
	//camera
	//////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////

	m_Camera.setPosition(vec3(2, 4, 2));

	



	//loading shaders
	//////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////


	//load vertex shader from file
	m_shader.loadShader(aie::eShaderStage::VERTEX, (getExePath() + "/resources/shaders/simple.vert").c_str());

	//load fragment shader from file
	m_shader.loadShader(aie::eShaderStage::FRAGMENT, (getExePath() + "/resources/shaders/simple.frag").c_str());

	if (m_shader.link() == false)
	{
		std::cout << "shader error" << m_shader.getLastError() << std::endl;
	}


	//load a mesh
	//////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////

	if (m_CRASH.load((getExePath() + "/resources/Crash Bandicoot/crash.obj").c_str(), true, true) == false)
	{
		std::cout << "mesh load failed \n";
		return false;
	}

	m_CRASHTransform = glm::mat4(1);
	m_CRASHTransform = glm::translate(m_CRASHTransform, glm::vec3(10, 0, 0));

	//new mesh
	if (m_daxter.load((getExePath() + "\\resources\\Daxter\\Daxter.obj").c_str(), true, true) == false)
	{
		std::cout << "mesh load failed \n";
		return false;
	}
	m_daxterTransform = mat4(1);
	m_daxterTransform = glm::scale(m_daxterTransform, glm::vec3(0.2, 0.2, 0.2));
	
	//create lights
	//////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////

	m_staticlight = Light(mat4(1), vec4(1), 1.0f);
	m_staticlight.setTransform(glm::translate(m_staticlight.getTransform(), vec3(0, 10, 0)));
	

	//pass window pointer to input
	//////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////

	Input::getInstance().setWindowPointer(p_myWindow);



	//createw callbacs
	//////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////

	glfwSetCursorPosCallback(p_myWindow, mouseCallback);
	glfwSetFramebufferSizeCallback(p_myWindow, framebufferSizeCallback);


	//lock cursor to screen
	glfwSetInputMode(p_myWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//store application pointer in the window to get at later
	//////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////

	glfwSetWindowUserPointer(p_myWindow, this);


	return false;
}


bool application::run()
{
	//initialising stuff
	glClearColor(0.22f, 0.22f, 0.22f, 1);
	glEnable(GL_DEPTH_TEST); // enables the depth buffer

	

	//frameloop
	while (glfwWindowShouldClose(p_myWindow) == false &&
		glfwGetKey(p_myWindow, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{
		//clear stuff at the start of rendering
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		aie::Gizmos::clear();

		update();
		
		
		
		




		//create a grid 
		
		vec4 white(1);
		vec4 black(0, 0, 0, 1);


		for (int i = 0; i < 21; ++i) {
			aie::Gizmos::addLine(vec3(-10 + i, 0, 10),
				vec3(-10 + i, 0, -10),
				i == 10 ? white : black);
			aie::Gizmos::addLine(vec3(10, 0, -10 + i),
				vec3(-10, 0, -10 + i),
				i == 10 ? white : black);
		}
		
		aie::Gizmos::addSphere(vec3(m_staticlight.getTransform()[3]), 1.0f, 10, 10, m_staticlight.getColour());

		aie::Gizmos::draw(m_Camera.getProjectionView());




		//bind the shader
		m_shader.bind();

		//bind light uniforms

			m_shader.bindUniform("lightPos", m_staticlight.getTransform()[3]);
			m_shader.bindUniform("lightColour", m_staticlight.getColour());

		
		//per model positions
		mat4 pvm = m_Camera.getProjectionView() * m_CRASHTransform;

		//
		//m_shader.bindUniform("ProjectionViewModel", pvm);
		//m_shader.bindUniform("model", m_daxterTransform);
		//m_daxter.draw();



		pvm = m_Camera.getProjectionView() * m_CRASHTransform;

		m_shader.bindUniform("ProjectionViewModel", pvm);
		m_shader.bindUniform("model", m_CRASHTransform);
		m_CRASH.draw();
		
		
		
		
		


		glfwSwapBuffers(p_myWindow);
		glfwPollEvents();
	}


	aie::Gizmos::destroy();
	windowhandler.destroyWindow();
	glfwTerminate();
	return false;
}



std::string application::getExePath()
{
	{
		char buffer[MAX_PATH];
		GetModuleFileName(NULL, buffer, MAX_PATH);
		char *pos;

		if (pos = strrchr(buffer, '\\'))
		{
			*pos = 0;
		}

		return buffer;
	}

}

void application::update()
{
	//time update
	Clock::getInstance().update();

	processInput();
	
}



void application::processInput()
{
#define INP_INST Input::getInstance()

	m_Camera.setSpeed(500.0f, 1000.0f);
	m_Camera.m_running = false;
	
	INP_INST.update();

	//exit on esc
	if (INP_INST.getDown(GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(p_myWindow, true);
	}

	//camera input settings
	//wsad controls
	{
		if (INP_INST.getHeld(GLFW_KEY_LEFT_SHIFT))
		{
			m_Camera.m_running = true;
		}

		if (INP_INST.getHeld(GLFW_KEY_W) || INP_INST.getHeld(GLFW_KEY_UP))
		{
			m_Camera.processKeyboard(FORWARD);
		}
		if (INP_INST.getHeld(GLFW_KEY_S) || INP_INST.getHeld(GLFW_KEY_DOWN))
		{
			m_Camera.processKeyboard(BACKWARD);
		}
		if (INP_INST.getHeld(GLFW_KEY_A) || INP_INST.getHeld(GLFW_KEY_LEFT))
		{
			m_Camera.processKeyboard(LEFT);
		}
		if (INP_INST.getHeld(GLFW_KEY_D) || INP_INST.getHeld(GLFW_KEY_RIGHT))
		{
			m_Camera.processKeyboard(RIGHT);
		}
		if (INP_INST.getHeld(GLFW_KEY_SPACE) || INP_INST.getHeld(GLFW_KEY_PAGE_UP))
		{
			m_Camera.processKeyboard(UPWARD);
		}
		if (INP_INST.getHeld(GLFW_KEY_LEFT_CONTROL) || INP_INST.getHeld(GLFW_KEY_PAGE_DOWN))
		{
			m_Camera.processKeyboard(DOWNWARD);
		}
	}


	

}

//runs when the mouse moves
void mouseCallback(GLFWwindow* window, double XPos, double YPos)
{	//get the application pointer out of the window
	application* app = static_cast<application*>(glfwGetWindowUserPointer(window));

	if (app->m_LastMousePos == glm::vec2(-1, -1))
	{
		app->m_LastMousePos = vec2(XPos, YPos);
	}

	
	float xoffset = (float)XPos - app->m_LastMousePos.x;
	//y position is writen from bottom to top

	float yoffset = app->m_LastMousePos.y - (float)YPos;

	app->m_LastMousePos = vec2(XPos, YPos);

	app->m_Camera.processMouseMovement(xoffset, yoffset);
}

// whenever the window is resized this callback is run
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	// resize viewport to match the new size
	glViewport(0, 0, width, height);
}

