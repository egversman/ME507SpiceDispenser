/** @file SpicyNode.h
 *  This file contains #includes and function definitions for the SpicyNode
 *  class. 
 */

#ifndef NODE_H
#define NODE_H

#include <Arduino.h>
// #include <string.h>

class Node
{
protected:
    uint8_t spiceId;
    float amount;
    Node *next;
public:
    Node();
    Node(uint8_t spiceId, float amount);
    Node(uint8_t spiceId, float amount, Node *next);
    uint8_t getSpiceId();
    float getAmount();
    void setAmount(float newAmount);
    Node *getNextNode();
    void setNextNode(Node *newNext);
};

#endif