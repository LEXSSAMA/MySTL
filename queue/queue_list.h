#include "list/list.h"
#pragma once

template <typename T> class queue : public List<T>{
    public:
        void enqueue(T const& e) {insertAtLast(e);}
        T dequeue() {return this->remove(this->first());}
        T& front() {return this->first()->data;}
};