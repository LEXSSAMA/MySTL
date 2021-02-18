#pragma once
#include "queue/queue.h"

typedef enum {UNDETERMINED,TREE,CROSS,FORWARD,BACKWARD} Etype;
typedef enum {UNDISCOVERED,DISCOVERED,VISITED} VStatus;

template <typename Tv , typename Te> class graphic{
    private:
        void reset(){   /*所有顶点,边的辅助信息复位*/
            for(int i=0;i<n;++i){
                getStatus(i) = UNDISCOVERED; getDTime(i) = getFTime(i) = -1;
                getParent(i) = -1; getPriority(i) = __INT_MAX__;
                for(int j=0;j<n;j++)
                    if(exists(i,j)) getType(i,j) = UNDETERMINED;
            }
        }
    public:
    int n ; /*顶点总数*/
    virtual int insertV(Tv const& ) = 0; /*插入顶点,返回编号*/
    virtual Tv remove (int) = 0;        /*删除顶点及其关联边,返回顶点信息*/
    virtual Tv& getVertex(int) = 0;        /*顶点v的数据,(该顶点必须存在)*/
    virtual int getInDegree(int) = 0;      /*顶点v的入度(该顶点必须存在)*/
    virtual int getOutDegree(int) = 0;     /*顶点v的出度(该顶点必须存在)*/
    virtual int getFirstNbr(int) = 0;      /*顶点v的首个邻接顶点*/
    virtual int getNextNbr(int, int ) = 0; /*顶点v相对于顶点j的) 下一个邻接顶点*/
    virtual VStatus& getStatus(int ) = 0;      /*顶点v的状态*/
    virtual int& getDTime(int) = 0;          /*顶点v的时间标签dTime*/
    virtual int& getFTime(int) = 0;         /*顶点v的时间标签fTime*/
    virtual int& getParent(int) = 0;         /*顶点v在遍历树中的父亲*/
    virtual int& getPriority(int) = 0;       /*顶点v在遍历树中的优先级数*/
/*无向图全部转化为方向互逆的一对有向边，从而将无向图视为有向图的特例*/
    int e;
    virtual bool exists(int , int ) = 0;  /*边(v,u)是否存在?*/
    virtual void insertE (Te const& , int, int ,int) = 0;    /*在顶点v和u之间插入权重为w的边e*/
    virtual Te remove(int , int) = 0;   /*删除顶点v和u之间的边，返回该边的信息*/
    virtual Etype& getType(int ,int) = 0;  /*边(v,u)的类型*/
    virtual Te& getEdge(int ,int) = 0;     /*边(v,u)的数据,该边必须存在*/
    virtual int& getWeight(int ,int) = 0;  /*边(v,u)的权重*/
    /*遍历*/
    void BFS(int , int& );
    void bfs(int );
    void DFS(int ,int& );
    void dfs(int );
};
#include "graphic_implementation.h"