#pragma once
#include <map>
#include "glfw\glfw3.h"

struct InputState
{
	bool current = false; //is this key down
	bool last = false; //was this key down last frame
};


class Input
{
public:


	static Input& getInstance();

	void setWindowPointer(GLFWwindow* window) { m_window = window; }

	void update();

	bool getDown(int GLFWkeycode);
	bool getHeld(int GLFWkeycode);
	bool getUp(int GLFWkeycode);

private:


	// pointer to window
	GLFWwindow * m_window = nullptr;

	// map of keycodes and states
	std::map<int, InputState> m_keyStates;




	Input();
	~Input();
};

