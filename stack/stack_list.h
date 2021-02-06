#include "list/list.h"
#pragma once


template <typename T> class stack : public List<T>{
    public:
        void push(T const& e){this->insertAtLast(e);}
        T pop() {return this->remove(this->last());}
        T& top() {return this->last()->data;}
};
