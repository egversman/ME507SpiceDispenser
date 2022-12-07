/** @file SpicyLinkedList.cpp
 *  This file contains a singly-linked list implementation to store all user 
 *  input data. Using a linked list to store user data makes sorting the list
 *  substantially faster.
 */

#include "SpicyLinkedList.h"

/** @brief   SpicyLinkedList class implements a singly-linked list to store and
 *           manipulate input data from the spice machine website.
 *  @details Each spice and spice amount requested by the user is stored in a 
 *           SpicyNode. Each node contains a pointer to the next node in the
 *           SpicyLinkedList. This linked list implementation makes sorting 
 *           input data from the user substantially faster. All data in this 
 *           class is private and must be accessed using the public "getter" and
 *           "setter" functions within.
 */

Node *head;
uint8_t size;

/** @brief   Default constructor for a SpicyLinkedList.
 *  @details This linked list implementation only requires one default
 *           constructor which initializes the head node of the list to NULL and
 *           the list size to zero.
 */
SpicyLinkedList::SpicyLinkedList()
{
    this->head = NULL;
    this->size = 0;
}

/**
 *  @brief  Returns the size of (number of nodes in) a SpicyLinkedList.
 *  @return The integer size of a SpicyLinkedList.
 */
uint8_t SpicyLinkedList::getSize()
{
    return this->size;
}

/**
 *  @brief   Increments the size of a linked list.
 *  @details This function should only be used when setting the next pointer of 
 *           a node in the list to a new node. The size of the list cannot be
 *           altered from the SpicyNode class, so this function must be called
 *           when creating a new node within an existing list. The append(), 
 *           insert(), pop(), and remove() methods increment or decrement the
 *           size of the list automatically, so this function should never be 
 *           in conjunction with any of those methods.
 */
void SpicyLinkedList::incrementSize()
{
    this->size++;
}

/**
 *  @brief   Returns a pointer to the head node of a SpicyLinkedList.
 *  @return  Pointer to the head node of the list.
 */
Node *SpicyLinkedList::getHeadNode()
{
    return this->head;
}

/**
 *  @brief   Returns a pointer to the head node of a SpicyLinkedList.
 *  @param   newHead is a pointer to the new head of the list.
 */
void SpicyLinkedList::setHeadNode(Node *newHead)
{
    head = newHead;
}

/**
 *  @brief   Returns the amount of spice requested at a given location on the
 *           carousel.
 *  @param   idx An integer index of the SpicyLinkedList at which to get the
 *           spice amount from. This is not a carousel index.
 *  @return  A float type amount of a spice from the node specified.
 */
float SpicyLinkedList::getAmount(uint8_t idx)
{
    if (this->size < idx || idx < 0)
    {
        Serial.print("Index out of bounds");
        return 0;
    }
    Node *curr = this->head;
    for (uint8_t i = 0; i < idx; i++)
    {
        curr = curr->getNextNode();
    }
    return curr->getAmount();
}

/**
 *  @brief   Sets the amount of spice requested at a given location on the 
 *           carousel.
 *  @param   idx An integer index of the SpicyLinkedList at which to set the
 *           spice amount. This is not a carousel index.
 *  @param   amount holds the physical amount of the spice requested in
 *           teaspoons(?).
 */
void SpicyLinkedList::setAmount(uint8_t idx, float amount)
{
    if (this->size < idx || idx < 0)
    {
        Serial.print("Index out of bounds");
        return;
    }
    Node *curr = this->head;
    for (uint8_t i = 0; i < idx; i++)
    {
        curr = curr->getNextNode();
    }
    curr->setAmount(amount);
}

/**
 *  @brief   Appends a new Node to the end of a SpicyLinkedList.
 *  @details This function traverses the list until it has reached the last 
 *           node, and then it changes the next pointer of the last node from 
 *           NULL to a the new node specified. The size of the list is 
 *           incremented at the end.
 *  @param   spiceId the carousel index of a spice.
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
 *  @brief   Inserts a new Node at a specified index in a SpicyLinkedList.
 *  @details This function traverses the list until it has reached the node 
 *           immediately before the list index specified by the caller. Then it 
 *           changes the next pointer of that node to the new node specified, 
 *           and sets the next pointer of the new node appropriately. The size 
 *           of the list is incremented at the end.
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
        Serial.print("Index out of bounds");
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
        for (uint8_t i = 0; i < idx - 1; i++) 
        {
            curr = curr->getNextNode();
        }
        curr->setNextNode(new Node(spiceId, amount, curr->getNextNode()));
    }
    this->size++;
}

/**
 *  @brief   Removes the head Node of a SpicyLinkedList and returns a pointer to 
 *           the removed node.
 *  @details This function is called when dispensing occurs. The user input
 *           array is sorted by SpicySort and returned as a SpicyLinkedList. 
 *           Then, to fulfill the users request, pop() can be called until the
 *           sorted list is empty. Every time a node is "popped," getSpiceId()
 *           and getAmount() can be called on the removed node pointer to access
 *           and parse the request at each carousel index. The size of the list
 *           is decremented at the end.
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
 *  @brief   Removes a Node from a SpicyLinked list at a specified index.
 *  @details This function traverses the list until it reaches the node before
 *           the list index specified by the caller. Then, it changes the next 
 *           node pointer of that node to the node after the node to be removed.
 *           A pointer to the removed node is returned and the size of the list
 *           is decremented.
 *  @param   idx An integer index of the SpicyLinkedList at which to remove
 *           a Node.
 *  @return
 */
Node *SpicyLinkedList::remove(uint8_t idx)
{
    if (this->size < idx || idx < 0)
    {
        Serial.print("Index out of bounds");
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
        for (uint8_t i = 0; i < this->size - 2; i++)
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

/**
 *  @brief   This function prints a SpicyLinkedList to the console and is used
 *           only for testing purposes.
 */
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
