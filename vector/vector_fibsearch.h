#pragma once 
#include "fibonacci/Fib.h"
template <typename T> static Rank fibSearch (T* S, T const& e, Rank lo, Rank hi){
   for(Fib f(hi-lo);lo<hi;) {
       while(hi-lo<f.get()) f.prev();
       Rank mid = lo + f.get() -1;
       if(e<S[mid]) lo = mid+1;
       else if(s[mid]<e) hi = mid;
       else return mid;
   }
   return -1;
}