#include <Arduino.h>
#include "SpicyNode.h"
#include <iostream>
#include <unordered_map>
using std::cout;
using std::endl;
using std::unordered_map;

class SpicyLinkedList
{
public:
    Node *head;
    uint8_t size = 0;

    uint8_t size();
    Node *getHeadNode();
    float getAmount(uint8_t idx);
    void setAmount(uint8_t, float);
    void insert(uint8_t idx, uint8_t spiceId, float amount);
    void append(uint8_t, float);
    Node *remove(uint8_t);
    Node *pop();
    SpicyLinkedList *SpicySort(unordered_map<uint8_t, float>, uint8_t);
};