#pragma once

#include<exception>

namespace mhc
{
namespace data_structs
{

namespace {
    template<typename T>
    struct ListNode {
        T val;
        ListNode<T>* next;

        using ln = ListNode<T>*;
        ListNode(T _val, ln _next = nullptr) : val(_val), next(_next) {}
    };

    template<typename T>
    struct DoubleListNode {
        DoubleListNode<T>* prev;
        T val;
        DoubleListNode<T>* next;

        using dln = DoubleListNode<T>*;
        DoubleListNode(T _val) : prev(0), val(_val), next(0) {}
        DoubleListNode(T _val, dln _next) : prev(0), val(_val), next(_next) {}
        DoubleListNode(dln _prev, T _val, dln _next = nullptr) : prev(_prev), val(_val), next(_next) {}
    };
}
}
}

namespace mhc 
{
namespace data_structs
{

//Singly linked list
template<typename T>
class LinkedList {
    using ln = ListNode<T>*;
public:
    LinkedList(T val)              : m_head(new ListNode(val)), m_size(1) { m_tail = m_head; }
    LinkedList(ln _head = nullptr) : m_head(_head),             m_size(_head ? 1 : 0) { m_tail = m_head; }
    ~LinkedList();

    //
    ln front() { return m_head; }
    ln back()  { return m_tail; }
    ln node_at(size_t pos);
    T at(size_t pos);
    
    bool empty()  { return !m_head && !m_tail && !m_size; }
    size_t size() { return m_size; }
    const static size_t max_size = static_cast<size_t>(-1) / sizeof(T);
    
    void clear();
    void insert(T val, size_t pos);
    void insert(T val);
    T erase(size_t pos);

    void push_back(T val);
    void push_front(T val);
    T pop_back();
    T pop_front();

    T operator[](size_t pos);

    friend void reverse(DoubleLinkedList& list);

private:
    size_t m_size;
    ln m_head;
    ln m_tail;
};





template<typename T>
class DoubleLinkedList {
    using dln = DoubleListNode<T>*;
public:
    DoubleLinkedList(T val) : m_head(new DoubleListNode(val)), m_size(0) { m_tail = m_head; }
    DoubleLinkedList(dln _head = nullptr) : m_head(_head), m_size(_head ? 1 : 0) { m_tail = m_head; }
    ~DoubleLinkedList();

    dln front() { return m_head; }
    dln back() { return m_tail; }
    dln node_at(size_t pos);
    T at(size_t pos);

    bool empty() { return !m_head && !m_tail && !m_size; }
    size_t size() { return m_size; }
    const static size_t max_size = static_cast<size_t>(-1) / sizeof(T);

    void clear();
    void insert(T val, size_t pos);
    void insert(T val);
    T erase(size_t pos);

    void push_back(T val);
    void push_front(T val);
    T pop_back();
    T pop_front();

    T operator[](size_t pos);

    friend void reverse(DoubleLinkedList& list);

private:
    size_t m_size;
    dln m_head;
    dln m_tail;
};

}
}


using namespace mhc::data_structs;
template<typename T>
void reverse(LinkedList<T>& list) {

}
template<typename T>
void reverse(DoubleLinkedList<T>& list) {

}