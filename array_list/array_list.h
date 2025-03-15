#include <stdlib.h>

typedef void (*FOREACH_IN_WITH_RESULT_FUNCTION)(int, int *);
typedef void (*FOREACH_IN_PLACE_FUNCTION)(int *);

struct array_list {

    size_t base_size; // We use this to increase the size of the array when full;
    size_t size;
    int *data;
};


struct array_list *array_list_constructor(const size_t base_size);
void array_list_destructor(struct array_list *list);

void array_list_append(struct array_list *list, int value);

int element_at(struct array_list *list, const size_t index, int *ret);

int remove_at(struct array_list *list, const size_t index);

    // Function technically not need but used to make "oop"
size_t size(const struct array_list *list);

int empty(struct array_list* list);

void print(struct array_list *list);

void foreach(struct array_list* list, FOREACH_IN_WITH_RESULT_FUNCTION function, int* ret);

void foreach_in_place(struct array_list* list, FOREACH_IN_PLACE_FUNCTION function);
