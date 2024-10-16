#pragma once

#include "stack.h"

namespace mhc
{
namespace ds
{


	//Array Based
	template<typename T, size_t _cap>
	class Stack<T, _cap, impl::ARRAY> {
	public:
		void push(T item) {
			if (full()) throw std::overflow_error("Stack is full");;

			data[m_top++] = item;
			_size++;
		}
		void pop() {
			if (empty()) throw std::underflow_error("Stack is empty");;

			m_top--;
			_size--;
		}

		T& top() {
			return data[m_top - 1];
		}
		const T& top() const {
			return data[m_top - 1];
		}

		bool empty() const {
			return m_top == 0;
		}
		bool full() const {
			return m_top == _cap;
		}

	private:
		size_t m_top = 0;
		T data[_cap];
	};

	//Linked List based
	template<typename T, size_t _cap>
	class Stack<T, _cap, impl::LIST> {
	public:
		void push(T item) {
			if (_capaity == _size) return;
			if (!m_head) {
				m_head = new DoubleListNode<T>(item);
				m_tail = m_head;
				_size++;
				return;
			}

			m_tail->next = new DoubleListNode<T>(m_tail, item);
			m_tail = m_tail->next;
			_size++;
		}
		void pop() {
			if (!tail) return;
			if (m_head == m_tail) {
				m_head = nullptr;
				delete m_tail;
				m_tail = m_head;
				_size--;
				return;
			}

			m_tail = m_tail->prev;
			delete m_tail->next;
			m_tail->next = nullptr;
			_size--;
		}

		const T& top() const {
			return m_tail->val;
		}

		T& top() {
			return m_tail->val;
		}

		bool empty() const {
			return _size == 0;
		}
		bool full() const {
			return _size == _capacity;
		}
	private:
		DoubleListNode<T>* m_head;
		DoubleListNode<T>* m_tail;
	};

}
}