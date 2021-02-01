#include "ListNode.h"

typedef int Rank;
template <typename T> class List{
    private: 
        int _size; Posi(T) header; Posi(T) trailer;

    protected:
        void init();
        void copyNode(Posi(T) p,int n);
        void clear();
    public:
        /*构造*/
        List(){init();}
        List(List<T> L) {copyNode(L.first(),L._size);}
        ~List(){clear();delete header; delete trailer;}
        Posi(T) first() {return header->succ;}
        /*重载下标操作符，可模仿向量的循秩访问方式*/
        T operator[] (Rank r) const{
            Posi(T) p = first();
            while(0<r--)   p = p->succ;
            return p->data;
        }
        /*无序列表的插入和删除*/
        Posi(T) insertB(Posi(T) p , T const& e);    /*将e当作节点p的直接前驱插入*/
        Posi(T) insertA(Posi(T) p , T const& e);    /*将e当作节点p的直接后继插入*/
        Posi(T) insertAtLast(T const& e);   /*将e插入列表尾*/
        Posi(T) insertAtFirst(T const& e);  /*将e插入列表首*/
        T remove(Posi(T) p);

        /*无序列表查找和去重*/
        Posi(T) find(T const& e,int n,Posi(T) p) const;   /*从p开始向前的n个节点中寻找e*/
        Posi(T) find(T const& e) const{return find(e,_size,trailer);}
        int deduplicate();
        void traverse(void (*visit)(T&));
        template <typename VST> void traverse(VST& visit);
};