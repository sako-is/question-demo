#pragma once

#include <defines.h>

#define VECTOR_INIT_CAPACITY 6

typedef struct Vector {
    void** items;
    int capacity;
    int total;
} Vector;

Vector initVector(int capacity);

bool resizeVector(Vector* vec, int capacity);

bool vectorPush(Vector* vec, void* item);

bool vectorSet(Vector* vec, int index, void* item);

void* vectorGet(Vector* vec, int index);

bool vectorDelete(Vector* vec, int index);

bool freeVector(Vector* vec);
