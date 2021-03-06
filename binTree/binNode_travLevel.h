#pragma once

template <typename T> template <typename VST>
void binNode<T>::travLevel(VST& visit){
    queue<binNodePos(T)> Q; Q.enqueue(this);
    while(!Q.empty()){
        binNodePos(T) x = Q.dequeue(); visit(x->data);
        if(HasLeftChild( *x )) Q.enqueue(x->leftchild);
        if(HasRightChild( *x )) Q.enqueue(x->rightchild);
    }
}