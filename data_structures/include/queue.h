#pragma once

#include "ds_common.h"
#include "list.h"

namespace mhc
{
namespace ds
{
    
    // Data type held, implementation(array or linked list), predetermined size/allocation (impl defaults to ll)
    template<typename T, size_t _cap = 10, impl implementation = impl::ARRAY>
    class queue {
    public:
        //Constructors/Destructor
        queue();
        ~queue();

        //Modifiers
        void enqueue();
        T dequeue();

        //Element Access
        T front();
        T rear();

        //Capacity Attributes
        size_t size()     const { return _size; }
        size_t capacity() const { return _cap; }
        bool empty() const;
        bool full()  const;

    private:
        size_t _size;
    };
    
}
}