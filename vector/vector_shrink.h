#pragma once

template <typename T> void vector<T>::shrink(){
    if(_capacity < DEFAULT_CAPACITY <<1) return ;
    if((_size<<2)>_capacity) return;    /*如果(_size <<2)<_capacity,则_capacity缩小一倍都可以装入所以元素*/
    T* oldElem = _elem; _elem = new T[_capacity>>=1];
    for(int i=0;i<_size;++i) _elem[i] = oldElem[i];

    delete [] oldElem;
}