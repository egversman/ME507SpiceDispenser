/** @file SpicySort.cpp
 *  This file is used to process user input data into a sorted SpicyLinkedList.
 *  The input data is given as an 8x2 array and sorted based on the current 
 *  index of the carousel.
 */
#include "SpicySort.h"

float input[8][2];
uint8_t startIdx;
SpicyLinkedList sortedOutput;

/** @brief   SpicySort class creates an object from a user input array and the 
 *           current index of the carousel. The sort() function is used to sort
 *           the input data.
 *  @details This class is used to sort the user input data. The data can be 
 *           sorted into a SpicyLinkedList using the functions within. The
 *           resulting sorted list will only move in one direction, clockwise
 *           or counterclockwise and will be in the shortest such path.
 */
SpicySort::SpicySort(float input[8][2], uint8_t startIdx)
{
    for (uint8_t i = 0; i < 8; i++)
        for (uint8_t j = 0; j < 2; j++)
            this->input[i][j] = input[i][j];
    this->startIdx = startIdx;
    this->sortedOutput = SpicyLinkedList();
}

/** @brief   Implements a modified insertion sort for the Spice Dispenser data.
 *  @details This method uses an insertion sort that sorts either clockwise or
 *           counterclockwise depending on the current index of the carousel and 
 *           the closest spice index in the user input to the current carousel 
 *           index
 *  @return  A sorted SpicyLinkedList
 */
SpicyLinkedList SpicySort::sort()
{
    // Ignore any inputs that contain a zero amount
    uint8_t i = 0;
    while (input[i][1] == 0)
    {
        i++;
    }

    sortedOutput.append((uint8_t)input[i][0], input[i][1]);
    i++;

    // One at a time, insert elements from input map into output list
    //  in sorted order of based on the rotation direction of the carousel.
    if (direction(first()))     // true --> ccw rotation
    {
        for (uint8_t j = i; j < 8; j++)
        {
            if (input[j][1] != 0)
            {
                if ((uint8_t) input[j][0] == startIdx || 
                    ((uint8_t) input[j][0] > startIdx && 
                     (uint8_t) input[j][0] < sortedOutput.getHeadNode()->getSpiceId())) 
                {
                        sortedOutput.insert(0, (uint8_t) input[j][0], input[j][1]);
                        continue;
                }

                Node *curr = sortedOutput.getHeadNode();
                if ((uint8_t)input[j][0] > startIdx)
                {   
                    while (curr->getNextNode() &&
                            curr->getNextNode()->getSpiceId() < (uint8_t)input[j][0])
                    {
                        curr = curr->getNextNode();
                    }
                }
                else    // input[j][0] < startIdx
                {
                    while (curr->getNextNode() &&
                            curr->getNextNode()->getSpiceId() >= startIdx)
                    {
                        curr = curr->getNextNode();
                    }
                    while (curr->getNextNode() &&
                            curr->getNextNode()->getSpiceId() < (uint8_t)input[j][0])
                    {
                        curr = curr->getNextNode();
                    }
                }
                if (curr->getNextNode() != NULL) 
                {
                    curr->setNextNode(new Node((uint8_t)input[j][0], input[j][1], curr->getNextNode()));
                    sortedOutput.incrementSize();
                } else 
                {
                    curr->setNextNode(new Node((uint8_t) input[j][0], input[j][1]));
                    sortedOutput.incrementSize();
                }
            }
        }
    }
    else // false --> (cw rotation)
    {
        for (uint8_t j = i; j < 8; j++)
        {
            if ((uint8_t) input[j][1] != 0)
            {
                if ((uint8_t) input[j][0] == startIdx || 
                    ((uint8_t) input[j][0] < startIdx && 
                     (uint8_t) input[j][0] > sortedOutput.getHeadNode()->getSpiceId())) 
                {
                        sortedOutput.insert(0, (uint8_t) input[j][0], input[j][1]);
                        continue;
                }

                Node *curr = sortedOutput.getHeadNode();
                if ((uint8_t)input[j][0] < startIdx)
                {   
                    while (curr->getNextNode() &&
                            curr->getNextNode()->getSpiceId() > (uint8_t)input[j][0])
                    {
                        curr = curr->getNextNode();
                    }
                }
                else // input[j][0] > startIdx
                {
                    while (curr->getNextNode() &&
                            curr->getNextNode()->getSpiceId() <= startIdx)
                    {
                        curr = curr->getNextNode();
                    }
                    while (curr->getNextNode() &&
                            curr->getNextNode()->getSpiceId() > (uint8_t)input[j][0])
                    {
                        curr = curr->getNextNode();
                    }
                }
                if (curr->getNextNode() != NULL) 
                {
                    curr->setNextNode(new Node((uint8_t)input[j][0], input[j][1], curr->getNextNode()));
                    sortedOutput.incrementSize();
                } else 
                {
                    curr->setNextNode(new Node((uint8_t)input[j][0], input[j][1]));
                    sortedOutput.incrementSize();
                }
            }
        }
    }

    return sortedOutput;
}

/** @brief   Finds the spin direction of the carousel
 *  @details Determines the direction that the carousel should spin in order to
 *           take the shortest path to the closest spice in the users' input
 *           request
 *  @param   first is the integer spice index on the carousel that the carousel
 *           must travel to first.
 *  @return  A boolean representing the spin direction of the carousel. A true 
 *           return indicates counterclockwise rotation.
 */
bool SpicySort::direction(uint8_t first)
{
    // Find the direction that the carousel should move to get to it's first
    //  destination most efficiently. Counter clockwise rotation is denoted
    //  as true and clockwise as false.
    bool spinDirection = true;
    bool flag = false;
    float firstAmount = input[first][1];
    if (first == startIdx) 
    {
        flag = true;
        input[first][1] = 0;
        first = this->first();
    }

    int8_t compare = startIdx - 3;
        if ((compare > 0 && first > compare) ||
            (compare < 0 && first > compare + 7) ||
            (compare == 0 && first <= startIdx))
        {
            spinDirection = false;
        }

    if (flag) 
    {
        input[first][1] = firstAmount;
    }
    return spinDirection;
}

/** @brief   Finds the nearest spiceId in the input array to the startIdx.
 *  @return  An integer spice index that the carousel must travel to first.
 */
uint8_t SpicySort::first()
{
    uint8_t firstIdx = 8;
    uint8_t firstDist = 8;
    uint8_t inputIdx;
    uint8_t dist;

    for (uint8_t i = 0; i < 8; i++)
    {
        inputIdx = (uint8_t) input[i][0];
        if ((uint8_t) input[i][1] != 0) 
        {
            dist = abs(startIdx - inputIdx);
            if (firstDist > dist || firstDist > (8 - dist)) 
            {
                firstIdx = inputIdx;
                if (dist - 8 < dist)
                {
                    firstDist = 8 - dist;
                } else 
                {
                    firstDist = dist;
                }
            }
        }
    }

    return firstIdx;
}

