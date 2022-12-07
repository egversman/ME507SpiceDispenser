/** @file SpicyNode.cpp
 *  This file contains a linked list node implementation. Each SpicyNode 
 *  contains the data for one element within a user input request, as well as a
 *  pointer to the next node in a SpicyLinkedList. The collection of all user 
 *  data is stored as several linked SpicyNodes in a SpicyLinkedList.
 */

#include "SpicyNode.h"

/** @brief   Node class to represent an element of a SpicyLinkedList.
 *  @details While a traditional node in a linked contains one value and a 
 *           node pointer to the next node in the list, a SpicyNode contains two
 *           values and a pointer to the next node. The first value is an
 *           integer carousel index, and the second value is a float spice 
 *           amount. All data in this class is private and must be accessed 
 *           using the public "getter" and "setter" functions within.
 */

uint8_t spiceId;
float amount;
Node *next;

/** @brief   Default constructor for a SpicyNode.
 *  @details This default constructor initializes the spiceId and amount values
 *           to zero and the next node pointer to NULL.
 */
Node::Node()
{
    this->spiceId = 0;
    this->amount = 0;
    this->next = NULL;
}

/** @brief   Overloaded, parameterized constructor for a SpicyNode.
 *  @details This constructor initializes the spiceId and amount values
 *           to the the values specified by the caller. An argument for the next 
 *           node pointer is not accepted and is set to NULL.
 */
Node::Node(uint8_t spiceId, float amount)
{
    this->spiceId = spiceId;
    this->amount = amount;
    this->next = NULL;
}

/** @brief   Overloaded, parameterized constructor for a SpicyNode.
 *  @details This constructor initializes the spiceId and amount values
 *           to the the values specified by the caller. The next node pointer is
 *           also specified by the caller and set accordingly.
 */
Node::Node(uint8_t spiceId, float amount, Node *next)
{
    this->spiceId = spiceId;
    this->amount = amount;
    this->next = next;
}

/**
 *  @brief   Returns the carousel spice index stored in a SpicyNode.
 *  @return  An integer carousel index.
 */
uint8_t Node::getSpiceId()
{
    return spiceId;
}

/**
 *  @brief   Returns the spice amount stored in a SpicyNode.
 *  @return  A float type spice amount.
 */
float Node::getAmount()
{
    return amount;
}

/**
 *  @brief   Sets the carousel spice index stored in a SpicyNode.
 *  @param   newAmount is a float type spice amount to be stored.
 */
void Node::setAmount(float newAmount)
{
    amount = newAmount;
}

/**
 *  @brief   Returns a pointer to the head node of a SpicyLinkedList.
 *  @param   newHead is a pointer to the new head of the list.
 */
Node *Node::getNextNode()
{
    return next;
}

/**
 *  @brief   Sets the next node pointer stored in a SpicyNode.
 *  @details If a new node is given as the argument to this function, the size
 *           of the corresponding SpicyLinked list must be incremented manually
 *           using the incrementSize() function in the SpicyLinkedList class.
 *  @param   newNext is a pointer to the new next node of a SpicyNode.
 */
void Node::setNextNode(Node *newNext)
{
    next = newNext;
}
