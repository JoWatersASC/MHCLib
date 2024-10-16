#pragma once

#include"common.h"

namespace mhc
{
namespace ds
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
namespace ds
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




namespace mhc {

    using namespace ds;
    template<typename T>
    void reverse(LinkedList<T>& list) {
        ListNode<T>* prev = nullptr;
        ListNode<T>* curr = list.front();
        ListNode<T>* next = curr->next;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        list.head = prev;
    }
    template<typename T>
    std::ostream& operator<<(LinkedList<T> list, std::ostream& out) {
        ListNode<T>* _head = list.front();

        out << "{";
        while (_head) {
            out << _head->val << ", ";
            _head = _head->next;
        }
        out << "\b\b}";

        return out;
    }

    template<typename T>
    void reverse(DoubleLinkedList<T>& list) {
        DoubleListNode<T>* pr   = list.front()->prev;
        DoubleListNode<T>* curr = list.front();
        DoubleListNode<T>* nx   = list.front()->next;

        while (nx && curr) {
            dln temp = curr;
            curr->next = temp->prev;
            curr->prev = temp->next;
        
            curr = curr->next;
            pr = curr->prev;
            nx = curr->next;
        }
    }
    template<typename T>
    std::ostream& operator<<(DoubleLinkedList<T> list, std::ostream& out) {
        DoubleListNode<T>* _head = list.front();

        out << "{";
        while (_head) {
            out << _head->val << ", ";
            _head = _head->next;
        }
        out << "\b\b}";

        return out;
    }

}