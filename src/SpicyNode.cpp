/** @file SpicyNode.cpp
 *  This file contains
 */

#include <Arduino.h>
#include "SpicyNode.h"

/** @brief   Node class to represent an element of a SpicyLinkedList.
 *  @details
 */
class Node
{
public:     // public for testing only 
//protected:
    uint8_t spiceId;
    float amount;
    Node *next;

//public:
    Node()
    {
        spiceId = 0;
        amount = 0;
        next = NULL;
    }

    Node(uint8_t spiceId, float amount)
    {
        this->spiceId = spiceId;
        this->amount = amount;
        next = NULL;
    }

    Node(uint8_t spiceId, float amount, Node *next)
    {
        this->spiceId = spiceId;
        this->amount = amount;
        this->next = next;
    }

    uint8_t getSpiceId()
    {
        return spiceId;
    }

    float getAmount()
    {
        return amount;
    }


    void setAmount(float newAmount)
    {
        amount = newAmount;
    }

    Node *getNextNode()
    {
        return next;
    }

    void setNextNode(Node *newNext)
    {
        next = newNext;
    }
};
