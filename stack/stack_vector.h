#include "vector/vector.h"
# pragma once

template <typename T> class stack : public vector<T>{
    public:
        void push(T const& e){this->insert(e);}
        T pop(){return this->remove(this->size()-1);}
        T& top() {return (*this)[this->size()-1];}
};