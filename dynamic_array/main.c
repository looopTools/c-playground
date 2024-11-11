#include "dynamic_arr.h"

#include <stdio.h>

#include <assert.h>

int main(void) {

    struct dynamic_arr* arr = dynamic_arr_create(10);

    assert(arr->size == 0);
    assert(arr->capacity == 10);

    for (int i = 0; i < 10; ++i) {
        dynamic_arr_add(arr, i);
    }

    assert(arr->size == 10);
    assert(arr->capacity == 10);

    printf("[");

    int val;
    for (int i = 0; i < 9; ++i) {

        assert(dynamic_arr_at(arr, i, &val) == 0);

        printf("%d, ", val);
    }

    assert(dynamic_arr_at(arr, 9, &val) == 0);

    printf("%d]", val);


    dynamic_arr_add(arr, 10);

    assert(arr->size == 11);
    assert(arr->capacity == 20);

}
