/** @file SpicyNode.cpp
 *  This file contains
 */

#include "SpicyNode.h"

/** @brief   Node class to represent an element of a SpicyLinkedList.
 *  @details
 */

uint8_t spiceId;
float amount;
Node *next;

Node::Node()
{
    this->spiceId = 0;
    this->amount = 0;
    this->next = NULL;
}

Node::Node(uint8_t spiceId, float amount)
{
    this->spiceId = spiceId;
    this->amount = amount;
    this->next = NULL;
}

Node::Node(uint8_t spiceId, float amount, Node *next)
{
    this->spiceId = spiceId;
    this->amount = amount;
    this->next = next;
}

uint8_t Node::getSpiceId()
{
    return spiceId;
}

float Node::getAmount()
{
    return amount;
}

void Node::setAmount(float newAmount)
{
    amount = newAmount;
}

Node *Node::getNextNode()
{
    return next;
}

void Node::setNextNode(Node *newNext)
{
    next = newNext;
}
