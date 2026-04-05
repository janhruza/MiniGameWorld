//
// Created by jan on 31/03/2026.
//

#include <stdio.h>

#include "../../inc/UI/Ansi.h"
#include "../../inc/Common.h"
#include "../../inc/LinkedList.h"
#include "../../inc/UI/Screens.h"

#include <string.h>
#include <time.h>

#include "../../inc/Person.h"
#include "../../inc/AppState.h"

STATUS ScrAddPerson(AppState *state) {
	if (state == NULL)
	{
		return STATUS_CRITICAL;
	}

	// get: first name, last name, age
	ClearScreen();

	char name[TEXT_SIZE];
	char lname[TEXT_SIZE];
	int age = 0;

	printf("%s--- NEW PERSON ---%s\n", ACCENT_BOLD, RESET);

	printf("First name: ");
	CoReadString(name, TEXT_SIZE, stdin);

	printf("Last name: ");
	CoReadString(lname, TEXT_SIZE, stdin);

	printf("Age: ");
	CoReadInt(&age);

	// print confirmation
	printf("First name: %s\n", name);
	printf("Last name:  %s\n", lname);
	printf("Age:        %d\n", age);
	printf("\n");

	// confirm
	if (CoChoice(NULL) == 0) {
		// not confirmed
		printf("Cancelled.\n");
		return STATUS_ERROR;
	}

	// confirmed
	Person* person = (Person*)malloc(sizeof(Person));
	if (person == NULL)
	{
		fprintf(stderr, "Unable to allocate memory.\n");
		return STATUS_CRITICAL;
	}

	memset(person, 0, sizeof(person));

	person->Id = time(0);
	strcpy(person->Firstname, name);
	strcpy(person->Lastname, lname);
	person->Age = age;

	Node n = {
		.data = person,
		.next = NULL
	};

	if (ListPush(&state->Persons, &n, sizeof(int)) != 0)
	{
		fprintf(stderr, "Unable to push the item to the list.\n");
		return STATUS_ERROR;
	}

	return STATUS_OK;
};

STATUS ScrRemovePerson(AppState* state) {
	if (state == NULL)
	{
		return STATUS_CRITICAL;
	}

	// gets the database length
	int dbLen = ListLength(&state->Persons);
	if (dbLen == 0)
	{
		fprintf(stderr, "No persons registered.\n");
		return STATUS_ERROR;
	}

	ClearScreen();

	// get name and last name, then search by Id
	char name[TEXT_SIZE], lname[TEXT_SIZE];
	int id = 0;

	ClearScreen();
	printf("%s--- REMOVE PERSON%s\n", ACCENT_BOLD, RESET);

	printf("Enter person's name: ");
	CoReadString(name, TEXT_SIZE, stdin);

	printf("Enter person's lastname: ");
	CoReadString(lname, TEXT_SIZE, stdin);

	// iterate the database
	printf("\n%s--- MATCHING PERSONS ---%s\n", ACCENT_BOLD, RESET);
	Node* ptr = state->Persons.head;
	for (int i = 0; i < dbLen; i++)
	{
		Person* p = (Person*)ptr->data;
		if (strcmp(name, p->Firstname) == 0 && strcmp(lname, p->Lastname) == 0)
		{
			printf("%4d: %-*s %-*s\n", p->Id, TEXT_SIZE, p->Firstname, TEXT_SIZE, p->Lastname);
		}

		ptr = ptr->next;
	}

	printf("\nEnter record ID: ");
	CoReadInt(&id);

	if (id <= 0)
	{
		fprintf(stderr, "Invalid ID.\n");
		return STATUS_ERROR;
	}

	// TODO icomplete implementation

	// remove the record from the database
	ptr = state->Persons.head;
	while (ptr != NULL)
	{
		Person* p = (Person*)ptr->data;
		if (p == NULL)
		{
			// no data
			ptr = ptr->next;
			continue;
		}

		if (p->Id == id)
		{
			// free the memory
			free(p);
			ptr->data = NULL;
			return STATUS_OK;
		}

		ptr = ptr->next;
	}

	return STATUS_ERROR;
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