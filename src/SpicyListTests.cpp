#include <Arduino.h>
#include <SpicyLinkedList.cpp>
#include <iostream>
#include <string>
#include <unordered_map>

class SpicyListTests
{
    bool test01_empty();
    bool test02_append();

    bool test01_empty()
    {
        cout << "Testing empty lists" << endl;

        SpicyLinkedList lst;

        if (lst.size == 0) {
            return true;
        }

        cout << "size != " + to_string(lst.size) << endl;

        return false;
    }

    bool test02_append()
    {
        cout << "Testing appending onto lists" << endl;
        
        SpicyLinkedList lst;

        lst.append(0, 1.0);
        lst.append(1, 2.0);

        if (lst.size != 2) 
        {
            cout << "size != " + to_string(lst.size) << endl;
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

        if (lst.size != 4) 
        {
            cout << "size != " + to_string(lst.size) << endl;
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
        if (removed.getAmount() != 3.0) 
        {
            cout << "1st pop amount != " + to_string(removed.getAmount()) << endl;
            return false;
        }

        Node *removed = lst.pop();
        if (removed.getAmount() != 3.0) 
        {
            cout << "2nd pop amount != " + to_string(removed.getAmount()) << endl;
            return false;
        }

        Node *removed = lst.pop();
        if (removed.getAmount() != 3.0) 
        {
            cout << "3rd pop amount != " + to_string(removed.getAmount()) << endl;
            return false;
        }

        Node *removed = lst.pop();
        if (removed.getAmount() != 3.0) 
        {
            cout << "4th pop amount != " + to_string(removed.getAmount()) << endl;
            return false;
        }

        if (lst.size != 0) 
        {
            cout << "size != " + to_string(lst.size) << endl;
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
        if (removed.getAmount() != 3.0) 
        {
            cout << "Amount at 2 != " + to_string(removed.getAmount()) << endl;
            return false;
        }

        Node *removed = lst.remove(2);
        if (removed.getAmount() != 3.0) 
        {
            cout << "Amount at 2 != " + to_string(removed.getAmount()) << endl;
            return false;
        }

        Node *removed = lst.remove(0);
        if (removed.getAmount() != 3.0) 
        {
            cout << "Amount at 0 != " + to_string(removed.getAmount()) << endl;
            return false;
        }

        Node *removed = lst.remove(0);
        if (removed.getAmount() != 3.0) 
        {
            cout << "Amount at 0 != " + to_string(removed.getAmount()) << endl;
            return false;
        }

        if (lst.size != 0) 
        {
            cout << "size != " + to_string(lst.size) << endl;
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

        if (lst.size != 4) 
        {
            cout << "size != " + to_string(lst.size) << endl;
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
        if (removed.getAmount() != 3.0) 
        {
            cout << "Amount at 2 != " + to_string(removed.getAmount()) << endl;
            return false;
        }

        Node *removed = lst.remove(3);
        if (removed.getAmount() != 5.0) 
        {
            cout << "Amount at 3 != " + to_string(removed.getAmount()) << endl;
            return false;
        }

        Node *removed = lst.remove(1);
        if (removed.getAmount() != 2.0) 
        {
            cout << "Amount at 1 != " + to_string(removed.getAmount()) << endl;
            return false;
        }

        Node *removed = lst.remove(1);
        if (removed.getAmount() != 4.0) 
        {
            cout << "Amount at 1 != " + to_string(removed.getAmount()) << endl;
            return false;
        }

        Node *removed = lst.remove(0);
        if (removed.getAmount() != 1.0) 
        {
            cout << "Amount at 00!= " + to_string(removed.getAmount()) << endl;
            return false;
        }

        if (lst.size != 0) 
        {
            cout << "size != " + to_string(lst.size) << endl;
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
};

// methods
// exceptions
