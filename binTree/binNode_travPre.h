#pragma once

/*先序便利*/
template <typename T,typename VST>
void binNode<T>::travPre(VST& visit){
    switch(rand()%3){
        case 1:
            travPreA(this,visit); break;
        case 2:
            travPreB(this,visit); break;
        default:
            travPreR(this,visit); break;
    }
}

/*递归方式*/
template <typename T,typename VST>
void travPreR(binNodePos(T) x,VST& visit){
    if(!x) return ;
    visit(x->data);
    travPreR(this->leftchild,visit);
    travPreR(this->rightchild,visit);
}