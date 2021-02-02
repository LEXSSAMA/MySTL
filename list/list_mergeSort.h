#include <stdio.h>
#pragma once

template <typename T> void merge(Posi(T)& p,int n, Posi(T)& q,int m){
    printf("n==%d,m==%d,p->data==%d,q->data==%d\n",n,m,p->data,q->data);
    int size = n+m;
    int mi =size>>1;
    Posi(T) header = p->pred;
    printf("header->data =%d\n",header->data);
    Posi(T) rec = header->succ;
    for(int i=0;i<size;++i){
        printf("%d ",rec->data);
        rec = rec->succ;
    }
    printf("\n");
    while(0<m){
        if(0<n&&p->data<=q->data){
            printf("p->data == %d\n",p->data);
            if((p=p->succ) == q) break;
            n--;
        }
        else{
            printf("q->data == %d\n",q->data);
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
    printf("\n");
    rec = header->succ;
    for(int i=0;i<size;++i){
        printf("%d ",rec->data);
        rec = rec->succ;
    }
    p = header->succ;
    q = p;
    for(int i=0;i<mi;++i)
        q = q->succ;
    printf("recove p->data == %d, q->data ==%d\n",p->data,q->data);
    printf("\n----------------------------------\n");
}

template <typename T> void List<T>::mergeSort(Posi(T) p,int n){
    if(n<2) return ;
    int mi = n>>1 ;
    Posi(T) q = p;
    for(int i=0;i<mi;++i)
        q = q->succ;
   mergeSort(p,mi);
   mergeSort(q,n-mi);
   merge(p,mi,q,n-mi);
//    Posi(T) rec = p;
//    printf("P:\n");
//    for(int i=0;i<mi;++i){
//        printf("%d ",rec->data);
//        rec = rec->succ;
//    }
//    rec =q;
//    printf("\nq:\n");
//    for(int i=0;i<mi;++i){
//        printf("%d ",rec->data);
//        rec =rec->succ;
//    }
//    printf("\n-----------------------------------------------------------\n");
}