#ifndef NODE_H
#define NODE_H

#include <Arduino.h>
// for testing only
//#include <string.h>
//

class Node
{
private:
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