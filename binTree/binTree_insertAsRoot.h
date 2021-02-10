#pragma once

template <typename T> binNodePos(T) binTree<T>::insertAsRoot(T const& e){
    _size=1; _root = new binNode<T>(e);
    return _root;
}