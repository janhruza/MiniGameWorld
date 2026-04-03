#ifndef APPSTATE_H
#define APPSTATE_H

#include "LinkedList.h"

// save game file name
#define SAVEGAME		"data.state"

/**
* @brief Representing the program state variables.
*/
typedef struct tagAppState
{
	/**
	* @brief Representing the list of all registered persons.
	*/
	LinkedList Persons;
} AppState;

/**
* @brief Loads the state from a save state file.
* @param state Pointer to the output object.
* @return Operation result.
*/
int AppLoad(AppState *state);

/**
* @brief Saves the app state to the save file.
* @param state Target app state.
* @returns Operation result.
*/
int AppSave(AppState* state);

#endif /* APPSTATE_H */