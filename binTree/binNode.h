#pragma once

#define binNodePos(T) binNode<T>*

template <typename T> struct binNode{
    binNodePos(T) parent,leftchild,rightchild; T data; int height;
    binNode(T const& edata){binNode(edata,NULL);}
    binNode(T const& edata , binNodePos(T) pa) {
        parent=pa; leftchild = NULL; rightchild = NULL; 
        data = edata; height = 0;
    }
    int size(); /*代表子树的规模*/
    binNodePos(T) insertAsLeftChild(T const& e);
    binNodePos(T) insertAsRightChild(T const& e);

    template <typename VST> void travLevel(VST& visit);
    template <typename VST> void travPost (VST& visit);
    template <typename VST> void travPre(VST& visit);
    template <typename VST> void travIn (VST& visit);
};