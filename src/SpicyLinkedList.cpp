/** @file SpicyLinkedList.cpp
 *  This file contains
 */

#include "SpicyLinkedList.h"
using std::cout;
using std::endl;
using std::unordered_map;

/** @brief   SpicyLinkedList class implements a singly-linked list to store and
 *           manipulate input data from the spice machine website.
 *  @details
 */
class SpicyLinkedList
{
public:
    Node *head;       // public only while testing, protected otherwise
    uint8_t size = 0; // public only while testing, protected otherwise

    SpicyLinkedList()
    {
        head = NULL;
    }

    /**
     *  Returns the size of (number of nodes in) a SpicyLinkedList.
     *  @return
     */
    uint8_t size()
    {
        return size;
    }

    /**
     *  Returns a pointer to the head node of a SpicyLinkedList.
     *  @return  Pointer ton head ead node
     */
    Node *getHeadNode()
    {
        return head;
    }

    /**
     *  Returns a pointer to the head node of a SpicyLinkedList.
     *  @param   newHead ton head ead node
     */
    void setHeadNode(Node *newHead)
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
     *  @param   idx An integer index of the SpicyLinkedList at which to set the
     *           spice amount.
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

    /**
     *  Inserts a new Node at a specified index in a SpicyLinkedList.
     *  @param   idx An integer index of the SpicyLinkedList at which to insert
     *           a new Node.
     *  @param   spiceId the carousel index of a spice.
     *  @param   amount holds the physical amount of the spice requested in
     *           teaspoons(?).
     */
    void insert(uint8_t idx, uint8_t spiceId, float amount)
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
    void append(uint8_t spiceId, float amount)
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
     *  @param   idx An integer index of the SpicyLinkedList at which to remove
     *           a Node.
     *  @return
     */
    Node *remove(uint8_t idx)
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
                curr = curr->getNextNode();
            }
            curr->setNextNode(curr->getNextNode()->getNextNode());
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
        Node *removed = this->getHeadNode();
        this->head = this->head->getNextNode();
        return removed;
    }

    /** @brief
     *  @details
     *  @param   input
     *  @param   startIdx
     */
    SpicyLinkedList *SpicySort(unordered_map<uint8_t, float> input,
                               uint8_t startIdx)
    {
        if (input.size() == 0)
        {
            return;
        }

        // new linked list to hold the output of SpicySort.
        SpicyLinkedList *sortedOutput = new SpicyLinkedList();

        // Find the nearest spiceId in the input map to the startIdx.
        // Integer, first, represents the first location the in the carousel's
        //  path
        uint8_t first = 12;

        for (uint8_t i = 0; i < input.size(); i++)
        {
            if (abs(startIdx - input[i]) < first)
            {
                first = input[i];
            }
        }

        // Find the direction that the carousel should move to get to it's first
        //  destination most efficiently. Counter clockwise rotation is denoted
        //  as true and clockwise as false.
        bool spinDirection = true;
        uint8_t compare = startIdx - 6;
        if ((compare >= 0 && first > compare) ||
            (compare < 0 && first > compare + 12))
        {
            spinDirection = false;
        }

        // One at a time, insert elements from input map into output list
        //  in sorted order of based on the rotation direction of the carousel.
        if (spinDirection) // spinDirection == true (ccw rotation)
        {
            for (uint8_t i = 0; i < sizeof(input); i++)
            {
                if (sortedOutput->getHeadNode() == NULL)
                {
                    sortedOutput->append(input[i], 1);
                    break;
                }

                Node *newNode = new Node(input[i], 1, NULL);
                Node *curr = sortedOutput->head;
                if (newNode->getSpiceId() >= startIdx)
                {
                    while (curr->getNextNode()->getSpiceId() > curr->getSpiceId())
                    {
                        curr = curr->getNextNode();
                    }
                }
                else // newNode.getSpiceId() < startIdx
                {
                    while (curr->getNextNode()->getSpiceId() > curr->getSpiceId())
                    {
                        curr = curr->getNextNode();
                    }
                    while (curr->getNextNode()->getSpiceId() < curr->getSpiceId())
                    {
                        curr = curr->getNextNode();
                    }
                }
                curr->setNextNode(newNode);
            }
        }
        else // spinDirection == false (cw rotation)
        {
            for (uint8_t i = 0; i < sizeof(input); i++)
            {
                if (sortedOutput->getHeadNode() == NULL)
                {
                    sortedOutput->append(input[i], 1);
                    break;
                }

                Node *newNode = new Node(input[i], 1, NULL);
                Node *curr = sortedOutput->head;
                if (newNode->getSpiceId() <= startIdx)
                {
                    while (curr->getNextNode()->getSpiceId() < curr->getSpiceId())
                    {
                        curr = curr->getNextNode();
                    }
                }
                else // newNode.getSpiceId() > startIdx
                {
                    while (curr->getNextNode()->getSpiceId() < curr->getSpiceId())
                    {
                        curr = curr->getNextNode();
                    }
                    while (curr->getNextNode()->getSpiceId() > curr->getSpiceId())
                    {
                        curr = curr->getNextNode();
                    }
                }
                curr->setNextNode(newNode);
            }
        }

        return sortedOutput;
    }
};
