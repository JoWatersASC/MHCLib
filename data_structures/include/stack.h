#pragma once

#include "ds_common.h"
#include "list.h"

namespace mhc
{
namespace ds
{

	// Data type held, implementation(array or linked list), predetermined size/allocation (impl defaults to ll)
	template<typename T, size_t _cap = 10, impl implementation = impl::ARRAY>
	class Stack {
	public:
		//Constructors
		Stack() = default;
		Stack(Stack&);

		//Modifiers
		void push(T);
		void pop(T);

		//Element Access
		const T& top() const;
		T& top();

		//Capacity Attributes
		size_t size()	  const { return _size; }
		size_t capacity() const { return _cap; }
		bool empty() const;
		bool full()  const;

	private:
		size_t _size = 0;
	};

	//Can't initialize a stack with 0 capacity
	template<typename T, impl implementation>
	class Stack<T, 0, implementation> {
		Stack() = delete;
		Stack(Stack&) = delete;
		Stack(Stack&&) = delete;
	};

	/*
	To initialize a stack:

	- "data_type" is any datatype you want to be in the stack

	- "max_size" is the maximum # of items you want the stack to be able to hold
		-Is **optional** and is unsigned long long int that will default to 10

	- "implementation_type" is  impl::ARRAY for array based or impl::LIST for linked list
		-Is also **optional** and will default to impl::ARRAY

	- "stack_name" is the variable name, can be whatever you want

	1) mhc::ds::stack<data_type, max_size, implementation_type> stack_name;
	2) mhc::ds::stack<data_type, max_size> stack_name;
		- Array based stack of max_size
	3) mhc::ds::stack<data_type, implementation_type> stack_name;
		- 10 element stack of implementation
	4) mhc::ds::stack<data_type> stack_name;
		- 10 element array based stack
	*/
}
}