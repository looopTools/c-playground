#pragma once

#include <stdlib.h>

struct dynamic_arr {
    size_t size;
    size_t capacity;
    int* data;
};


struct dynamic_arr *dynamic_arr_create(size_t capacity);
void dynamic_arr_add(struct dynamic_arr *arr, int val);
int dynamic_arr_at(const struct dynamic_arr *arr, const size_t index, int* val);
