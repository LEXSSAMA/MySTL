#pragma once

template <typename T , typename VST>
void binNode<T>::travPost(VST& visit){
    switch (rand()%3)
    {
    case 1:
        travPostR(this,visit);
        break;
    default:
        travPostA(this,visit);  /*权重更大一点*/
        break;
    }
}

/*递归方式*/
template <typename T , typename VST>
void travPostR(binNodePos(T) x, VST& visit){
    if(!x) return ;
    travPostR(x->leftchild,visit);
    travPostR(x->rightchild,visit);
    visit(x->data);
}

template <typename T>
void gotoLeftMostLeaf(stack<binNodePos(T)>& S){
    while(binNodePos(T) x = S.top()){
        if(HasLeftChild(*x)){
            if(HasRightChild(*x))
                S.push(x->rightchild);
            S.push(x->leftchild);
        }
        else S.push(x->rightchild);
    }
    S.pop();    /*返回前,弹出栈顶的空字符*/
}
/*迭代+栈*/
template <typename T , typename VST>
void travPostA(binNodePos(T) x,VST& visit){
    stack<binNodePos(T)> S; if(x) S.push(x);
    while(!S.empty()){
        if(x->parent != S.top()) /*栈顶非x之父(而为右兄)*/
            gotoLeftMostLeaf(S);
        x = S.pop(); visit(x->data);    /*弹出栈顶,处理x*/
    }
}