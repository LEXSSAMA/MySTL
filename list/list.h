#include "ListNode.h"
#include <stdlib.h>

typedef int Rank;
template <typename T> class List{
    private: 
        int _size; Posi(T) header; Posi(T) trailer;

    protected:
        void init();
        void copyNodes(Posi(T) p,int n);
        int clear();
        void insertionSort(Posi(T) p,int n);
        void mergeSort(Posi(T)& p,int n);
        void selectionSort(Posi(T) p,int n);
    public:
        /*构造*/
        List(){init();}
        List(List<T>const& L ){copyNodes(L.first(),L.size());}
        Posi(T) first() const{return header->succ;}
        Posi(T) last() const {return trailer->pred;}
        int size() const{return _size;};
        bool empty() {return (_size==0)?true:false;}
        ~List(){clear();delete header; delete trailer;}
        /*重载下标操作符，可模仿向量的循秩访问方式*/
        T& operator[] (Rank r) const{
            Posi(T) p = first();
            while(0<r--)   p = p->succ;
            return p->data;
        }
        /*无序列表的插入和删除*/
        Posi(T) insertB(Posi(T) p , T const& e);    /*将e当作节点p的直接前驱插入*/
        Posi(T) insertA(Posi(T) p , T const& e);    /*将e当作节点p的直接后继插入*/
        Posi(T) insertAtLast(T const& e);   /*将e插入列表尾*/
        Posi(T) insertAtFirst(T const& e);  /*将e插入列表首*/
        int disordered () const;
        T remove(Posi(T) p);

        /*无序列表查找和去重*/
        Posi(T) find(T const& e,int n,Posi(T) p) const;   /*从p开始向前的n个节点中寻找e*/
        Posi(T) find(T const& e) const{return find(e,_size,trailer);}
        int deduplicate();
        void traverse(void (*visit)(T&));
        template <typename VST> void traverse(VST& visit);
        int uniquify();
        Posi(T) search(T const& e,int n,Posi(T) p); /*在有序列表的n个前驱中,找到不大于e的最靠后者*/
        /*排序*/
        void sort(Posi(T) p,int n); /*对列表中起始为p,宽度为n的列表进行排序*/
        void sort(){sort(first(),_size);}
};

#include "list_implementation.h"
