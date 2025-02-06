#include <stdlib.h>

struct array_list {

    size_t base_size; // We use this to increase the size of the array when full;
    size_t size;
    int *data;
};


struct array_list *init(const size_t base_size);
void destruct(struct array_list *list);

void append(struct array_list *list, int value);

int element_at(struct array_list *list, const size_t index, int *ret);

int remove_at(struct array_list *list, const size_t index);

    // Function technically not need but used to make "oop"
size_t size(const struct array_list *list);

void print(struct array_list *list);
