#pragma once

template <typename T> int binNode<T>::size(){
    int s = 1;
    if(leftchild) s+= leftchild->size();
    if(rightchild) s+= rightchild->size();
    return s;
}