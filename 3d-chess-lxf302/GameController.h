#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

/*

	File: GameController.h
	Author: Andrew Smith
	Date: March 2023
	Description: A class for adding Game Controller support to C++ program that has no GameController support
					implementation
	Notes: Tested with XBox One Controller (PC-Compatable)	

*/

#include <GLFW/glfw3.h>

#define LEFT_BUTTON_DIRECTION 14
#define RIGHT_BUTTON_DIRECTION 12
#define UP_BUTTON_DIRECTION 11
#define DOWN_BUTTON_DIRECTION 13

#define A_BUTTON 0
#define X_BUTTON 2

class GameController
{
private:
	// Private Memebers
	
	// State check members
	bool isLibraryEnabled;	
	bool isGC_Connected;

	int retGAction; // By default no action taken
public:
	// Constructor
	GameController();
	
	// Used to setup buttons, axis, hats, etc...
	bool setupGC_Credentials();
	
	// Identifies if libruary is enabled 
	bool isLibEnabled();	
	
	// Checks to see if Game Controller is connected
	bool GC_Connected();
	
	// Gets the connection state of GameController (Connected or Disconnected)
	bool getGC_ConnectionState();
	
	// Process the actions from the Game Controller
	int processGameControllerAction();
};

#endif
