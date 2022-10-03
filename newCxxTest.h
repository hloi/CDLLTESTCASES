/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newCxxTest.h
 * Author: hloi
 *
 * Created on January 26, 2018, 3:52 PM
 */

#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
//Include your classes header file(s) below and uncomment.
//#include "myClass.h"
#include "circular_list.h"
#include <iostream>
#include <ostream>
using std::cout;
using std::endl;
#include <stdexcept>

using KW::circular_list;

class newCxxTest : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testPushBack1() {
        cout << endl << "Test pushback" << endl;
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions. 
        KW::circular_list<int> list1;
        for (int i = 0; i < 20; i++) {
            list1.push_back(i);
        }
        bool pass = true;
        KW::circular_list<int>::iterator itr1 = list1.begin();
        for (int i = 0; i < 20; i++) {
            if (i != *itr1) {
                cout << i << " != list1[" << i << "] == "
                     << *itr1 << '\n';
                pass = false;
            }
            ++itr1;
        }
        if (pass) {
            cout << "push_back test passed\n";

        }
        else {
            cout << "push_back test failed\n";

        }
        TS_ASSERT(pass);

    }

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testPushFront2() {
        cout << endl << "Test pushfront " << endl;
        bool pass = true;
        KW::circular_list<int> list3;
        for (int i = 0; i < 20; i++) {
            list3.push_front(19 - i);
        }
        pass = true;
        KW::circular_list<int>::iterator itr3 = list3.begin();
        for (int i = 0; i < 20; i++) {
            if (i != *itr3) {
                cout << i << " != list3[" << i << "] == "
                     << *itr3 << '\n';
                pass = false;
            }
            ++itr3;
        }
        if (pass) {
            cout << "push_front test passed\n";
        }
        else {
            cout << "push_front test failed\n";
        }
        TS_ASSERT(pass);

    }
    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testInsert() {
        cout << endl << "Test pushInsert" << endl;
        bool pass = true;

        KW::circular_list<int> list2;
        for (int i = 0; i < 20; i += 2) {
            list2.push_back(i);
        }
        // insert every other position
        KW::circular_list<int>::iterator itr2 = list2.begin();
        for (int i = 0; i < 20; i += 2) {
            list2.insert(++itr2, i+1);
        }
        pass = true;
        itr2 = list2.begin();
        for (int i = 0; i < 20; i++) {
            if (i != *itr2) {
                cout << i << " != list2[" << i << "] == "
                     << *itr2 << '\n';
                pass = false;
            }
            ++itr2;
        }
        if (pass)
            cout << "Insert test passed\n";
        else
            cout << "Insert test failed\n";
        TS_ASSERT(pass);
    }

    void testBegin() {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        cout << "Test begin()" << endl;
        KW::circular_list<int> list1;
        for (int i = 0; i < 10; i++) {
            list1.push_back(i);
        }
        KW::circular_list<int>::iterator itr1 = list1.begin();

        TS_ASSERT_EQUALS(*itr1, 0);
    }

    void testDecOperator() {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        cout << "Test -- operator" << endl;
        KW::circular_list<int> list1;
        for (int i = 0; i < 10; i++) {
            list1.push_back(i);
        }
        KW::circular_list<int>::iterator itr1 = list1.begin();
        itr1--;
        TS_ASSERT_EQUALS(*itr1, 9);
    }

    void testEnd() {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        cout << "Test end()" << endl;
        KW::circular_list<int> list1;
        for (int i = 0; i < 10; i++) {
            list1.push_back(i);
        }
        KW::circular_list<int>::iterator itr1 = list1.end();
        TS_ASSERT_EQUALS(*itr1, 9);
    }

    void testInOperator() {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        cout << "Test ++ operator" << endl;
        KW::circular_list<int> list1;
        for (int i = 1; i < 10; i++) {
            list1.push_back(i);
        }
        KW::circular_list<int>::iterator itr1 = list1.end();
        itr1++;
        TS_ASSERT_EQUALS(*itr1, 1);
    }

    void testPopBack() {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        cout << "Test pop back" << endl;
        KW::circular_list<int> list1;
        for (int i = 1; i < 10; i++) {
            list1.push_back(i);
        }

        TS_ASSERT_EQUALS(list1.back(), 9);
        list1.pop_back();
        TS_ASSERT_EQUALS(list1.back(), 8);
        TS_ASSERT_EQUALS(list1.front(), 1);
    }

    void testPopFront() {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        cout << "Test pop front" << endl;
        KW::circular_list<int> list1;
        for (int i = 1; i < 10; i++) {
            list1.push_back(i);
        }

        TS_ASSERT_EQUALS(list1.front(), 1);
        list1.pop_front();
        TS_ASSERT_EQUALS(list1.front(), 2);
        TS_ASSERT_EQUALS(list1.back(), 9);
    }
    void testConstList() {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        cout << "Test const list" << endl;
        KW::circular_list<int> list1;
        for (int i = 1; i < 4; i++) {
            list1.push_back(i);
        }
        const KW::circular_list<int> list2 = list1 ;
        TS_ASSERT_EQUALS(list2.front(), 1);
        TS_ASSERT_EQUALS(list2.back(), 3);
    }
    void testNonConstList() {  // test copy constructor
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        cout << "Test non const list" << endl;
        KW::circular_list<int> list1;
        for (int i = 1; i < 4; i++) {
            list1.push_back(i);
        }
        KW::circular_list<int> list2;
        list2 = list1 ;
        TS_ASSERT_EQUALS(list2.front(), 1);
        list2.pop_front();
        TS_ASSERT_EQUALS(list2.front(), 2)
        list2.pop_back();
        TS_ASSERT_EQUALS(list2.back(), 2);
        TS_ASSERT_EQUALS(list2.size(), 1)
        TS_ASSERT_EQUALS(list1.front(), 1);
        TS_ASSERT_EQUALS(list1.size(), 3);


    }
    void testErase() {
        //Use TS_ASSERT_EQUALS(Result, ExpResult) to test your functions.
        cout << "Test erase" << endl;
        KW::circular_list<int> list1;
        for (int i = 1; i < 4; i++) {
            list1.push_back(i);
        }

        TS_ASSERT_EQUALS(list1.size(),3);
        KW::circular_list<int>::iterator itr= list1.begin();
        itr++;
        TS_ASSERT_EQUALS(*itr, 2);
        itr = list1.erase(itr);
        TS_ASSERT_EQUALS(*itr, 3);
        TS_ASSERT_EQUALS(list1.size(),2);
        itr = list1.erase(itr);
        TS_ASSERT_EQUALS(list1.size(),1);
        TS_ASSERT_EQUALS(*itr, 1);
        itr = list1.erase(itr);
        TS_ASSERT(list1.empty());
        TS_ASSERT_EQUALS(list1.size(),0);
    }



};
#endif /* NEWCXXTEST_H */

