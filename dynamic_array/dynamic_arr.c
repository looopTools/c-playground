#include "dynamic_arr.h"
#include <string.h>

struct dynamic_arr *dynamic_arr_create(size_t capacity) {


    struct dynamic_arr* arr = malloc(sizeof(struct dynamic_arr));
    arr->size = 0;
    arr->capacity = capacity;
    arr->data = calloc(capacity, sizeof(int));
    return arr;
}

void dynamic_arr_add(struct dynamic_arr *arr, int val) {

    if (arr->capacity == arr->size)
    {
        arr->capacity = arr->capacity * 2;
        int* data = calloc(arr->capacity, sizeof(int));

        memmove(data, arr->data, sizeof(int) * arr->size);
        free(arr->data);
        arr->data = data;
    }

    arr->data[arr->size] = val;

    arr->size = arr->size + 1;
}

int dynamic_arr_at(const struct dynamic_arr *arr, const size_t index, int *val) {

    if (index >= arr->size) {
        return -1;
    }

    *val = arr->data[index];
    return 0;



}
