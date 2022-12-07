/** @file SpicySort.h
 *  This file contains #includes and function definitions for the SpicySort
 *  class. 
 */

#ifndef SPICY_SORT_H
#define SPICY_SORT_H

#include "SpicyLinkedList.h"
#include <string.h>

class SpicySort
{
private:
    float input[8][2];
    uint8_t startIdx;
    SpicyLinkedList sortedOutput;

public:
    SpicySort(float input[8][2], uint8_t startIdx);
    SpicyLinkedList sort();
    bool direction(uint8_t first);
    uint8_t first();
};

#endif