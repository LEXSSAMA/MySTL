#include <stdio.h>
#pragma once

template <typename T> void List<T>::insertionSort(Posi(T) p,int n){
    printf("insertSort\n");
    for(int i=1;i<n;++i){
        Posi(T) q = search((p=p->succ)->data,i,p);
        p->succ->pred = p->pred;
        p->pred->succ = p->succ;

        p->succ = q->succ;
        p->pred = q;

        q->succ->pred= p;
        q->succ =p;
    }
}