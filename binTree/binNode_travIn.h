#pragma once

template <typename T, typename VST>
void binNode<T>::travIn(VST& visit){
     siwtch(rand()%3){
         case 1 : travInR(this,visit); break;
         default: travInA(this,visit); break;
     }
}

template <typename T,typename VST>
void travInR(binNodePos(T) x,VST& visit){
    if(!x) return;
    travInR(x->leftchild,visit);
    visit(x->data);
    travInR(x->rightchild,visit);
}

template <typename T,typename VST>
void goAlongVine(binNodePos(T) x ,stack<binNodePos(T)>& S){
    while(x){
        S.push(x); x = x->leftchild;
    }
}

template <typename T,typename VST>
void travInA(binNodePos(T) x,VST& visit){
    stack<binNodePos(T)> S;
    while(true){
        goAlongVine(x,S);
        if(S.empty()) break;
        x = S.pop(); visit(x->data);
        x = x->rightchild;
    }
}