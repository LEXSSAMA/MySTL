#pragma once

template <typename T> ListNode<T>::insertAsPred(T const& e){
   Posi(T) p = new ListNode<T>(e,pred,this);
   pred->succ = p;
   pred = p;
   return p;
}