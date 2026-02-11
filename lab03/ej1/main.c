/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>
#include <stdlib.h>

/** @brief structure which represent a person */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(void) {

    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};
    
    int *pointer1 = NULL;
    person_t *pointer2 = NULL;

    pointer1 =&x;
    *pointer1 = 9;

    pointer2 = &m;
    pointer2->age = 100;
    pointer2->name_initial = 'F';

    pointer1 = &a[1];
    *pointer1 = 42;

    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return EXIT_SUCCESS;
}

