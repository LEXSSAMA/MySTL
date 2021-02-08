#pragma once

template <typename T> binNodePos(T) binNode<T>::insertAsLeftChild(T const& e){
    return leftchild = new binNode<T>(e,this);
};