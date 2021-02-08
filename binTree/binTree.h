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

        /*子树删除*/
        int remove(binNodePos(T) x);   /*将x节点及其儿孙节点从树上删除，返回总共删除的总数*/

        /*子树分离*/
        binTree<T>* secede(binNodePos(T) x); /*将x节点及其儿孙从树上分离，返回分离后的x所在的树*/

        /*遍历*/
        template <typename VST> void travPre(VST& visit){if(_root) _root->travPre(visit);}      /*先序遍历：对每个元素执行visit操作*/
        template <typename VST> void travPost(VST& visit){if(_root) _root->travPost(visit);}    /*后序遍历：对每个元素执行visit操作*/
        template <typename VST> void travLevel(VST& visit){if(_root) _root->travLevel(visit);}  /*层序遍历：对每个元素执行visit操作*/
        template <typename VST> void travIn(VST& visit){if(_root) _root->travIn(visit);}        /*中序遍历：对每个元素执行visit操作*/
};