/** @file SpicyLinkedList.cpp
 *  This file contains
 */

#include <Arduino.h>
#include <PrintStream.h>
#include <taskshare.h>
#include <taskqueue.h>
#include <shares.h>
#include <constants.h>
#include <forward_list>
#include <iostream>
#include <unordered_map>

using namespace std;

/** @brief   SpicyLinkedList class implements a singly-linked list to store and
 *           manipulate input data from the spice machine website.
 *  @details
 */
class SpicyLinkedList
{
    /** @brief   Node class to represent an element of a SpicyLinkedList.
     *  @details
     */
    class Node
    {
    protected:
        uint8_t spiceId;
        float amount;
        Node *next;

    public:
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

        Node *getNextNode()
        {
            return next;
        }

        void setAmount(float newAmount)
        {
            amount = newAmount;
        }

        void setNextNode(Node *newNext)
        {
            next = newNext;
        }
    };

    Node *head;
    uint8_t size = 0;

public:
    SpicyLinkedList()
    {
        head = NULL;
    }

    void setAmount(uint8_t, float);
    void insert(uint8_t, float);
    void append(uint8_t, float);
    Node *remove(uint8_t);
    Node *pop();
    void SpicyLinkedList::SpicySort(unordered_map<uint8_t, float>, uint8_t);

    /**
     *  Returns the size of a SpicyLinkedList.
     *  @return
     */
    uint8_t size()
    {
        return size;
    }

    /**
     *  Returns a pointer to the head node of a SpicyLinkedList.
     */
    Node *getHeadNode()
    {
        return head;
    }

    /** Returns the amount of spice requested at a given location on the
     *  carousel.
     *  @param   idx represents the integer index of a spice on the carousel.
     *  @return
     */
    float getAmount(uint8_t idx)
    {
        if (this->size < idx || idx < 0)
        {
            cout << "Index out of bounds" << endl;
            return;
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
     *  @param   idx represents the integer index of a spice on the carousel.
     *  @param   amount holds the physical amount of the spice requested in
     *           teaspoons(?).
     */
    void setAmount(uint8_t idx, float amount)
    {
        if (this->size < idx || idx < 0)
        {
            cout << "Index out of bounds" << endl;
            return;
        }
        Node *curr = this->head;
        for (int i = 0; i < idx; i++)
        {
            curr = curr->getNextNode();
        }
        curr->setAmount(amount);
    }

    /** Inserts a new Node at a specified index in a SpicyLinkedList.
     *  @param   idx represents the integer index of a spice on the carousel.
     *  @param   spiceId the carousel index of a spice.
     *  @param   amount holds the physical amount of the spice requested in
     *           teaspoons(?).
     */
    void SpicyLinkedList::insert(uint8_t idx, uint8_t spiceId, float amount)
    {
        if (this->size < idx || idx < 0)
        {
            cout << "Index out of bounds" << endl;
            return;
        }

        Node *newNode = new Node(spiceId, amount);

        if (idx == 0)
        {
            this->head = newNode;
            return;
        }
        else if (idx == this->size)
        {
            Node *curr = head;
            while (curr->getNextNode() != NULL)
            {
                curr = curr->getNextNode();
            }

            curr->setNextNode(newNode);
        }
        else
        {
            Node *curr = head;
            for (uint8_t i = 0; i < idx - 1; i++)
            {
                curr = curr->getNextNode();
            }
            curr->setNextNode(newNode);
        }

        this->size++;
    }

    /**
     *  Appends a new Node to the end of a SpicyLinkedList.
     *  @param   amount holds the physical amount of the spice requested in
     *           teaspoons(?).
     */
    void SpicyLinkedList::append(uint8_t spiceId, float amount)
    {
        Node *newNode = new Node(spiceId, amount);

        if (this->size == 0)
        {
            this->head = newNode;
            return;
        }
        else
        {
            Node *curr = head;
            while (curr->getNextNode() != NULL)
            {
                curr = curr->getNextNode();
            }

            curr->setNextNode(newNode);
        }

        this->size++;
    }

    /**
     *  Removes a Node from a SpicyLinked list at a specified index.
     *  @param   idx represents the integer index of a spice on the carousel.
     *  @return
     */
    Node *SpicyLinkedList::remove(uint8_t idx)
    {
        if (this->size < idx || idx < 0)
        {
            cout << "Index out of bounds" << endl;
            return;
        }

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
            curr->setNextNode(NULL);
        }
        else
        {
            Node *curr = this->head;
            for (uint8_t i = 0; i < this->size - 2; i++)
            {
                curr = curr.getNextNode();
            }
            curr.setNextNode(curr.getNextNode().getNextNode());
        }

        this->size--;
    }

    /**
     *  Removes the head Node of a SpicyLinkedList and returns a pointer to the
     *  removed node.
     *  @return  A pointer to the removed Node, which contains the spiceId and
     *           amount.
     */
    Node *pop()
    {
        Node *removed = this.getHeadNode();
        this.getHeadNode() = this.getHeadNode().getNextNode();
        return removed;
    }

    /** @brief
     *  @details
     *  @param   input
     *  @param   startIdx
     */
    SpicyLinkedList SpicyLinkedList::SpicySort(unordered_map<uint8_t, float> inputs, uint8_t startIdx)
    {
        if (inputs.size() == 0)
        {
            return;
        }

        // new linked list to hold the output of SpicySort.
        SpicyLinkedList *sortedOutput = new SpicyLinkedList();

        // Find the nearest spiceId in the input map to the startIdx.
        // Integer, first, represents the first location the in the carousel's
        //  path
        uint8_t first = 12;

        for (uint8_t i = 0; i < inputs.size(); i++)
        {
            if (abs(startIdx - inputs[i]) < first)
            {
                first = input[i];
            }
        }

        // find the direction that the carousel should move to get to it's first
        //  destination most efficiently. Counter clockwise rotation is denoted
        //  as true and clockwise as false.
        bool sortDirection = true;
        uint8_t compare = startIdx - 6;
        if ((compare >= 0 && first > compare) ||
            (compare < 0 && first > compare + 12))
        {
            sortDirection = false;
        }

        // One at a time, insert elements from input map into output list
        //  in sorted order of based on the rotation direction of the carousel.
        if (sortDirection)
        {
            for (uint8_t i = 0; i < sizeof(input); i++)
            {
                if (sortedOutput.getHeadNode() == NULL)
                {
                    sortedOutput.append(input[i], 1)
                    break;
                }
                Node *newNode = new Node(input[i], 1, NULL);
                Node *curr = sortedOutput->head;
                if (newNode.getSpiceId() >= startIdx)
                {
                    while (curr.getNextNode.getSpiceId() > curr.getSpiceId())
                    {
                        curr = curr.getNextNode();
                    }
                    curr.setNextNode(newNode);
                }
            }
        }
        else
        {
            for (uint8_t i = 0; i < sizeof(input); i++)
            {
                if (sortedOutput.getHeadNode() == NULL)
                {
                    sortedOutput.append(input[i], 1) break;
                }
                Node *newNode = new Node(input[i], 1, NULL);
                Node *curr = sortedOutput->head;
                if (newNode.getSpiceId() >= startIdx)
                {
                    while (curr.getNextNode.getSpiceId() > curr.getSpiceId())
                    {
                        curr = curr.getNextNode();
                    }
                    curr.setNextNode(newNode);
                }
            }
        }

        return *sortedOutput;
    }
};

// void SortedInsert(uint8_t spiceId, float amount)
// {
//     Node *newNode = new Node(spiceId, amount);
//     if (this->head == NULL || this->head->getSpiceId() >= newNode.getSpiceId())
//     {
//         newNode->next = *head;
//         *head = newNode;
//         return;
//     }

//     Node *curr = this->head;
//     while (curr.getNextNode() != NULL &&
//            curr.getNextNode().getSpiceId() < newNode.getSpiceId())
//         curr = curr->next;

//     newNode.getNextNode() = curr.getNextNode();
//     curr.getNextNode() = newNode;
// }

