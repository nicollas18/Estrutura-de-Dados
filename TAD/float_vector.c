#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "float_vector.h"

/**************** INTERFACE PRIVADA ***************/

typedef struct float_vector{
    int capacity;
    int size;
    float *data;
} FloatVector;

bool _FloatVector_isFull(const FloatVector *vec)
{
    return vec->size == vec->capacity;
}


/**************** INTERFACE PÚBLICA ***************/


FloatVector *FloatVector_create(int capacity)
{
    FloatVector *vec;
    vec = (FloatVector*) malloc(sizeof(FloatVector));

    vec->size = 0;
    vec->capacity = capacity;
    vec->data = (float*) malloc(capacity * sizeof(float));

    return vec;
}

void FloatVector_destroy(FloatVector **vec_ref)
{
    FloatVector *vec = *vec_ref;

    free(vec->data);
    free(vec);

    *vec_ref = NULL;
}

void FloatVector_append(FloatVector *vec, float val)
{

    if(_FloatVector_isFull(vec))
    {
        fprintf(stderr, "ERROR int 'append'\n");
        fprintf(stderr, "Vector is full\n");
        exit(EXIT_FAILURE);
    }

    vec->data[vec->size] = val;
    vec->size++;
}

void FloatVector_print(const FloatVector *vec)
{

    printf("Size: %d\n", vec->size);
    printf("Capacity: %d\n", vec->capacity);

    for(int i = 0; i < vec->capacity; i++)
    {
        printf("[%d] = %.f\n", i, vec->data[i]);
    }
    
}

int FloatVector_size(const FloatVector *vec)
{
    return vec->size;
}


int FloatVector_capacity(const FloatVector *vec)
{
    return vec->capacity;
}

float FloatVector_at(const FloatVector *vec, int index)
{

    if(index < 0 || index >= vec->capacity)
    {
        fprintf(stderr, "ERROR int 'at'\n");
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vec->size);
        exit(EXIT_FAILURE);
    }

    return vec->data[index];
}


float FloatVector_get(const FloatVector *vec, int index)
{
    return vec->data[index];
}


