#ifndef MEPHI_DOZEN_ARRAYLIST_H
#define MEPHI_DOZEN_ARRAYLIST_H
#include "stdlib.h"

struct Node {
    void *data;
    size_t sizeOfData;
};

struct List {
    struct Node **array;
    size_t start, counter;
    size_t max_size;
};


#endif //MEPHI_DOZEN_ARRAYLIST_H
