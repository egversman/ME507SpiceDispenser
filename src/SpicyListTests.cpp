#include <Arduino.h>
#include <SpicyLinkedList.cpp>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class SpicyListTests
{
    bool test01_empty();
    bool test02_append();

    bool test01_empty()
    {
        cout << "Testing empty lists" << endl;

        SpicyLinkedList lst;

        if (lst.size() == 0) {
            return true;
        }

        cout << "size != " + to_string((int) lst.size()) << endl;

        return false;
    }

    bool test02_append()
    {
        cout << "Testing appending onto lists" << endl;
        
        SpicyLinkedList lst;

        lst.append(0, 1.0);
        lst.append(1, 2.0);

        if (lst.size() != 2) 
        {
            cout << "size != " + to_string((int) lst.size()) << endl;
            return false;
        }

        if (lst.getAmount(0) != 1.0) 
        {
            cout << "Amount at 0 != " + to_string(lst.getAmount(0)) << endl;
            return false;
        }

        if (lst.getAmount(1) != 2.0) 
        {
            cout << "Amount at 1 != " + to_string(lst.getAmount(1)) << endl;
            return false;
        }

        return true;
    }

    bool test03_insert()
    {
        cout << "Testing inserting into lists" << endl;
        
        SpicyLinkedList lst;

        lst.insert(0, 1, 1.0);
        lst.insert(1, 2, 2.0);
        lst.insert(2, 4, 4.0);
        lst.insert(2, 3, 3.0);

        if (lst.size() != 4) 
        {
            cout << "size != " + to_string((int) lst.size()) << endl;
            return false;
        }

        if (lst.getAmount(0) != 1.0) 
        {
            cout << "Amount at 0 != " + to_string(lst.getAmount(0)) << endl;
            return false;
        }

        if (lst.getAmount(1) != 2.0) 
        {

            cout << "Amount at 1 != " + to_string(lst.getAmount(1)) << endl;
            return false;
        }

        if (lst.getAmount(2) != 3.0) 
        {
            cout << "Amount at 2 != " + to_string(lst.getAmount(2)) << endl;
            return false;
        }

        if (lst.getAmount(3) != 4.0) 
        {
            cout << "Amount at 3 != " + to_string(lst.getAmount(3)) << endl;
            return false;
        }

        return true;
    }

    bool test04_pop()
    {
        cout << "Testing popping from lists" << endl;
        
        SpicyLinkedList lst;

        lst.append(0, 1.0);
        lst.append(1, 2.0);
        lst.append(2, 3.0);
        lst.append(3, 4.0);

        Node *removed = lst.pop();
        if (removed->getAmount() != 3.0) 
        {
            cout << "1st pop amount != " + to_string(removed->getAmount()) << endl;
            return false;
        }

        Node *removed = lst.pop();
        if (removed->getAmount() != 3.0) 
        {
            cout << "2nd pop amount != " + to_string(removed->getAmount()) << endl;
            return false;
        }

        Node *removed = lst.pop();
        if (removed->getAmount() != 3.0) 
        {
            cout << "3rd pop amount != " + to_string(removed->getAmount()) << endl;
            return false;
        }

        Node *removed = lst.pop();
        if (removed->getAmount() != 3.0) 
        {
            cout << "4th pop amount != " + to_string(removed->getAmount()) << endl;
            return false;
        }

        if (lst.size() != 0) 
        {
            cout << "size != " + to_string((int) lst.size()) << endl;
            return false;
        }

        return true;
    }

    bool test05_remove()
    {
        cout << "Testing removing from lists" << endl;
        
        SpicyLinkedList lst;

        lst.append(1, 2.0);
        lst.append(3, 4.0);
        lst.insert(1, 2, 3.0);
        lst.insert(0, 0, 1.0);

        Node *removed = lst.remove(2);
        if (removed->getAmount() != 3.0) 
        {
            cout << "Amount at 2 != " + to_string(removed->getAmount()) << endl;
            return false;
        }

        Node *removed = lst.remove(2);
        if (removed->getAmount() != 3.0) 
        {
            cout << "Amount at 2 != " + to_string(removed->getAmount()) << endl;
            return false;
        }

        Node *removed = lst.remove(0);
        if (removed->getAmount() != 3.0) 
        {
            cout << "Amount at 0 != " + to_string(removed->getAmount()) << endl;
            return false;
        }

        Node *removed = lst.remove(0);
        if (removed->getAmount() != 3.0) 
        {
            cout << "Amount at 0 != " + to_string(removed->getAmount()) << endl;
            return false;
        }

        if (lst.size() != 0) 
        {
            cout << "size != " + to_string((int) lst.size()) << endl;
            return false;
        }

        return true;
    }

    bool test06_inserts()
    {
        cout << "Testing adding to lists" << endl;
        
        SpicyLinkedList lst;

        lst.insert(0, 0, 1.0);
        lst.insert(1, 1, 2.0);
        lst.insert(2, 4, 4.0);
        lst.insert(3, 5, 6.0);
        lst.insert(2, 3, 4.0);
        lst.insert(2, 2, 3.0);

        if (lst.size() != 4) 
        {
            cout << "size != " + to_string((int) lst.size()) << endl;
            return false;
        }

        if (lst.getAmount(0) != 1.0) 
        {
            cout << "Amount at 0 != " + to_string(lst.getAmount(0)) << endl;
            return false;
        }

        if (lst.getAmount(1) != 2.0) 
        {
            cout << "Amount at 1 != " + to_string(lst.getAmount(1)) << endl;
            return false;
        }

        if (lst.getAmount(2) != 3.0) 
        {
            cout << "Amount at 2 != " + to_string(lst.getAmount(2)) << endl;
            return false;
        }

        if (lst.getAmount(3) != 4.0) 
        {
            cout << "Amount at 3 != " + to_string(lst.getAmount(3)) << endl;
            return false;
        }

        if (lst.getAmount(4) != 5.0) 
        {
            cout << "Amount at 4 != " + to_string(lst.getAmount(4)) << endl;
            return false;
        }

        if (lst.getAmount(5) != 6.0) 
        {
            cout << "Amount at 5 != " + to_string(lst.getAmount(5)) << endl;
            return false;
        }

        return true;
    }

    bool test06_insertRemove()
    {
        cout << "Testing inserting and removing" << endl;
        
        SpicyLinkedList lst;

        lst.append(0, 1.0);
        lst.append(1, 2.0);
        lst.append(2, 3.0);
        lst.append(3, 4.0);
        lst.append(4, 5.0);

        Node *removed = lst.remove(2);
        if (removed->getAmount() != 3.0) 
        {
            cout << "Amount at 2 != " + to_string(removed->getAmount()) << endl;
            return false;
        }

        Node *removed = lst.remove(3);
        if (removed->getAmount() != 5.0) 
        {
            cout << "Amount at 3 != " + to_string(removed->getAmount()) << endl;
            return false;
        }

        Node *removed = lst.remove(1);
        if (removed->getAmount() != 2.0) 
        {
            cout << "Amount at 1 != " + to_string(removed->getAmount()) << endl;
            return false;
        }

        Node *removed = lst.remove(1);
        if (removed->getAmount() != 4.0) 
        {
            cout << "Amount at 1 != " + to_string(removed->getAmount()) << endl;
            return false;
        }

        Node *removed = lst.remove(0);
        if (removed->getAmount() != 1.0) 
        {
            cout << "Amount at 00!= " + to_string(removed->getAmount()) << endl;
            return false;
        }

        if (lst.size() != 0) 
        {
            cout << "size != " + to_string((int) lst.size()) << endl;
            return false;
        }

        return true;
    }

    bool test07_setAmount()
    {
        cout << "Testing inserting and removing" << endl;
        
        SpicyLinkedList lst;

        lst.append(0, 1.0);
        lst.append(1, 2.0);
        lst.append(2, 3.0);
        lst.setAmount(1, 5.0);

        if (lst.getAmount(1) != 5.0) 
        {
            cout << "Amount at 0 != " + to_string(lst.getAmount(1)) << endl;
            return false;
        }

        return true;
    }

    // bool test08_sortCcw()
    // {
    //     cout << "Testing sorting input map into list" << endl;

    //     uint8_t startIdx = 0;
    //     unordered_map<int, float> input;
    //     input[6] = 7.0;
    //     input[10] = 11.0;
    //     input[1] = 2.0;
    //     input[2] = 3.0;

    //     SpicyLinkedList *sortedLst = SpicySort(input, startIdx);

    //     if (sortedLst->size() != 4) 
    //     {
    //         cout << "starting size != " + to_string(sortedLst->size()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 2.0) 
    //     {
    //         cout << "1st pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 3.0) 
    //     {
    //         cout << "2nd pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 7.0) 
    //     {
    //         cout << "3rd pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 11.0) 
    //     {
    //         cout << "4th pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     if (sortedLst->size() != 0) 
    //     {
    //         cout << "ending size != " + to_string(sortedLst->size()) << endl;
    //         return false;
    //     }
    // }

    //  bool test09_sortCw()
    // {
    //     cout << "Testing sorting input map into list" << endl;

    //     uint8_t startIdx = 7;
    //     unordered_map<int, float> input;
    //     input[6] = 7.0;
    //     input[10] = 11.0;
    //     input[1] = 2.0;
    //     input[2] = 3.0;

    //     SpicyLinkedList *sortedLst = SpicySort(input, startIdx);

    //     if (sortedLst->size() != 4) 
    //     {
    //         cout << "starting size != " + to_string(sortedLst->size()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 7.0) 
    //     {
    //         cout << "1st pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 3.0) 
    //     {
    //         cout << "2nd pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 2.0) 
    //     {
    //         cout << "3rd pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 11.0) 
    //     {
    //         cout << "4th pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     if (sortedLst->size() != 0) 
    //     {
    //         cout << "ending size != " + to_string(sortedLst->size()) << endl;
    //         return false;
    //     }
    // }

    //     bool test10_bigSortCcw()
    // {
    //     cout << "Testing sorting input map into list" << endl;

    //     uint8_t startIdx = 0;
    //     unordered_map<int, float> input;
    //     input[6] = 7.0;
    //     input[10] = 11.0;
    //     input[1] = 2.0;
    //     input[2] = 3.0;
    //     input[5] = 6.0;
    //     input[7] = 8.0;
    //     input[3] = 4.0;
    //     input[0] = 1.0;
    //     input[9] = 10.0;
    //     input[8] = 9.0;

    //     SpicyLinkedList *sortedLst = SpicySort(input, startIdx);

    //     if (sortedLst->size() != 10) 
    //     {
    //         cout << "starting size != " + to_string(sortedLst->size()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 1.0) 
    //     {
    //         cout << "1st pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 2.0) 
    //     {
    //         cout << "2nd pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 3.0) 
    //     {
    //         cout << "3rd pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 4.0) 
    //     {
    //         cout << "4th pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 6.0) 
    //     {
    //         cout << "3rd pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 7.0) 
    //     {
    //         cout << "4th pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 8.0) 
    //     {
    //         cout << "3rd pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 9.0) 
    //     {
    //         cout << "4th pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 10.0) 
    //     {
    //         cout << "3rd pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 11.0) 
    //     {
    //         cout << "4th pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     if (sortedLst->size() != 0) 
    //     {
    //         cout << "ending size != " + to_string(sortedLst->size()) << endl;
    //         return false;
    //     }
    // }

    //  bool test11_bigSortCw()
    // {
    //     cout << "Testing sorting input map into list" << endl;

    //     uint8_t startIdx = 11;
    //     unordered_map<int, float> input;
    //     input[6] = 7.0;
    //     input[10] = 11.0;
    //     input[1] = 2.0;
    //     input[2] = 3.0;
    //     input[5] = 6.0;
    //     input[7] = 8.0;
    //     input[3] = 4.0;
    //     input[9] = 10.0;
    //     input[8] = 9.0;
    //     input[4] = 5.0;

    //     SpicyLinkedList *sortedLst = SpicySort(input, startIdx);

    //     if (sortedLst->size() != 10) 
    //     {
    //         cout << "starting size != " + to_string(sortedLst->size()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 11.0) 
    //     {
    //         cout << "1st pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 10.0) 
    //     {
    //         cout << "2nd pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 9.0) 
    //     {
    //         cout << "3rd pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 8.0) 
    //     {
    //         cout << "4th pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 7.0) 
    //     {
    //         cout << "3rd pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 6.0) 
    //     {
    //         cout << "4th pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 5.0) 
    //     {
    //         cout << "3rd pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 4.0) 
    //     {
    //         cout << "4th pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();
    //     if (removed->getAmount() != 3.0) 
    //     {
    //         cout << "3rd pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     Node *removed = sortedLst->pop();3
    //     if (removed->getAmount() != 2.0) 
    //     {
    //         cout << "4th pop amount != " + to_string(removed->getAmount()) << endl;
    //         return false;
    //     }

    //     if (sortedLst->size() != 0) 
    //     {
    //         cout << "ending size != " + to_string(sortedLst->size()) << endl;
    //         return false;
    //     }
    // }
};

// methods
// exceptions
