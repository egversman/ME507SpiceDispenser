#ifndef SPICY_SORT_H
#define SPICY_SORT_H

#include "SpicyLinkedList.h"

// #include <string.h>

class SpicySort
{
private:
    float input[12][2];
    uint8_t startIdx;
    SpicyLinkedList sortedOutput;

public:
    SpicySort(float input[12][2], uint8_t startIdx);
    SpicyLinkedList sort(float input[12][2], uint8_t startIdx);
    bool direction(uint8_t first);
    uint8_t first();
};

#endif