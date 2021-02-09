#pragma once

template <typename T> binNodePos(T) binNode<T>::succ(){
    binNodePos(T) x = this;
    if(rightchild){ /*如果存在右子树，那么中序遍历的直接后缀在右子树中*/
        x = x->rightchild;
        while(x->leftchild) x = x->leftchild;
    }else{
        while(IsRightChild(*x)) x = x->parent;
        x = x->parent;
    }
    return x;
}