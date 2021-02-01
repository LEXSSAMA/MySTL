#pragma once

template <typename T> void List<T>::copyNode(Posi(T) p,int n){
    init();
    while(0<n--){
        insertAtLast(p->data);
        p = p->succ;
    }
}