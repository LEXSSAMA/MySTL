#pragma once

template <typename T> binTree<T>* binTree<T>::secede(binNodePos(T) x){
    FromParentTo(*x) = NULL;
    updateHeightAbove(x->parent);
    binTree<T>* S = new binTree<T>;
    S->_root = x; x->parent = NULL;
    S->_size = x->size(); _size -= S->_size;
    return S;
}