#pragma once

template <typename T> binNodePos(T) binTree<T>::attachAsLC(binNodePos(T) x , binTree<T>* & S){
    if(x->leftchild = S->_root)
        x->leftchild->parent = x;
    _size += S->_size;
    updateHeightAbove(x);
    S->_root = NULL; S->_size = 0;
    release(S); S=NULL;
    return x;
}