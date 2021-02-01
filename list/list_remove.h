#pragma once

template <typename T> T List<T>::remove(Posi(T) p){
    T e = p->data;
    p->succ->pred = p->pred;
    p->pred->succ = p->succ;
    delete p;
    _size--;
    return e;
}