#include "binNode.h"
#pragma once

#define stature(p) ((p)?p->heights:-1)

template <typename T> class binTree(){
    protected:
        int _size;  binNodePos(T) _root;
        virtual int updateHeight(binNodePos(T) x);  /*更新节点x的高度*/
        void updateHeightAbove(binNodePos(T) x);    /*更新x及祖先的高度*/
    public:
        binTree(T const& e){_size = 1; _root = new binNode<T>(e); updateHeight(root);}
        binTree(): _size(0), _root(NULL){}
        int size() const{return _size;}
        bool empty() {return !_root;}
        binNodePos(T) root() {return _root;}
        /*节点插入*/
        binNodePos(T) insertAsRoot(T const& e);
        binNodePos(T) insertAsRC(binNodePos(T) x, T const& e);  /*对x的右节点插入*/
        binNodePos(T) insertAsLC(binNodePos(T) x, T const& e);  /*对x的左节点插入*/
        /*子树接入*/
        binNodePos(T) attachAsRC(binNodePos(T) x, binTree<T>* & S); /*将二叉树S作为节点x的右子树*/
        binNodePos(T) attachAsLC(binNodePos(T) x,binTree<T>*& S);   /*将二叉树S作为节点x的左子树*/
};