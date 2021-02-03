#pragma once

template <typename T> void merge(Posi(T)& p,int n, Posi(T)& q,int m){
    Posi(T) header = p->pred;
    while(0<m){
        if(0<n&&p->data<=q->data){
            if((p=p->succ) == q) break;
            n--;
        }
        else{
            Posi(T) nextq = q->succ;
            /*相当于将q,remove*/
            q->succ->pred = q->pred;
            q->pred->succ = q->succ;
            /*将移除的q插入作为p的前继*/
            q->succ = p;
            q->pred = p->pred;
            p->pred->succ = q;
            p->pred = q;
            q = nextq;
            m--;
        }
    }
    p = header->succ;
}

template <typename T> void List<T>::mergeSort(Posi(T)& p,int n){
    if(n<2) return ;
    int mi = n>>1 ;
    Posi(T) q = p;
    for(int i=0;i<mi;++i)
        q = q->succ;
   mergeSort(p,mi);
   mergeSort(q,n-mi);
   merge(p,mi,q,n-mi);
}