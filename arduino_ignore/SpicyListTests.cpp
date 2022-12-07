/** @file SpicyListTests.cpp
 *  This file contains 39 test cases for SpicyLinkedList, SpicyNode, and 
 *  SpicySort. This file is used for testing process and should not be read by
 *  a microcontroller. In order to run these test cases, move this file, along 
 *  with listTestMain.cpp SpicyNode.cpp, SpicyLinkedList.cpp, SpicySort.cpp, and 
 *  all corresponding header files to a separate directory on your local 
 *  machine. All instances of uint8_t must be changed to int and uncomment the 
 *  #includes in SpicyLinkedList.h that are labeled "for testing only." Compile
 *  using g++.
 */

#include "SpicyListTests.h"

bool test01_empty()
{
    cout << "\n***************** LIST TESTS ***************************************************\n";
    cout << "\nTest 1: Testing empty lists" << endl;

    SpicyLinkedList lst;

    if (lst.size == 0)
    {
        cout << "PASS\n"
             << endl;
        return true;
    }

    cout << "FAIL: size != " + to_string(lst.size) + "\n"
         << endl;
    return false;
}

bool test02_getNextNode()
{
    cout << "Test 2: Testing getting next node in list" << endl;

    SpicyLinkedList lst;

    lst.append(0, 1.0);
    lst.append(1, 2.0);
    lst.append(2, 3.0);

    Node *curr = lst.head;
    if (curr->getNextNode()->getAmount() != 2.0)
    {
        cout << "FAIL: Amount at next != " + to_string(lst.getAmount(1)) + "\n"
             << endl;
        return false;
    }

    curr = curr->getNextNode();
    if (curr->getNextNode()->getAmount() != 3.0)
    {
        cout << "FAIL: Amount at next != " + to_string(lst.getAmount(1)) + "\n"
             << endl;
        return false;
    }

    curr = curr->getNextNode();
    if (curr->getNextNode() != NULL)
    {
        cout << "FAIL: Amount at next != " + to_string(lst.getAmount(1)) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test03_append()
{
    cout << "Test 3: Testing appending onto lists" << endl;

    SpicyLinkedList lst;

    lst.append(0, 1.0);
    lst.append(1, 2.0);

    if (lst.getAmount(0) != 1.0)
    {
        cout << "FAIL: Amount at 0 != " + to_string(lst.getAmount(0)) + "\n"
             << endl;
        return false;
    }

    if (lst.getAmount(1) != 2.0)
    {
        cout << "FAIL: Amount at 1 != " + to_string(lst.getAmount(1)) + "\n"
             << endl;
        return false;
    }

    if (lst.size != 2)
    {
        cout << "FAIL: size != " + to_string(lst.size) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test04_insert()
{
    cout << "Test 4: Testing inserting into lists" << endl;
    SpicyLinkedList lst;

    lst.insert(0, 1, 1.0);
    lst.insert(1, 2, 2.0);
    lst.insert(2, 4, 4.0);
    lst.insert(2, 3, 3.0);

    if (lst.getAmount(0) != 1.0)
    {
        cout << "FAIL: Amount at 0 != " + to_string(lst.getAmount(0)) + "\n"
             << endl;
        return false;
    }

    if (lst.getAmount(1) != 2.0)
    {

        cout << "FAIL: Amount at 1 != " + to_string(lst.getAmount(1)) + "\n"
             << endl;
        return false;
    }

    if (lst.getAmount(2) != 3.0)
    {
        cout << "FAIL: Amount at 2 != " + to_string(lst.getAmount(2)) + "\n"
             << endl;
        return false;
    }

    if (lst.getAmount(3) != 4.0)
    {
        cout << "FAIL: Amount at 3 != " + to_string(lst.getAmount(3)) + "\n"
             << endl;
        return false;
    }

    if (lst.size != 4)
    {
        cout << "FAIL: size != " + to_string(lst.size) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test05_pop()
{
    cout << "Test 5: Testing popping from lists" << endl;

    SpicyLinkedList lst;

    lst.append(0, 1.0);
    lst.append(1, 2.0);
    lst.append(2, 3.0);
    lst.append(3, 4.0);

    Node *removed = lst.pop();
    if (removed->getAmount() != 1.0)
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = lst.pop();
    if (removed->getAmount() != 2.0)
    {
        cout << "FAIL: 2nd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = lst.pop();
    if (removed->getAmount() != 3.0)
    {
        cout << "FAIL: 3rd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = lst.pop();
    if (removed->getAmount() != 4.0)
    {
        cout << "FAIL: 4th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    if (lst.getSize() != 0)
    {
        cout << "FAIL: size != " + to_string(lst.size) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test06_remove()
{
    cout << "Test 6: Testing removing from lists" << endl;

    SpicyLinkedList lst;

    lst.append(1, 2.0);
    lst.append(3, 4.0);
    lst.insert(1, 2, 3.0);
    lst.insert(0, 0, 1.0);

    Node *removed = lst.remove(2);
    if (removed->getAmount() != 3.0)
    {
        cout << "FAIL: Amount at 2 (1) != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = lst.remove(2);
    if (removed->getAmount() != 4.0)
    {
        cout << "FAIL: Amount at 2 (2) != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = lst.remove(0);
    if (removed->getAmount() != 1.0)
    {
        cout << "FAIL: Amount at 0 (3) != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = lst.remove(0);
    if (removed->getAmount() != 2.0)
    {
        cout << "FAIL: Amount at 0 (4) != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    if (lst.size != 0)
    {
        cout << "FAIL: size != " + to_string(lst.size) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test07_inserts()
{
    cout << "Test 7: Testing adding to lists" << endl;

    SpicyLinkedList lst;

    lst.insert(0, 0, 1.0);
    lst.insert(1, 1, 2.0);
    lst.insert(2, 4, 5.0);
    lst.insert(3, 5, 6.0);
    lst.insert(2, 3, 4.0);
    lst.insert(2, 2, 3.0);

    if (lst.getAmount(0) != 1.0)
    {
        cout << "FAIL: Amount at 0 != " + to_string(lst.getAmount(0)) + "\n"
             << endl;
        return false;
    }

    if (lst.getAmount(1) != 2.0)
    {
        cout << "FAIL: Amount at 1 != " + to_string(lst.getAmount(1)) + "\n"
             << endl;
        return false;
    }

    if (lst.getAmount(2) != 3.0)
    {
        cout << "FAIL: Amount at 2 != " + to_string(lst.getAmount(2)) + "\n"
             << endl;
        return false;
    }

    if (lst.getAmount(3) != 4.0)
    {
        cout << "FAIL: Amount at 3 != " + to_string(lst.getAmount(3)) + "\n"
             << endl;
        return false;
    }

    if (lst.getAmount(4) != 5.0)
    {
        cout << "FAIL: Amount at 4 != " + to_string(lst.getAmount(4)) + "\n"
             << endl;
        return false;
    }

    if (lst.getAmount(5) != 6.0)
    {
        cout << "FAIL: Amount at 5 != " + to_string(lst.getAmount(5)) + "\n"
             << endl;
        return false;
    }

    if (lst.size != 6)
    {
        cout << "FAIL: size != " + to_string(lst.size) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test08_insertRemove()
{
    cout << "Test 8: Testing inserting and removing" << endl;

    SpicyLinkedList lst;

    lst.append(0, 1.0);
    lst.append(1, 2.0);
    lst.append(2, 3.0);
    lst.append(3, 4.0);
    lst.append(4, 5.0);

    Node *removed = lst.remove(2);
    if (removed->getAmount() != 3.0)
    {
        cout << "FAIL: Amount at 2 != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = lst.remove(3);
    if (removed->getAmount() != 5.0)
    {
        cout << "FAIL: Amount at 3 != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = lst.remove(1);
    if (removed->getAmount() != 2.0)
    {
        cout << "FAIL: Amount at 1 != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = lst.remove(1);
    if (removed->getAmount() != 4.0)
    {
        cout << "FAIL: Amount at 1 != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = lst.remove(0);
    if (removed->getAmount() != 1.0)
    {
        cout << "FAIL: Amount at 00!= " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    if (lst.size != 0)
    {
        cout << "FAIL: size != " + to_string(lst.size) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test09_setAmount()
{
    cout << "Test 9: Testing setting amount in a node" << endl;

    SpicyLinkedList lst;

    lst.append(0, 1.0);
    lst.append(1, 2.0);
    lst.append(2, 3.0);
    lst.setAmount(1, 5.0);

    if (lst.getAmount(1) != 5.0)
    {
        cout << "FAIL: Amount at 0 != " + to_string(lst.getAmount(1)) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test10_sortDirectionCcw1()
{
    cout << "***************** SORT TESTS ***************************************************\n\n";
    cout << "----------------- Sort Helper Function Tests: Rotation Direction ---------------\n\n";
    cout << "Test 10: Testing rotation direction function\n";

    int startIdx = 5;
    float input[8][2];

    SpicySort sortObj = SpicySort(input, startIdx);
    bool sortDirection = sortObj.direction(7);

    if (!sortDirection)
    {
        cout << "FAIL: Sort direction should be true (ccw)\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test11_sortDirectionCcw2()
{
    cout << "Test 11: Testing rotation direction function" << endl;

    int startIdx = 6;
    float input[8][2];

    SpicySort sortObj = SpicySort(input, startIdx);
    bool sortDirection = sortObj.direction(1);

    if (!sortDirection)
    {
        cout << "FAIL: Sort direction should be true (ccw)\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test12_sortDirectionCw1()
{
    cout << "Test 12: Testing rotation direction function" << endl;

    int startIdx = 0;
    float input[8][2];

    SpicySort sortObj = SpicySort(input, startIdx);
    bool sortDirection = sortObj.direction(7);

    if (sortDirection)
    {
        cout << "FAIL: Sort direction should be false (cw)\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test13_sortDirectionCw2()
{
    cout << "Test 13: Testing rotation direction function" << endl;

    int startIdx = 5;
    float input[8][2];

    SpicySort sortObj = SpicySort(input, startIdx);
    bool sortDirection = sortObj.direction(2);

    if (sortDirection)
    {
        cout << "FAIL: Sort direction should be false (cw)\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test14_sortFirstId_1()
{
    cout << "----------------- Sort Helper Function Tests: Find First Index -----------------\n\n";
    cout << "\nTest 14: Testing function for first node in sorted list\n";

    int startIdx = 0;
    float input[8][2] = {{0, 0}, {1, 2.2}, {2, 3.3}, {3, 0}, {4, 0}, {5, 0}, 
                          {6, 7.7}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);
    int firstId = sortObj.first();

    if (firstId != 1)
    {
        cout << "FAIL: First node ID != " + to_string(firstId) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test15_sortFirstId_2()
{
    cout << "Test 15: Testing function for first node in sorted list" << endl;

    int startIdx = 5;
    float input[8][2] = {{0, 0}, {1, 2.2}, {2, 3.3}, {3, 0}, {4, 0}, {5, 0}, 
                          {6, 7.7}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);
    int firstId = sortObj.first();

    if (firstId != 6)
    {
        cout << "FAIL: First node ID != " + to_string(firstId) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test16_sortFirstId_3()
{
    cout << "Test 16: Testing function for first node in sorted list" << endl;

    int startIdx = 7;
    float input[8][2] = {{0, 0}, {1, 2.2}, {2, 3.3}, {3, 0}, {4, 0}, {5, 0}, 
                          {6, 7.7}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);
    int firstId = sortObj.first();

    if (firstId != 6)
    {
        cout << "FAIL: First node ID != " + to_string(firstId) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test17_sortBasic1()
{
    cout << "----------------- Main Sort Tests ----------------------------------------------\n\n";
    cout << "Test 17: Testing sorting input map into list" << endl;

    int startIdx = 0;
    float input[8][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 3.3}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 3)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (!sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be true (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 3.3))
    {
        cout << "FAIL: pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test18_sortBasic2()
{
    cout << "Test 18: Testing sorting input map into list" << endl;

    int startIdx = 1;
    float input[8][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 3.3}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 3)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (!sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be true (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 3.3))
    {
        cout << "FAIL: pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test19_sortBasic3()
{
    cout << "Test 19: Testing sorting input map into list" << endl;

    int startIdx = 2;
    float input[8][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 3.3}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 3)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (!sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be true (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 3.3))
    {
        cout << "FAIL: pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test20_sortBasic4()
{
    cout << "Test 20: Testing sorting input map into list" << endl;

    int startIdx = 3;
    float input[8][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 3.3}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 3)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 3.3))
    {
        cout << "FAIL: pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test21_sortBasic5()
{
    cout << "Test 21: Testing sorting input map into list" << endl;

    int startIdx = 4;
    float input[8][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 3.3}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 3)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be false (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 3.3))
    {
        cout << "FAIL: pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test22_sortBasic6()
{
    cout << "Test 22: Testing sorting input map into list" << endl;

    int startIdx = 5;
    float input[8][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 3.3}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 3)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be false (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 3.3))
    {
        cout << "FAIL: pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test23_sortBasic7()
{
    cout << "Test 23: Testing sorting input map into list" << endl;

    int startIdx = 6;
    float input[8][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 3.3}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 3)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be false (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 3.3))
    {
        cout << "FAIL: pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test24_sortBasic8()
{
    cout << "Test 24: Testing sorting input map into list" << endl;

    int startIdx = 7;
    float input[8][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 3.3}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 3)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be false (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 3.3))
    {
        cout << "FAIL: pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test25_sortBasic9()
{
    cout << "Test 25: Testing sorting input map into list" << endl;

    int startIdx = 0;
    float input[8][2] = {{0, 1.1}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 0)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 1.1))
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test26_sortBasic10()
{
    cout << "Test 26: Testing sorting input map into list" << endl;

    int startIdx = 1;
    float input[8][2] = {{0, 1.1}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 0)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (!sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be true (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 1.1))
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test27_sortBasic11()
{
    cout << "Test 27: Testing sorting input map into list" << endl;

    int startIdx = 2;
    float input[8][2] = {{0, 1.1}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 0)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (!sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be true (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 1.1))
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test28_sortBasic12()
{
    cout << "Test 28: Testing sorting input map into list" << endl;

    int startIdx = 3;
    float input[8][2] = {{0, 1.1}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 0)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (!sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be true (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 1.1))
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test29_sortBasic13()
{
    cout << "Test 29: Testing sorting input map into list" << endl;

    int startIdx = 4;
    float input[8][2] = {{0, 1.1}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);

    if (sortObj.first() != 0)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be false (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 1.1))
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test30_sortBasic14()
{
    cout << "Test 30: Testing sorting input map into list" << endl;

    int startIdx = 5;
    float input[8][2] = {{0, 1.1}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 0)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be false (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 1.1))
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test31_sortBasic15()
{
    cout << "Test 31: Testing sorting input map into list" << endl;

    int startIdx = 6;
    float input[8][2] = {{0, 1.1}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 0)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be false (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 1.1))
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test32_sortBasic16()
{
    cout << "Test 32: Testing sorting input map into list" << endl;

    int startIdx = 7;
    float input[8][2] = {{0, 1.1}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, 
                          {6, 0}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 0)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be false (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    if (sortedLst.getSize() != 1)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 1.1))
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test33_sortCcw()
{
    cout << "\nTest 33: Testing sorting input map into list\n";

    int startIdx = 0;
    float input[8][2] = {{0, 0}, {1, 2.2}, {2, 3.3}, {3, 0}, {4, 0}, {5, 0}, 
                          {6, 7.7}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);

    if (sortObj.first() != 1)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (!sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be true (ccw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    cout << "Expected:\t(1, 2.2) --> (2, 3.3) --> (6, 7.7)\nActual:  \t";
    sortedLst.print();

    if (sortedLst.getSize() != 3)
    {
        cout << "FAIL: starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 2.2))
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 3.3))
    {
        cout << "FAIL: 2nd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 7.7))
    {
        cout << "FAIL: 3rd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    if (sortedLst.getSize() != 0)
    {
        cout << "FAIL: ending size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test34_sortCw()
{
    cout << "Test 34: Testing sorting input map into list" << endl;

    int startIdx = 7;
    float input[8][2] = {{0, 0}, {1, 2.2}, {2, 3.3}, {3, 0}, {4, 0}, {5, 0}, 
                          {6, 7.7}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);

    if (sortObj.first() != 6)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be false (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    cout << "Expected:\t(6, 7.7) --> (2, 3.3) --> (1, 2.2)\nActual:  \t";
    sortedLst.print();

    if (sortedLst.getSize() != 3)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 7.7))
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 3.3))
    {
        cout << "FAIL: 2nd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 2.2))
    {
        cout << "FAIL: 3rd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    if (sortedLst.getSize() != 0)
    {
        cout << "FAIL: Ending size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test35_bigSortCcw()
{
    cout << "Test 35: Testing sorting input map into list" << endl;

    int startIdx = 5;
    float input[8][2] = {{0, 0}, {1, 2.2}, {2, 3.3}, {3, 4.4}, {0, 0}, {5, 6.6}, 
                          {6, 7.7}, {7, 8.8}};

    SpicySort sortObj = SpicySort(input, startIdx);

    if (sortObj.first() != 5)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (!sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be true (ccw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    cout << "Expected:\t(5, 6.6) --> (6, 7.7) --> (7, 8.8) --> (1, 2.2) --> (2, 3.3) --> (3, 4.4)\nActual:  \t";
    sortedLst.print();

    if (sortedLst.getSize() != 6)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 6.6))
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 7.7))
    {
        cout << "FAIL: 2nd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 8.8))
    {
        cout << "FAIL: 3rd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 2.2))
    {
        cout << "FAIL: 4th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 3.3))
    {
        cout << "FAIL: 5th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 4.4))
    {
        cout << "FAIL: 6th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    if (sortedLst.getSize() != 0)
    {
        cout << "FAIL: Ending size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test36_bigSortCw()
{
    cout << "Test 36: Testing sorting input map into list" << endl;

    int startIdx = 7;
    float input[8][2] = {{0, 0}, {1, 2.2}, {2, 3.3}, {3, 4.4}, {4, 5.5}, {5, 6.6}, 
                          {6, 7.7}, {7, 8.8}};

    SpicySort sortObj = SpicySort(input, startIdx);

    if (sortObj.first() != 7)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be false (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    cout << "Expected:\t(7, 8.8) --> (6, 7.7) --> (5, 6.6) --> (4, 5.5) --> (3, 4.4) --> (2, 3.3) --> (1, 2.2)\nActual:  \t";
    sortedLst.print();

    if (sortedLst.getSize() != 7)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 8.8))
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 7.7))
    {
        cout << "FAIL: 2nd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 6.6))
    {
        cout << "FAIL: 3rd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 5.5))
    {
        cout << "FAIL: 4th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 4.4))
    {
        cout << "FAIL: 5th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 3.3))
    {
        cout << "FAIL: 6th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 2.2))
    {
        cout << "FAIL: 7th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    if (sortedLst.getSize() != 0)
    {
        cout << "FAIL: Ending size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test37_bigSortCcw2()
{
    cout << "Test 37: Testing sorting input map into list" << endl;

    int startIdx = 0;
    float input[8][2] = {{0, 0}, {1, 2.2}, {2, 3.3}, {3, 4.4}, {4, 5.5}, {5, 6.6}, 
                          {6, 7.7}, {7, 0}};

    SpicySort sortObj = SpicySort(input, startIdx);

    if (sortObj.first() != 1)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (!sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be true (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    cout << "Expected:\t(1, 2.2) --> (2, 3.3) --> (3, 4.4) --> (4, 5.5) --> (5, 6.6) --> (6, 7.7)\nActual:  \t";
    sortedLst.print();

    if (sortedLst.getSize() != 6)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 2.2))
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 3.3))
    {
        cout << "FAIL: 2nd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 4.4))
    {
        cout << "FAIL: 3rd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 5.5))
    {
        cout << "FAIL: 4th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 6.6))
    {
        cout << "FAIL: 5th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 7.7))
    {
        cout << "FAIL: 6th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    if (sortedLst.getSize() != 0)
    {
        cout << "FAIL: Ending size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}


bool test38_bigSortCw2()
{
    cout << "Test 38: Testing sorting input map into list" << endl;

    int startIdx = 4;
    float input[8][2] = {{0, 1.1}, {1, 2.2}, {2, 3.3}, {3, 4.4}, {4, 0}, {5, 0}, 
                          {6, 7.7}, {7, 8.8}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 3)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be false (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();

    cout << "Expected:\t(3, 4.4) --> (2, 3.3) --> (1, 2.2) --> (0, 1.1) --> (7, 8.8) --> (6, 7.7)\nActual:  \t";
    sortedLst.print();

    if (sortedLst.getSize() != 6)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 4.4))
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 3.3))
    {
        cout << "FAIL: 2nd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 2.2))
    {
        cout << "FAIL: 3rd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 11.1))
    {
        cout << "FAIL: 4th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 8.8))
    {
        cout << "FAIL: 5th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 7.7))
    {
        cout << "FAIL: 6th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    if (sortedLst.getSize() != 0)
    {
        cout << "FAIL: Ending size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}

bool test39_sortTest7()
{
    cout << "Test 39: Testing sorting input map into list" << endl;

    int startIdx = 6;
    float input[8][2] = {{0, 1.1}, {1, 2.2}, {2, 3.3}, {3, 0}, {4, 5.5}, {5, 6.6}, 
                          {6, 7.7}, {7, 8.8}};

    SpicySort sortObj = SpicySort(input, startIdx);


    if (sortObj.first() != 5)
    {
        cout << "FAIL: First node ID != " + to_string(sortObj.first()) + "\n"
             << endl;
        return false;
    }

    if (sortObj.direction(sortObj.first()))
    {
        cout << "FAIL: Sort direction should be false (cw)\n"
             << endl;
        return false;
    }

    SpicyLinkedList sortedLst = sortObj.sort();
    cout << "Expected:\t(5, 6.6) --> (4, 5.5) --> (2, 3.3) --> (1, 2.2) --> (0, 1.1) --> (7, 8.8) --> (6, 7.7)\nActual:  \t";
    sortedLst.print();

    if (sortedLst.getSize() != 7)
    {
        cout << "FAIL: Starting size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    Node *removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 6.6))
    {
        cout << "FAIL: 1st pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 5.5))
    {
        cout << "FAIL: 2nd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 3.3))
    {
        cout << "FAIL: 3rd pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 2.2))
    {
        cout << "FAIL: 4th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 1.1))
    {
        cout << "FAIL: 5th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 8.8))
    {
        cout << "FAIL: 6th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    removed = sortedLst.pop();
    if (removed->getAmount() != ((float) 7.7))
    {
        cout << "FAIL: 7th pop amount != " + to_string(removed->getAmount()) + "\n"
             << endl;
        return false;
    }

    if (sortedLst.getSize() != 0)
    {
        cout << "FAIL: Ending size != " + to_string(sortedLst.getSize()) + "\n"
             << endl;
        return false;
    }

    cout << "PASS\n"
         << endl;
    return true;
}