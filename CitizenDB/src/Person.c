//
// Created by jan on 28/03/2026.
//

#include "../inc/Person.h"

char gFirstNames[NAMES_COUNT][TEXT_SIZE] = {
    "James", "Mary", "Robert", "Patricia", "John", "Jennifer", "Michael", "Linda", "David", "Elizabeth",
    "William", "Barbara", "Richard", "Susan", "Joseph", "Jessica", "Thomas", "Sarah", "Christopher", "Karen",
    "Charles", "Lisa", "Christopher", "Nancy", "Daniel", "Betty", "Matthew", "Margaret", "Anthony", "Sandra",
    "Mark", "Ashley", "Donald", "Dorothy", "Steven", "Kimberly", "Paul", "Emily", "Andrew", "Donna",
    "Joshua", "Michelle", "Kenneth", "Carol", "Kevin", "Amanda", "Brian", "Melissa", "George", "Deborah",
    "Timothy", "Stephanie", "Ronald", "Rebecca", "Edward", "Sharon", "Jason", "Laura", "Jeffrey", "Cynthia",
    "Ryan", "Kathleen", "Jacob", "Amy", "Gary", "Angela", "Nicholas", "Shirley", "Eric", "Anna",
    "Jonathan", "Brenda", "Stephen", "Pamela", "Larry", "Nicole", "Justin", "Emma", "Scott", "Samantha",
    "Brandon", "Helen", "Benjamin", "Ashley", "Samuel", "Christine", "Gregory", "Debra", "Alexander", "Rachel",
    "Frank", "Carolyn", "Patrick", "Janet", "Raymond", "Maria", "Jack", "Heather", "Dennis", "Diane"
};

char gLastNames[NAMES_COUNT][TEXT_SIZE] = {
    "Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez",
    "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson", "Thomas", "Taylor", "Moore", "Jackson", "Martin",
    "Lee", "Perez", "Thompson", "White", "Harris", "Sanchez", "Clark", "Ramirez", "Lewis", "Robinson",
    "Walker", "Young", "Allen", "King", "Wright", "Scott", "Torres", "Nguyen", "Hill", "Flores",
    "Green", "Adams", "Nelson", "Baker", "Hall", "Rivera", "Campbell", "Mitchell", "Carter", "Roberts",
    "Gomez", "Phillips", "Evans", "Turner", "Diaz", "Parker", "Cruz", "Edwards", "Collins", "Reyes",
    "Stewart", "Morris", "Morales", "Murphy", "Cook", "Rogers", "Gutierrez", "Ortiz", "Morgan", "Cooper",
    "Peterson", "Bailey", "Reed", "Kelly", "Howard", "Ramos", "Kim", "Cox", "Ward", "Richardson",
    "Watson", "Brooks", "Chavez", "Wood", "James", "Bennett", "Gray", "Mendoza", "Ruiz", "Hughes",
    "Price", "Alvarez", "Castillo", "Sanders", "Patel", "Myers", "Long", "Ross", "Foster", "Jimenez"
};

char* RndFirstName(void) {
    return gFirstNames[rand() % NAMES_COUNT];
}
char* RndLastName(void) {
    return gLastNames[rand() % NAMES_COUNT];
}