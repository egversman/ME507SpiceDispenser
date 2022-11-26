#include <Arduino.h>
#include "SpicyLinkedList.h"
#include "SpicyNode.h"
#include <iostream>
#include <unordered_map>

bool direction()
{
}

/** @brief
 *  @details
 *  @param   input
 *  @param   startIdx
 */
SpicyLinkedList *SpicySort(unordered_map<uint8_t, float> input, uint8_t startIdx)
{
    if (input.size() == 0)
    {
        return;
    }

    // new linked list to hold the output of SpicySort.
    SpicyLinkedList *sortedOutput = new SpicyLinkedList();

    // Find the nearest spiceId in the input map to the startIdx.
    // Integer, first, represents the first location the in the carousel's
    //  path
    uint8_t first = 12;

    for (uint8_t i = 0; i < input.size(); i++)
    {
        if (abs(startIdx - input[i]) < first)
        {
            first = input[i];
        }
    }

    // Find the direction that the carousel should move to get to it's first
    //  destination most efficiently. Counter clockwise rotation is denoted
    //  as true and clockwise as false.
    bool spinDirection = true;
    uint8_t compare = startIdx - 6;
    if ((compare >= 0 && first > compare) ||
        (compare < 0 && first > compare + 12))
    {
        spinDirection = false;
    }

    // One at a time, insert elements from input map into output list
    //  in sorted order of based on the rotation direction of the carousel.
    if (spinDirection) // spinDirection == true (ccw rotation)
    {
        for (uint8_t i = 0; i < sizeof(input); i++)
        {
            if (sortedOutput->getHeadNode() == NULL)
            {
                sortedOutput->append(input[i], 1);
                break;
            }

            Node *newNode = new Node(input[i], 1, NULL);
            Node *curr = sortedOutput->head;
            if (newNode->getSpiceId() >= startIdx)
            {
                while (curr->getNextNode()->getSpiceId() > curr->getSpiceId())
                {
                    curr = curr->getNextNode();
                }
            }
            else // newNode.getSpiceId() < startIdx
            {
                while (curr->getNextNode()->getSpiceId() > curr->getSpiceId())
                {
                    curr = curr->getNextNode();
                }
                while (curr->getNextNode()->getSpiceId() < curr->getSpiceId())
                {
                    curr = curr->getNextNode();
                }
            }
            curr->setNextNode(newNode);
        }
    }
    else // spinDirection == false (cw rotation)
    {
        for (uint8_t i = 0; i < sizeof(input); i++)
        {
            if (sortedOutput->getHeadNode() == NULL)
            {
                sortedOutput->append(input[i], 1);
                break;
            }

            Node *newNode = new Node(input[i], 1, NULL);
            Node *curr = sortedOutput->head;
            if (newNode->getSpiceId() <= startIdx)
            {
                while (curr->getNextNode()->getSpiceId() < curr->getSpiceId())
                {
                    curr = curr->getNextNode();
                }
            }
            else // newNode.getSpiceId() > startIdx
            {
                while (curr->getNextNode()->getSpiceId() < curr->getSpiceId())
                {
                    curr = curr->getNextNode();
                }
                while (curr->getNextNode()->getSpiceId() > curr->getSpiceId())
                {
                    curr = curr->getNextNode();
                }
            }
            curr->setNextNode(newNode);
        }
    }

    return sortedOutput;
}