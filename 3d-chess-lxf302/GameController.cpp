/*

	File: GameController.cpp
	Author: Andrew Smith
	Date: March 2023
	Description: Implementation of GameController class

*/

#include"GameController.h"

/*
	GameController constructor
*/
GameController::GameController()
{
	// Init properties
	isLibraryEnabled = false;	
	isGC_Connected = false;
	
	retGAction = -1;	
	
	// Attempt to Init library
	if (glfwInit())
	{
		isLibraryEnabled = true;
	}
	else
	{
		isLibraryEnabled = false;
	}
}

/*

	Return whether GLFW libruary is enabled
	or not

*/
bool GameController::isLibEnabled()
{
	return isLibraryEnabled;
}

/*

	Method that is used to detect if 
	GameController is detected - also enables GameController

*/
bool GameController::GC_Connected()
{
	
	if (isLibEnabled() == true)
	{
	
		if (glfwJoystickPresent(GLFW_JOYSTICK_1))
		{
			isGC_Connected = true;
		}
		else
		{
			isGC_Connected = false;
		}	
	}	
	
	return isGC_Connected;
}

/*

	Method used to return Connection state of GameController

*/
bool GameController::getGC_ConnectionState()
{
	return isGC_Connected;
}

/*

	Method used to detect which button has been pressed on the Game Controller

*/
int GameController::processGameControllerAction()
{

int buttonCount;
const unsigned char *buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);

	// Check to see if any of the buttons have been released
	if (GLFW_RELEASE == buttons[RIGHT_BUTTON_DIRECTION] || GLFW_RELEASE == buttons[LEFT_BUTTON_DIRECTION] || GLFW_RELEASE == buttons[UP_BUTTON_DIRECTION] || GLFW_RELEASE == buttons[DOWN_BUTTON_DIRECTION] || GLFW_RELEASE == buttons[A_BUTTON])
	{
		retGAction = -1;
	}

	// Check to see if any of the buttons have been pressed
	if (GLFW_PRESS == buttons[RIGHT_BUTTON_DIRECTION] && retGAction == -1)
	{
		retGAction = RIGHT_BUTTON_DIRECTION;
	}
	else if (GLFW_PRESS == buttons[LEFT_BUTTON_DIRECTION] && retGAction == -1)
	{
		retGAction = LEFT_BUTTON_DIRECTION;
	}
	else if (GLFW_PRESS == buttons[UP_BUTTON_DIRECTION])
	{
		retGAction = UP_BUTTON_DIRECTION; // Up
	}
	else if (GLFW_PRESS == buttons[DOWN_BUTTON_DIRECTION])
	{
		retGAction = DOWN_BUTTON_DIRECTION; // Down
	}
	else if (GLFW_PRESS == buttons[A_BUTTON])
	{
		retGAction = A_BUTTON;
	}	
	
	return retGAction;
}





