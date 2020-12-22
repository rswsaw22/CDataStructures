#include <stdlib.h>
#include "vector.h"

#define DEFAULT_SIZE 8

struct vec_t {
    void *_array;
    unsigned int size;
    size_t *indexLocation;
};

struct vec_t *vector(size_t elemSize, unsigned int size) {
    if (size == 0) {
        size = DEFAULT_SIZE;
    }
    void *arr = calloc((size_t)size, elemSize);

    struct vec_t *newVec = (struct vec_t*)malloc(1 * sizeof(struct vec_t));
    newVec->_array = arr;
    newVec->size = size;
    newVec->indexLocation = &arr;

    return newVec;
}

struct vec_t *vectorDefault(size_t elemSize) {
    void *arr = calloc((size_t)DEFAULT_SIZE, elemSize);

    struct vec_t *newVec = (struct vec_t*)malloc(1 * sizeof(struct vec_t));
    newVec->_array = arr;
    newVec->size = DEFAULT_SIZE;
    newVec->indexLocation = &arr;

    return newVec;
}

void push_back(size_t element, struct vec_t *vector) {
    vector->_array[*vector->indexLocation] = element;
    vector->indexLocation++;
}

void destroyVector(struct vec_t *vector) {
    free(vector->_array);
    free((void *)vector);
    vector = NULL;
}