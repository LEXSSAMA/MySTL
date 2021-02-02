#pragma once

template <typename T> Posi(T) List<T>::search(T const& e,int n,Posi(T) p){
   do{p=p->pred;n--;} 
   while(-1<n&&(e<p->data));
   return p;
}