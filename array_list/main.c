#include "array_list.h"

#include <stdio.h>


int main(void) {

    struct array_list* list = init(10);

    for (size_t i = 0; i < 10; ++i) {
        append(list, (int)i);
    }

    printf("list size: %lu\n", size(list));
    print(list);

    printf("\n");
    append(list, 10);
    printf("list size: %lu\n", size(list));
    print(list);

    remove_at(list, 4) == 0 ? printf("removed element at index 4\n") : printf("could not remove element at index 4\n");

    printf("list size: %lu\n", size(list));
    print(list);



    destruct(list);
    return 0;
}
