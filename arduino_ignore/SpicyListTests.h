/** @file SpicyListTests.h
 *  This file contains #includes and function definitions for the test cases
 *  in SpicyListTests.cpp. 
 */

#ifndef LIST_TESTS_H
#define LIST_TESTS_H

//#include <Arduino.h>
#include "SpicyLinkedList.h"
#include "SpicySort.h"
using namespace std;

bool test01_empty();
bool test02_getNextNode();
bool test03_append();
bool test04_insert();
bool test05_pop();
bool test06_remove();
bool test07_inserts();
bool test08_insertRemove();
bool test09_setAmount();
bool test10_sortDirectionCcw1();
bool test11_sortDirectionCcw2();
bool test12_sortDirectionCw1();
bool test13_sortDirectionCw2();
bool test14_sortFirstId_1();
bool test15_sortFirstId_2();
bool test16_sortFirstId_3();
bool test17_sortBasic1();
bool test18_sortBasic2();
bool test19_sortBasic3();
bool test20_sortBasic4();
bool test21_sortBasic5();
bool test22_sortBasic6();
bool test23_sortBasic7();
bool test24_sortBasic8();
bool test25_sortBasic9();
bool test26_sortBasic10();
bool test27_sortBasic11();
bool test28_sortBasic12();
bool test29_sortBasic13();
bool test30_sortBasic14();
bool test31_sortBasic15();
bool test32_sortBasic16();
bool test33_sortCcw();
bool test34_sortCw();
bool test35_bigSortCcw();
bool test36_bigSortCw();
bool test37_bigSortCcw2();
bool test38_bigSortCw2();
bool test39_sortTest7();

#endif