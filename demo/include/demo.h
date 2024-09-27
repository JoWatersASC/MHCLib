#pragma once

#include<cassert>

#include"common.h"
#include"list.hpp"

using namespace mhc;
using namespace data_structs;

void testLinkedList() {
    // Test constructor and initial state
    LinkedList<int> list(1);
    assert(list.size() == 1);
    assert(list.front()->val == 1);
    assert(list.back()->val == 1);
    assert(!list.empty());

    // Test push_back
    list.push_back(2);
    assert(list.size() == 2);
    assert(list.back()->val == 2);

    // Test push_front
    list.push_front(0);
    assert(list.size() == 3);
    assert(list.front()->val == 0);

    // Test pop_back
    int poppedValue = list.pop_back();
    assert(poppedValue == 2);
    assert(list.size() == 2);
    assert(list.back()->val == 1);

    // Test pop_front
    poppedValue = list.pop_front();
    assert(poppedValue == 0);
    assert(list.size() == 1);
    assert(list.front()->val == 1);

    // Test insert
    list.insert(3, 0); // Insert 3 at position 0
    assert(list.size() == 2);
    assert(list.front()->val == 3);

    list.insert(4, 1); // Insert 4 at position 1
    assert(list.size() == 3);
    assert(list.back()->val == 4);

    // Test erase
    int erasedValue = list.erase(1); // Erase at position 1
    assert(erasedValue == 4);
    assert(list.size() == 2);
    assert(list.front()->val == 3);
    assert(list.back()->val == 1);

    // Test clear
    list.clear();
    assert(list.empty());
    assert(list.size() == 0);

    std::cout << "All tests passed!" << std::endl;
}

void testLinkedList2() {
    // Test: Create an empty list
    LinkedList<int> sll;
    assert(sll.empty() == true);
    assert(sll.size() == 0);

    // Test: Insert elements
    sll.insert(10);
    assert(sll.size() == 1);
    assert(sll.front()->val == 10);
    assert(sll.back()->val == 10);

    sll.insert(20);
    assert(sll.size() == 2);
    assert(sll.front()->val == 10);
    assert(sll.back()->val == 20);

    // Test: Access elements

    // Test: Erase elements
    sll.erase(0);
    assert(sll.size() == 1);
    assert(sll.front()->val == 20);

    sll.erase(0);
    assert(sll.empty() == true);

}

void testDoubleLinkedList() {
    // Test: Create an empty list
    DoubleLinkedList<int> dll;
    assert(dll.empty() == true);
    assert(dll.size() == 0);

    // Test: Insert elements at the back
    dll.push_back(10);
    assert(dll.size() == 1);
    assert(dll.front()->val == 10);
    assert(dll.back()->val == 10);

    dll.push_back(20);
    assert(dll.size() == 2);
    assert(dll.front()->val == 10);
    assert(dll.back()->val == 20);

    // Test: Insert elements at the front
    dll.push_front(5);
    assert(dll.size() == 3);
    assert(dll.front()->val == 5);
    assert(dll.back()->val == 20);

    // Test: Access elements

    // Test: Erase elements
    dll.pop_front();
    assert(dll.size() == 2);
    assert(dll.front()->val == 10);

    dll.pop_back();
    assert(dll.size() == 1);
    assert(dll.back()->val == 10);

    dll.pop_back();
    assert(dll.empty() == true);
}
