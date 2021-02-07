#include "vector/vector.h"
#pragma once

template <typename T> class queue : public vector<T>{
    public:
        void enqueue(T const& e){this->insert(e);}
        T dequeue() {return this->remove(0);}
        T& front() {return this->get(0);}
};