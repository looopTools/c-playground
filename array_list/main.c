#include "array_list.h"

#include <stdio.h>

void add_to_out(int val, int *ret) { *ret = *ret + val; }

void multiply_by_ten(int *val) { *val = *val * 10; }

int main(void) {

    struct array_list* list = array_list_constructor(10);

    for (size_t i = 0; i < 10; ++i) {
        array_list_append(list, (int)i);
    }

    printf("list size: %lu\n", size(list));
    print(list);

    printf("\n");
    array_list_append(list, 10);
    printf("list size: %lu\n", size(list));
    print(list);

    remove_at(list, 4) == 0 ? printf("removed element at index 4\n") : printf("could not remove element at index 4\n");

    printf("list size: %lu\n", size(list));
    print(list);
    printf("\n");

    int res = 0;
    foreach(list, add_to_out, &res);

    printf("res is: %d is this correct: %s\n\n", res, res == 51 ? "yes" : "no" );

    res = 0;
    foreach_in_place(list, multiply_by_ten);
    foreach(list, add_to_out, &res);
    print(list);

    printf("res is: %d is this correct: %s\n\n", res, res == 510 ? "yes" : "no" );


    array_list_destructor(list);
    return 0;
}
