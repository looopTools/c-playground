//
// Basic hash map implementation in C
// Using Fowler–Noll–Vo hash function (fnv-1a):
//      https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
//

#include <_string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>


const uint64_t FNV_OFFSET_BASIS = 14695981039346656037ULL;
const uint64_t FNV_PRIME = 1099511628211ULL;

uint64_t fnv1_a_hash(const char *key) {


    uint64_t hash = FNV_OFFSET_BASIS;

    while(*key) {
        hash = hash ^ (unsigned char)*key; // Extract single byte from key
        hash = hash * FNV_PRIME;
        key = key + 1;
    }
    return hash;
}

int is_capacity_power_of_two(const size_t capacity)
{
    return capacity != 0 && (capacity & (capacity - 1)) == 0;
}

size_t compute_index(const char *key, const size_t capacity)
{
    const uint64_t hash = fnv1_a_hash(key);
    return is_capacity_power_of_two(capacity) ? (hash & (capacity - 1)) : hash % capacity;

}


enum  entry_state{
    EMPTY,
    EXISTS
} ;

struct entry {
    enum entry_state state;
    char* key;
    char* value;
};

struct hash_map {

    struct entry* entries;
    size_t capacity;
    size_t size;
};

struct hash_map *create_map(const size_t capacity) {
    struct hash_map* map = malloc(sizeof(struct hash_map));

    map->capacity = capacity;
    map->size = 0;
    map->entries = calloc(capacity, sizeof(struct entry));

    return map;
}

void delete_map(struct hash_map *map) {

    for (size_t i = 0; i < map->capacity; ++i) {
        if (map->entries[i].state == EXISTS) {
            free(map->entries[i].key);
            free(map->entries[i].value);
        }
    }

    free(map->entries);
    free(map);
}

int add_entry(const char *key, const char *value, struct hash_map *map) {

    const uint64_t index = compute_index(key, map->capacity);

    if (index >= map->capacity) {
        return 0;
    }

    if (map->entries[index].state == EMPTY) {
        map->size = map->size + 1;
    }

    map->entries[index].state = EXISTS;
    map->entries[index].key = strdup(key);
    map->entries[index].value = strdup(value);
    return 1;
}

int entry_exist(const char *key, const struct hash_map *map) {
    const uint64_t index = compute_index(key, map->capacity);
    return !(index >= map->capacity || map->entries[index].state == EMPTY);
}

void remove_entry(const char *key, struct hash_map *map) {

    const uint64_t index = compute_index(key, map->capacity);
    if (!(index >= map->capacity || map->entries[index].state == EMPTY)) {
        return;
    }
    map->entries[index].state = EMPTY;
    free(map->entries[index].key);
    free(map->entries[index].value);
    map->size = map->size - 1;
}

struct entry *get_entry(const char *key, const struct hash_map* map) {

    const uint64_t index = compute_index(key, map->capacity);

    if (index >= map->capacity || map->entries[index].state == EMPTY) {
        return NULL;
    }

    return &(map->entries[index]);
}

struct entry *get_entry_by_index(const size_t index, const struct hash_map *map) {

    if (index >= map->capacity || map->entries[index].state == EMPTY) {
        return NULL;
    }

    return &(map->entries[index]);

}

int main(void) {

    struct hash_map* map = create_map(1024);
    add_entry("abba", "sweeden", map);
    add_entry("tyr", "denmark", map);

    for (size_t i = 0; i < map->capacity; ++i) {

        struct entry* ent = get_entry_by_index(i, map);

        if (ent != NULL) {
            printf("%s: %s\n", ent->key, ent->value);
        }
    }

    assert(get_entry("abba", map) != NULL);
    assert(get_entry("tyr", map) != NULL);
    assert(get_entry("metallica", map) == NULL);

    remove_entry("abba", map);
    //assert(get_entry("abba", map) == NULL);
    for (size_t i = 0; i < map->capacity; ++i) {

        struct entry* ent = get_entry_by_index(i, map);

        if (ent != NULL) {
            printf("%s: %s\n", ent->key, ent->value);
        }
    }

    delete_map(map);
}
