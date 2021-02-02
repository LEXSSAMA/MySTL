#pragma once
template <typename T> Posi(T) selectMax(Posi(T) p,int n){
    Posi(T) max = p;
    int maxData = p->data;
    while(0<n--){
        if(p->data>=maxData){
            max = p; maxData = p->data;
        }
        p = p->succ;
    }
    return max;
}
template <typename T> void List<T>::selectionSort (Posi(T) p,int n){
    Posi(T) head = p->pred; Posi(T) tail = p;
    for(int i=0;i<n;++i) tail = tail->succ;
    while(0<n){
        Posi(T) max = selectMax(head->succ,n);
        /*相当于remove操作*/
        max->pred->succ = max->succ;
        max->succ->pred = max->pred;
        /*相当于insert操作*/
        max->pred = tail->pred;
        max->succ = tail;
        /*更新tail*/
        tail->pred->succ = max;
        tail->pred = max;
        tail = tail->pred;
        n--;
    }
}