#pragma once

template <typename T> int List<T>::disordered() const{
    int n=0;
    Posi(T) p = first();
    Posi(T) q = p->succ;
    for(int i=0;i<_size-1;++i){
        if(p->data>q->data)
            n++;
        q = q->succ;
        p = p->succ;
    }
    return n;
}