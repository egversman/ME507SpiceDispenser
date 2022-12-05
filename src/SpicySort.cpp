#include "SpicySort.h"

// unordered_map<int, float> input;
float input[8][2];
int startIdx;
SpicyLinkedList sortedOutput;

SpicySort::SpicySort(float input[8][2], uint8_t startIdx)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 2; j++)
            this->input[i][j] = input[i][j];
    this->startIdx = startIdx;
    this->sortedOutput = SpicyLinkedList();
}

/** @brief
 *  @details
 *  @param   input
 *  @param   startIdx
 */
SpicyLinkedList SpicySort::sort()
{
    // Remove empty "rows" of 2d input array
    int i = 0;
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
            if ((int) input[j][1] != 0)
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
            (compare < 0 && first > compare + 11) ||
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

uint8_t SpicySort::first()
{
    // Find the nearest spiceId in the input map to the startIdx.
    // Integer, first, represents the first location the in the carousel's
    //  path
    uint8_t firstIdx = 8;     // store firstIdx result
    uint8_t firstDist = 8;
    uint8_t inputIdx = 8;
    uint8_t dist = 0;

    for (uint8_t i = 0; i <= 7; i++)
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

