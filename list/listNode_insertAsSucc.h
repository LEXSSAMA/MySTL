#pragma once

template <typename T> ListNode<T>::insertAsSucc(T const& e){
    Posi(T)  p = new ListNode<T>(e,this,succ);
    succ->pred = p; succ = p;
    return p;
}