// #include "SpicyLinkedList.h"
// #include <shares.h>


// class SpicySort
// {
// private:
//     unordered_map<uint8_t, float> input;
//     uint8_t startIdx;
//     SpicyLinkedList sortedOutput;

// public:
//     SpicySort(unordered_map<uint8_t, float> input, uint8_t startIdx)
//     {
//         this->input = input;
//         this->startIdx = startIdx;
//         this->sortedOutput = SpicyLinkedList();
//     }

//     /** @brief
//      *  @details
//      *  @param   input
//      *  @param   startIdx
//      */
//     SpicyLinkedList sort(unordered_map<uint8_t, float> input, uint8_t startIdx)
//     {
//         if (input.size() == 0)
//         {
//             return;
//         }

//         bool rotation_direction = direction(first());
//         spin_direction.put(rotation_direction);
//         sortedOutput.append(input[0], 1);

//         // One at a time, insert elements from input map into output list
//         //  in sorted order of based on the rotation direction of the carousel.
//         if (rotation_direction)     // true --> ccw rotation
//         {
//             for (uint8_t i = 1; i < sizeof(input); i++)
//             {   
//                 Node newNode(input[i], 1, NULL);
//                 Node* pNewNode = &newNode;
//                 Node *curr = sortedOutput.head;
//                 if (newNode.getSpiceId() >= startIdx)
//                 {
//                     while (curr->getNextNode()->getSpiceId() > curr->getSpiceId())
//                     {
//                         curr = curr->getNextNode();
//                     }
//                 }
//                 else // newNode.getSpiceId() < startIdx
//                 {
//                     while (curr->getNextNode()->getSpiceId() > curr->getSpiceId())
//                     {
//                         curr = curr->getNextNode();
//                     }
//                     while (curr->getNextNode()->getSpiceId() < curr->getSpiceId())
//                     {
//                         curr = curr->getNextNode();
//                     }
//                 }
//                 curr->setNextNode(pNewNode);
//             }
//         }
//         else    // false --> (cw rotation)
//         {
//             for (uint8_t i = 1; i < sizeof(input); i++)
//             {
//                 Node newNode(input[i], 1, NULL);
//                 Node* pNewNode = &newNode;
//                 Node *curr = sortedOutput.head;
//                 if (newNode.getSpiceId() <= startIdx)
//                 {
//                     while (curr->getNextNode()->getSpiceId() < curr->getSpiceId())
//                     {
//                         curr = curr->getNextNode();
//                     }
//                 }
//                 else // newNode.getSpiceId() > startIdx
//                 {
//                     while (curr->getNextNode()->getSpiceId() < curr->getSpiceId())
//                     {
//                         curr = curr->getNextNode();
//                     }
//                     while (curr->getNextNode()->getSpiceId() > curr->getSpiceId())
//                     {
//                         curr = curr->getNextNode();
//                     }
//                 }
//                 curr->setNextNode(pNewNode);
//             }
//         }

//         return sortedOutput;
//     }

// bool direction(uint8_t first)
//     {
//         // Find the direction that the carousel should move to get to it's first
//         //  destination most efficiently. Counter clockwise rotation is denoted
//         //  as true and clockwise as false.
//         bool spinDirection = true;
//         uint8_t compare = startIdx - 6;
//         if ((compare >= 0 && first > compare) ||
//             (compare < 0 && first > compare + 12))
//         {
//             spinDirection = false;
//         }
//         return spinDirection;
//     }

//     uint8_t first()
//     {
//         // Find the nearest spiceId in the input map to the startIdx.
//         // Integer, first, represents the first location the in the carousel's
//         //  path
//         uint8_t first = 12;

//         for (uint8_t i = 0; i < input.size(); i++)
//         {
//             if (abs(startIdx - input[i]) < first)
//             {
//                 first = input[i];
//             }
//         }
//         return first;
//     }
// };