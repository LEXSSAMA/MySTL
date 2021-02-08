#pragma once

template <typename T> binNodePos(T) insertAsRoot(T const& e){
    _size=1;
    _root = new binNode<T>e(e);
    return _root;
}