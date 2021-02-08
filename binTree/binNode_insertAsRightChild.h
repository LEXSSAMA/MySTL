#pragma once

template <typename T> binNodePos(T) binNode<T>::insertAsRightChild(T const& e){
    return rightchild = new binNode<T>(e,this);
}