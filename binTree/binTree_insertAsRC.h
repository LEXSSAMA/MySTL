#pragma once

template <typename T> binNodePos(T) binTree<T>::insertAsRC(binNodePos(T) x , T const& e){
    _size++;
    x->insertAsRightChild(e);
    updateHeightAbove(x);
    return x->rightchild;
}