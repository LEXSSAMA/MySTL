#pragma once

template <typename T> binNodePos(T) binTree<T>::attachAsRC(binNodePos(T) x, binTree<T>* & S){
    if(x->rightchild = S->_root)
        x->rightchild->parent = x;
    _size += S->_size;
    updateHeightAbove(x);
    S->_root = NULL; S->_size = 0;
    delete S; S = NULL;
    return x;
}