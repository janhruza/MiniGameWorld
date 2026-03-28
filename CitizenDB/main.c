#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "inc/UI/Ansi.h"
#include "inc/Common.h"
#include "inc/Person.h"

STATUS AppInit(void) {
    srand(time(NULL));
    ClearScreen();
    return STATUS_OK;
}

STATUS AppCleanup(void) {
    ClearScreen();
    return STATUS_OK;
}

int main(void) {

    if (AppInit() != STATUS_OK) {
        fprintf(stderr, "Initialization failed.\n");
    }

    Person p;
    memset(&p, 0, sizeof(Person));

    // firstname
    printf("Enter your first name: ");
    scanf("%s", &p.Firstname);

    // lastname
    printf("Enter your last name: ");
    scanf("%s", &p.Lastname);

    // auto-generated fields
    p.Id = time(NULL);
    p.Age = rand() % 99 + 1;
    snprintf(p.CountryCode, 4, "%s", gCountries[rand() % COUNTRIES_COUNT]);
    printf("\n");

    // print user
    printf("First name:: %s\n", p.Firstname);
    printf("Last name:   %s\n", p.Lastname);
    printf("Age:         %d\n", p.Age);
    printf("Country:     %s\n", p.CountryCode);

    getchar();

    if (AppCleanup() != STATUS_OK) {
        fprintf(stderr, "Cleanup failed.\n");
    }

    return EXIT_SUCCESS;
}
