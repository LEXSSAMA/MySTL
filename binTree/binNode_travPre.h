#pragma once

/*递归方式*/
template <typename T,typename VST>
void travPreR(binNodePos(T) x,VST& visit){
    if(!x) return ;
    visit(x->data);
    travPreR(x->leftchild,visit);
    travPreR(x->rightchild,visit);
}

/*迭代 + 栈*/
/*优点:好理解; 缺点: 这种形式的迭代是利用了先序遍历尾递归的特性，无法向其他遍历推广*/
template <typename T, typename VST>
void travPreA(binNodePos(T) x, VST& visit){
    stack<binNodePos(T)> S; if(x) S.push(x);
    while(!S.empty()){
        x = S.pop(); visit(x->data);
        if(HasRightChild(*x)) S.push(x->rightchild); /*先将右儿子入栈,因为右儿子后处理*/
        if(HasLeftChild(*x))  S.push(x->leftchild);  /*后将左儿子入栈*/
    }
}

template <typename T , typename VST>
void visitAlongVine(binNodePos(T) x , VST& visit, stack<binNodePos(T)> & S){
    while(x){
        visit(x->data);
        S.push(x->rightchild);
        x = x->leftchild;
    }   //只有右孩子、NULL可能入栈——增加判断以剔除后者，是否值得?
       /*没必要，只有右孩子和右孩子为NULL的情况,while(x)会跳出循环，一般情况下这两种情况相比于在二叉树中是比较少出现的,
       增加判断语句，每访问一个节点都会执行一次判断开销更大*/
}

template <typename T , typename VST>
void travPreB(binNodePos(T) x, VST& visit){
    stack<binNodePos(T)> S;
    while(true){
        visitAlongVine(x,visit,S);
        if(!S.empty()) break;
        x = S.pop();
    }
}

/*先序遍历*/
template <typename T> template <typename VST>
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
