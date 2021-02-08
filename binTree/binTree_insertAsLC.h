#pragma once

template <typename T> binNodePos(T) binTree<T>::insertAsLC(binNodePos(T) x,T const& e){
    _size++;
    x->insertAsLeftChild(e);
    updateHeightAbove(x);
    return x->leftchild;
}