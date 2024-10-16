#pragma once

#include"list.h"

namespace mhc 
{
namespace ds
{

template<typename T>
LinkedList<T>::~LinkedList() { clear(); }

template<typename T>
ListNode<T>* LinkedList<T>::node_at(size_t pos) {
    if (pos >= m_size) throw std::out_of_range("Out of bounds: too high");

    size_t _pos = 0;
    ln _head = m_head;

    while (_pos++ < pos) {
        if (_head == nullptr) throw std::out_of_range("Out of bounds: too high");
        _head = _head->next;
    }

    return _head;
}
template<typename T>
T LinkedList<T>::at(size_t pos) {
    if (pos >= m_size) throw std::out_of_range("Out of bounds: too high");
    return node_at(pos)->val;
}


template<typename T>
void LinkedList<T>::clear() {
    ln temp;

    while (m_head) {
        temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
    m_head = nullptr; m_tail = nullptr;

    m_size = 0;
}
template<typename T>
void LinkedList<T>::insert(T val, size_t pos) {
    if (m_size >= max_size) throw std::bad_alloc();
    if (m_size <= pos)      throw std::out_of_range("Out of bounds: too high");

    if (pos == 0) 
        push_front(val);
    else if (pos == m_size - 1) 
        push_back(val);
    else {
        ln _head = m_head;
        while (_head && --pos) { _head = _head->next; }

        ln newNode = new ListNode(val, _head->next);
        _head->next = newNode;

        m_size++;
    }
}
template<typename T>
void LinkedList<T>::insert(T val) { push_back(val); }
template<typename T>
T LinkedList<T>::erase(size_t pos) {
    if (m_size >= max_size) throw std::bad_alloc();
    if (m_size <= pos)      throw std::out_of_range("Out of bounds: too high");

    T _val;
    if (pos == 0)              _val = pop_front();
    else if (pos = m_size - 1) _val = pop_back();
    else {
        ln _head = m_head;
        while (_head->next && --pos) { _head = _head->next; }

        ln temp     = _head->next;
        _val        = temp->val;
        _head->next = temp->next;
        delete temp;

        m_size--;
    }

    return _val;
}

template<typename T>
void LinkedList<T>::push_back(T val) {
    if (m_size >= max_size) throw std::bad_alloc();

    if (m_size == 0) {
        m_head = new ListNode(val);
        m_tail = m_head;
    }
    else {
        m_tail->next = new ListNode(val);
        m_tail = m_tail->next;
    }
    m_size++;
}
template<typename T>
void LinkedList<T>::push_front(T val) {
    if (m_size >= max_size) throw std::bad_alloc();
    
    if (m_size == 0) {
        m_head = new ListNode(val);
        m_tail = m_head;
    }
    else {
        ln temp = new ListNode(val, m_head);
        m_head = temp;
    }
    m_size++;
}
template<typename T>
T LinkedList<T>::pop_back() {
    ln _head = m_head;

    while (_head->next && _head->next->next) { _head = _head->next; }

    ln temp = _head->next;
    T _val = temp->val;
    _head->next = nullptr;
    m_tail = _head;
    delete temp;

    if (--m_size == 0) { m_tail = nullptr; m_head = nullptr; }
    return _val;
}
template<typename T>
T LinkedList<T>::pop_front() {
    ln temp = m_head;
    T _val  = m_head->val;
    m_head  = m_head->next;
    delete temp;

    if (--m_size == 0) { m_tail = nullptr; m_head = nullptr; }
    return _val;
}

template<typename T>
T LinkedList<T>::operator[] (size_t pos) {
    return node_at(pos)->val;
}

}//namespace data_structs
}//namespace mhc






namespace mhc 
{
namespace ds
{

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() { clear(); }

template<typename T>
DoubleListNode<T>* DoubleLinkedList<T>::node_at(size_t pos) {
    if (pos >= m_size) throw std::out_of_range("Out of bounds: too high");
    
    size_t _pos = 0;
    dln _head = m_head;

    while (_pos++ < pos) {
        if (_head == nullptr) throw std::out_of_range("Out of bounds: too high");
        _head = _head->next;
    }

    return _head;
}
template<typename T>
T DoubleLinkedList<T>::at(size_t pos) {
    return node_at(pos)->val;
}

template<typename T>
void DoubleLinkedList<T>::clear() {
    while (m_head) {
        dln temp = m_head;
        m_head = m_head->next;
        delete temp;
    }

    m_head = nullptr; m_tail = nullptr;
    m_size = 0;
}
template<typename T>
void DoubleLinkedList<T>::insert(T val, size_t pos) {
    if (m_size >= max_size) throw std::bad_alloc();
    if (m_size <= pos)      throw std::out_of_range("Out of bounds: too high");

    if (pos == 0)
        push_front(val);
    else if (pos == m_size - 1)
        push_back(val);
    else {
        dln _head = m_head;
        while (_head && --pos) { _head = _head->next; }

        dln newNode = new ListNode(_head, val, _head->next);
        newNode->next->prev = newNode;
        _head->next = newNode;

        m_size++;
    }
}
template<typename T>
void DoubleLinkedList<T>::insert(T val) { push_back(val); }
template<typename T>
T DoubleLinkedList<T>::erase(size_t pos) {
    if (m_size >= max_size) throw std::bad_alloc();
    if (m_size <= pos)      throw std::out_of_range("Out of bounds: too high");

    T _val;
    if (pos == 0)              _val = pop_front();
    else if (pos = m_size - 1) _val = pop_back();
    else {
        dln _head = m_head;
        while (_head->next && --pos) { _head = _head->next; }

        dln nx       = _head->next;
        _val         = nx->val;

        _head->next  = nx->next;
        _head->next->prev = _head;
        delete nx;

        m_size--;
    }

    return _val;
}

template<typename T>
void DoubleLinkedList<T>::push_back(T val) {
    if (m_size >= max_size) throw std::bad_alloc();

    if (m_size == 0) {
        m_head = new DoubleListNode(val);
        m_tail = m_head;
    }
    else {
        m_tail->next = new DoubleListNode(m_tail, val);
        m_tail = m_tail->next;
    }
    m_size++;
}
template<typename T>
void DoubleLinkedList<T>::push_front(T val) {
    if (m_size >= max_size) throw std::bad_alloc();

    if (m_size == 0) {
        m_head = new DoubleListNode(val);
        m_tail = m_head;
    }
    else {
        dln temp = new DoubleListNode(val, m_head);
        m_head = temp;
    }

    m_size++;
}
template<typename T>
T DoubleLinkedList<T>::pop_back() {
    T _val = m_tail->val;

    if (m_size == 1) {
        m_head = nullptr;
        m_tail = nullptr;
    }
    else {
        dln _tail = m_tail;

        m_tail = m_tail->prev;
        m_tail->next = nullptr;
        delete _tail;
    }
    if (--m_size == 0) { m_tail = nullptr; m_head = nullptr; }
    return _val;
}
template<typename T>
T DoubleLinkedList<T>::pop_front() {
    dln temp = m_head;
    T _val = m_head->val;

    m_head = m_head->next;
    m_head->prev = nullptr;
    delete temp;

    if (--m_size == 0) { m_tail = nullptr; m_head = nullptr; }
    return _val;
}

template<typename T>
T DoubleLinkedList<T>::operator[](size_t pos) {
    return node_at(pos)->val;
}

}
}