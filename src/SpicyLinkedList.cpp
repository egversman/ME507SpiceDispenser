/** @file SpicyLinkedList.cpp
 *  This file contains
 */

#include "SpicyLinkedList.h"

/** @brief   SpicyLinkedList class implements a singly-linked list to store and
 *           manipulate input data from the spice machine website.
 *  @details
 */

Node *head;
int size;

SpicyLinkedList::SpicyLinkedList()
{
    this->head = NULL;
    this->size = 0;
}

/**
 *  Returns the size of (number of nodes in) a SpicyLinkedList.
 *  @return
 */
uint8_t SpicyLinkedList::getSize()
{
    return this->size;
}

/**
 *  Returns the size of (number of nodes in) a SpicyLinkedList.
 *  @return
 */
void SpicyLinkedList::incrementSize()
{
    this->size++;
}

/**
 *  Returns a pointer to the head node of a SpicyLinkedList.
 *  @return  Pointer ton head ead node
 */
Node *SpicyLinkedList::getHeadNode()
{
    return this->head;
}

/**
 *  Returns a pointer to the head node of a SpicyLinkedList.
 *  @param   newHead ton head ead node
 */
void SpicyLinkedList::setHeadNode(Node *newHead)
{
    head = newHead;
}

/**
 *  Returns the amount of spice requested at a given location on the
 *  carousel.
 *  @param   idx An integer index of the SpicyLinkedList at which to get the
 *           spice amount from.
 *  @return
 */
float SpicyLinkedList::getAmount(uint8_t idx)
{
    if (this->size < idx || idx < 0)
    {
        Serial.print("Index out of bounds\n");
        return 0;
    }
    Node *curr = this->head;
    for (int i = 0; i < idx; i++)
    {
        curr = curr->getNextNode();
    }
    return curr->getAmount();
}

/**
 *  Sets the amount of spice requested at a given location on the carousel.
 *  @param   idx An integer index of the SpicyLinkedList at which to set the
 *           spice amount.
 *  @param   amount holds the physical amount of the spice requested in
 *           teaspoons(?).
 */
void SpicyLinkedList::setAmount(uint8_t idx, float amount)
{
    if (this->size < idx || idx < 0)
    {
        Serial.print("Index out of bounds\n");
        return;
    }
    Node *curr = this->head;
    for (int i = 0; i < idx; i++)
    {
        curr = curr->getNextNode();
    }
    curr->setAmount(amount);
}

/**
 *  Appends a new Node to the end of a SpicyLinkedList.
 *  @param   amount holds the physical amount of the spice requested in
 *           teaspoons(?).
 */
void SpicyLinkedList::append(uint8_t spiceId, float amount)
{
    if (this->size == 0)
    {
        this->head = new Node(spiceId, amount);
        this->size++;
        return;
    }
    else
    {
        Node *curr = head;
        while (curr->getNextNode() != NULL)
        {
            curr = curr->getNextNode();
        }

        curr->setNextNode(new Node(spiceId, amount));
    }
    this->size++;
}

/**
 *  Inserts a new Node at a specified index in a SpicyLinkedList.
 *  @param   idx An integer index of the SpicyLinkedList at which to insert
 *           a new Node.
 *  @param   spiceId the carousel index of a spice.
 *  @param   amount holds the physical amount of the spice requested in
 *           teaspoons(?).
 */
void SpicyLinkedList::insert(uint8_t idx, uint8_t spiceId, float amount)
{
    if (idx > this->size || idx < 0)
    {
        Serial.print("Index out of bounds\n");
        return;
    }

    if (idx == 0)
    {
        this->head = new Node(spiceId, amount, this->head);
        this->size++;
        return;
    }
    else if (idx == this->size)
    {
        Node *curr = head;
        while (curr->getNextNode() != NULL)
        {
            curr = curr->getNextNode();
        }
        curr->setNextNode(new Node(spiceId, amount));
    }
    else
    {
        Node *curr = head;
        for (int i = 0; i < idx - 1; i++) 
        {
            curr = curr->getNextNode();
        }
        curr->setNextNode(new Node(spiceId, amount, curr->getNextNode()));
    }
    this->size++;
}

/**
 *  Removes the head Node of a SpicyLinkedList and returns a pointer to the
 *  removed node.
 *  @return  A pointer to the removed Node, which contains the spiceId and
 *           amount.
 */
Node *SpicyLinkedList::pop()
{
    Node *removed = this->getHeadNode();
    if (removed != NULL)
    {
        this->head = this->head->getNextNode();
        this->size--;
    }
    return removed;
}

/**
 *  Removes a Node from a SpicyLinked list at a specified index.
 *  @param   idx An integer index of the SpicyLinkedList at which to remove
 *           a Node.
 *  @return
 */
Node *SpicyLinkedList::remove(uint8_t idx)
{
    if (this->size < idx || idx < 0)
    {
        Serial.print("Index out of bounds\n");
        return NULL;
    }

    Node *removed = this->getHeadNode();
    if (idx == 0)
    {
        this->head = this->head->getNextNode();
    }
    else if (idx == this->size - 1)
    {
        Node *curr = this->head;
        for (int i = 0; i < this->size - 2; i++)
        {
            curr = curr->getNextNode();
        }
        removed = curr->getNextNode();
        curr->setNextNode(NULL);
    }
    else
    {
        Node *curr = this->head;
        for (uint8_t i = 0; i < idx - 1; i++)
        {
            curr = curr->getNextNode();
        }
        removed = curr->getNextNode();
        // cout << removed->getAmount() << endl;
        curr->setNextNode(curr->getNextNode()->getNextNode());
        // cout << removed->getAmount() << endl;
    }
    this->size--;
    return removed;
}

// void SpicyLinkedList::print() 
// {
//     Node *curr = this->head;
//     for (uint8_t i = 0; i < this->size - 1; i++)
//     {
//         cout << '(' << curr->getSpiceId() << ", " << curr->getAmount() << ") --> ";
//         curr = curr->getNextNode();
//     }
//     cout << '(' << curr->getSpiceId() << ", " << curr->getAmount() << ")\n";
// }
