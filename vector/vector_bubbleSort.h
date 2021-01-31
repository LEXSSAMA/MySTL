#pragma once 

/*最好的时间复杂度为O(n),最坏的时间复杂度为O(n^2)*/
template <typename T> void bubbleSort(T* S,Rank lo,Rank hi){
    for (Rank last = --hi; lo < hi; hi =last){
        for(Rank i=last=lo;i<hi;++i){
            if(S[i]>S[i+1]){
                int tmp = S[i+1];
                S[i+1] = S[i];
                S[i] = tmp;
                last = i;   /*逆序对只能残留于[lo,last)中*/
            }
        }
    }
}
