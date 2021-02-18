#pragma once


template <typename Tv> struct vertex {
    Tv data ; int inDegree , outDegree; /*顶点内装的数据,出度,入度*/
    VStatus status;     /*该顶点的状态*/
    int dTime , fTime; int parent; int priority; /*时间标签,在遍历树中的父节点,在遍历树中的优先级*/
    vertex(Tv const& d = (Tv)0) : data(d),inDegree(0),outDegree(0),status(UNDISCOVERED),dTime(-1),fTime(-1),parent(-1),priority(__INT_MAX__){}
};
