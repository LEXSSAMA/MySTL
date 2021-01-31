#pragma once
template <typename T> void merge(T* S,Rank lo ,Rank mid, Rank hi){
    int j=0, k=mid;
    int lb=mid-lo,lc=hi;
    T* buf = new T[lb];
    for(int i=0;i<lb;++i) buf[i] = S[lo+i];
    for(int i=lo;i<hi&&j<lb;++i){
        if(k>=lc||buf[j]<=S[k])
            S[i] = buf[j++];
        else
            S[i] = S[k++];
    }
    delete [] buf;
}

template <typename T> void mergeSort(T* S,Rank lo,Rank hi){
    if(hi-lo<2)  return ;
    int mid = (lo+hi)>>1;
    mergeSort(S,lo,mid);    /*sort S[lo~mid)*/
    mergeSort(S,mid,hi);    /*sort S[mid~hi)*/
    merge(S,lo,mid,hi);
}