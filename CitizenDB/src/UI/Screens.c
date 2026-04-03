//
// Created by jan on 31/03/2026.
//

#include <stdio.h>

#include "../../inc/UI/Ansi.h"
#include "../../inc/Common.h"
#include "../../inc/UI/Screens.h"

#include <string.h>
#include <time.h>

#include "../../inc/Person.h"

STATUS ScrAddPerson(void) {
	// get: first name, last name, age
	ClearScreen();

	char name[TEXT_SIZE];
	char lname[TEXT_SIZE];
	int age = 0;

	printf("%s--- NEW PERSON ---%s\n", BOLD, RESET);
	printf("First name: ");
	CoReadString(name, TEXT_SIZE, stdin);

	printf("Last name: ");
	CoReadString(lname, TEXT_SIZE, stdin);

	printf("Age: ");
	(void)scanf("%d", &age);

	// print confirmation
	printf("First name: %s\n", name);
	printf("Last name:  %s\n", lname);
	printf("Age:        %d\n", age);
	printf("\n");

	// clear buf
	CoClearBuffer();

	// confirm
	if (CoChoice(NULL) == 0) {
		// not confirmed
		printf("Cancelled.\n");
		return STATUS_ERROR;
	}

	// confirmed
	Person person;
	memset(&person, 0, sizeof(person));

	person.Id = time(0);
	strcpy(person.Firstname, name);
	strcpy(person.Lastname, lname);
	person.Age = age;

	// TODO save the created person object
	printf("Proceeding... \n");

	return STATUS_OK;
};

STATUS ScrRemovePerson(void) {
	ClearScreen();

	// TODO missing implementation
	return STATUS_UNINITIALIZED;
}

STATUS ScrAddVehicle(int personId) {
	ClearScreen();

	// TODO missing implementation
	return STATUS_UNINITIALIZED;
}

STATUS ScrRemoveVehicle(int personId) {
	ClearScreen();

	// TODO missing implementation
	return STATUS_UNINITIALIZED;
}