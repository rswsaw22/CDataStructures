#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include "vector.h"

#define DEFAULT_SIZE 8
#define STRUCT_SIZE 1
#define INDEX_START 0

struct vec_t {
    void *_array;
    size_t dataSize;
    unsigned int size;
    unsigned int indexLocation;
};

struct vec_t *Vector(size_t elemSize, unsigned int size) {
    if (size == 0) {
        size = DEFAULT_SIZE;
    }
    void *arr = calloc((size_t)size, elemSize);
    assert(arr);

    struct vec_t *newVec = (struct vec_t*)malloc(STRUCT_SIZE * sizeof(struct vec_t));
    assert(newVec);
    newVec->_array = arr;
    newVec->dataSize = elemSize;
    newVec->size = size;
    newVec->indexLocation = INDEX_START;

    return newVec;
}

struct vec_t *VectorDefault(size_t elemSize) {
    void *arr = calloc((size_t)DEFAULT_SIZE, elemSize);
    assert(arr);

    struct vec_t *newVec = (struct vec_t*)malloc(STRUCT_SIZE * sizeof(struct vec_t));
    assert(newVec);
    newVec->_array = arr;
    newVec->dataSize = elemSize;
    newVec->size = DEFAULT_SIZE;
    newVec->indexLocation = INDEX_START;

    return newVec;
}

void PushBack(void *element, struct vec_t *vector) {
    assert(vector);

    if (vector->indexLocation == vector->size) {
        // Vector needs to grow
        vector->_array = realloc(vector->_array, (vector->size * 2));
        vector->size = vector->size * 2;
    }

    memcpy((vector->_array + (vector->indexLocation * vector->dataSize)), element, vector->dataSize);
    vector->indexLocation++;
}

void *At(unsigned int index, struct vec_t *vector) {
    assert(vector);
    assert(index < vector->size);

    uint8_t *element;
    element = ((uint8_t *)vector->_array) + (index * vector->dataSize);
    return (void *)element;
}

unsigned int Size(struct vec_t *vector) {
    return vector->size;
}

void Swap(struct vec_t *vector1, struct vec_t *vector2) {
    assert(vector1);
    assert(vector2);
    
    size_t vecSize = sizeof(struct vec_t);

    struct vec_t *tempStruct = (struct vec_t*)malloc(STRUCT_SIZE * vecSize);
    memcpy(tempStruct, vector1, vecSize);
    memcpy(vector1, vector2, vecSize);
    memcpy(vector2, tempStruct, vecSize);

    free(tempStruct);
}

void DestroyVector(struct vec_t *vector) {
    free(vector->_array);
    free((void *)vector);
}