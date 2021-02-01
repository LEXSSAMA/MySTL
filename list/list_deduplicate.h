#pragma once

template <typename T> int List<T>::deduplicate(){
    int oldSize = _size;
    Posi(T) p = first();
    for(Rank i=0;p!=trailer;p=p->succ){
        if(Posi(T) q = find(p->data,i,p))
            remove(q);
        else
            i++;
    }
    return oldSize - _size;
}