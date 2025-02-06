#include "array_list.h"

#include <string.h>
#include <stdio.h>

struct array_list *init(const size_t base_size) {

    struct array_list* list = (struct array_list*)malloc(sizeof(struct array_list));
    list->base_size = base_size;
    list->size = 0;
    list->data = (int*)malloc(sizeof(int) * base_size);
    return list;
}

void destruct(struct array_list* list) {
    free(list->data);
    free(list);
}

void append(struct array_list *list, int value) {

    if (list->size != 0 && list->size % list->base_size) {
        int* tmp = (int *)malloc(sizeof(int) * (list->size + list->base_size));
        memcpy(tmp, list->data, sizeof(int) * list->size);
        free(list->data);
        list->data = tmp;
    }

    list->data[list->size] = value;
    list->size = list->size + 1;
}

int element_at(struct array_list* list, const size_t index, int* ret){

    if (list->size <= index) {
        return -1;
    }

    *ret = list->data[index];
    return 0;
}

int remove_at(struct array_list *list, const size_t index) {

    if (list->size <= index) {
        return -1;
    }

    if (index != list->size - 1) {
        memcpy(list->data + index, list->data + index + 1, sizeof(int)*(list->size - index));
    }

    list->data[list->size - 1] = 0; // Tecchnically not necessary but I like the cleaness
    list->size = list->size -1;

    return 0;
}


size_t size(const struct array_list *list) {
    return list->size;
}

int empty(struct array_list* list) {
    return list->size == 0;
}
void print(struct array_list* list) {

    printf("[");
    if (!empty(list)) {
        int val;
        element_at(list, 0, &val);
        printf("%d", val);

        for (size_t i = 1; i < size(list); ++i) {
            element_at(list, i, &val);
            printf(", %d", val);
        }
    }

    printf("]\n");
}
