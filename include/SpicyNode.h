#include <Arduino.h>

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