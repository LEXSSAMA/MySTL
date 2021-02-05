#pragma once

template <typename T> void List<T>::insertionSort(Posi(T) p,int n){
    for(int i=0;i<n;++i){
        Posi(T) nextp = p->succ;
        Posi(T) q = search(p->data,i,p);

        p->succ->pred = p->pred;
        p->pred->succ = p->succ;

        p->succ = q->succ;
        p->pred = q;

        q->succ->pred= p;
        q->succ =p;
        
        p = nextp;
    }
}