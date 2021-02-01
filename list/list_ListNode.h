#pragma once
#define Posi(T) ListNode<T>*

template <typename T> struct ListNode{
    T data;
    Posi(T) pred;   /*节点前驱*/
    Posi(T) succ;   /*节点后继*/
    ListNode() {}  /*针对header 和 trailer的构造*/
    ListNode(T e, Posi(T) p=NULL, Posi(T) s=NULL) :  data(e),pred(p),succ(s){}
    Posi(T) insertAsPred(T const& e);   /*前插入*/
    Posi(T) insertAsSucc(T const& e);   /*后插入*/
};
