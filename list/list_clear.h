#pragma once

template <typename T> List<T>::clear(){
    int oldSize = _size;
    while(0<_size)  remove(header->succ);
    return oldSize;
}