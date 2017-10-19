#include <stdio.h>
#include "src/void.c"

typedef struct _person {
    char *name;
    unsigned int age;
} Person;

int main()
{
    clear();

    int list[10] = {1, 3, 4, 5, 9, 8, 6, 7, 2};
    printf("%d\n", bsort(list));

    bool isTrue = false;
    if (isTrue == true)
        echo("true!");
    else
        echo("false!");
    //
    Person *person = new(Person);
    person->name = stralloc("bruno");
    strcpy(person->name, "bruno");
    echo("Hello %s!", person->name);
    //
    int array[] = {1, 2, 3};
    for_each(i, array)
        printf("%d\n", array[i]);
}
