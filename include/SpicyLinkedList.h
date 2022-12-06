#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <Arduino.h>
#include "SpicyNode.h"
#include <iostream>
// for testing only
// #include <string>
// #include <iomanip>
// #include <sstream>
// #include <unordered_map>
// using std::cout;
// using std::endl;
// using std::unordered_map;
// 

class SpicyLinkedList
{
// public:     // public for testing only
private:
    Node *head;
    int size;

public:
    SpicyLinkedList();
    uint8_t getSize();
    void incrementSize();
    Node *getHeadNode();
    void setHeadNode(Node *newHead);
    float getAmount(uint8_t idx);
    void setAmount(uint8_t idx, float amount);
    void append(uint8_t spiceId, float amount);
    void insert(uint8_t idx, uint8_t spiceId, float amount);
    Node *pop();
    Node *remove(uint8_t idx);
    // for testing only
    // void print();
    // 
};


#endif