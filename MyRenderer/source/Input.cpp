#include "Input.h"



Input & Input::getInstance()
{
	static Input inst;
	return inst;
}

void Input::update()
{
	for (auto iter = m_keyStates.begin(); iter != m_keyStates.end(); iter++)
	{
		iter->second.last = iter->second.current;
		iter->second.current = glfwGetKey(m_window, iter->first);
	}

}

bool Input::getDown(int GLFWkeycode)
{
	//find a keycode in the map
	std::map<int, InputState>::iterator iter = m_keyStates.find(GLFWkeycode);

	//if the map does not exist create it
	if (iter == m_keyStates.end())
	{
		m_keyStates.insert(std::pair<int, InputState>(GLFWkeycode, InputState()));
		return false;
	}
	//return if the key was pressed this frame
	else
	{
		InputState state = iter->second;
		return (state.current && !state.last);
	}
}

bool Input::getHeld(int GLFWkeycode)
{
	auto iter = m_keyStates.find(GLFWkeycode);

	//create map if it does not exist
	if (iter == m_keyStates.end())
	{
		m_keyStates.insert(std::pair<int, InputState>(GLFWkeycode, InputState()));
		return false;
	}
	else
	{
		InputState state = iter->second;
		return (state.current);
	}

}

bool Input::getUp(int GLFWkeycode)
{
	// search for the key in the map
	auto iter = m_keyStates.find(GLFWkeycode);

	// if it does not exist create it
	if (iter == m_keyStates.end())
	{
		m_keyStates.insert(std::pair<int, InputState>(GLFWkeycode, InputState()));
		return false;
	}
	// otherwise return if the key was released this frame
	else
	{
		InputState state = iter->second;

		return (!state.current && state.last);
	}
}

Input::Input()
{
}


Input::~Input()
{
}
