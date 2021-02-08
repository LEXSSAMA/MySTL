#pragma once

template <typename T> int binTree<T>::remove(binNodePos(T) x){
    FromParentTo(*x) = NULL;
    updateHeightAbove(x->parent);
    int n = removeAt(x); _size = _size -n;
    return n;
}

template <typename T> int removeAt(binNodePos(T) x){
    if(!x) return 0;
    int n = 1 + removeAt(x->leftchild) + removeAt(x->rightchild);
    release(x->data) ; /*因为x->data不一定是基础数据类型,也有可能是指针*/
    release(x);
    return n;
}