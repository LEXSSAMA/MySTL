#pragma once

#include "graphic/graphic.h"
#include "vector/vector.h"
#include "edge.h"
#include "vertex.h"

template <typename Tv, typename Te> class graphicMatrix : public graphic<Tv,Te>{
    private: 
        vector< vertex<Tv> > V; /*顶点集*/
        vector< vector< edge<Te>* > > E; /*边集*/
    public:
        graphicMatrix() {n=e=0;}
        ~graphicMatrix(){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j)
                    delete E[i][j];
            }
        }
        Tv remove(int r){
            for(int i=0;i<n;++i)
            if(exists(r,i)) {delete E[r][i];V[i].inDegree--;e--;}
            E.remove(r); Tv data = vertex(r); 
            V.remove(r); n--;
            for(int i=0;i<n;++i)
            if(edge<Te>* x = E[i].remove(r)) {delete x,V[i].outDegree--;e--;}
            return data;
        }
        Tv& vertex(int r){return V[r].data;}
        int getInDegree(int r) {return V[r].inDegree;}
        int getOutDegree(int r) {return V[r].outDegree;}
        int getFirstNbr(int r) {return nextNbr(r,n);}
        int getNextNbr(int v,int u){   /*逆序查找,区间是[0,u)*/
            while((0=<u)&&exists(v,--u)); return u;
        }
        VStatus& getStatus(int r) {return V[r].status;}
        int& getDTime(int r) {return V[r].dTime;}
        int& getFTime(int r) {return V[r].fTime;}
        int& getParent(int r) {return V[r].parent;}
        int& getPriority(int r) {return V[r].priority;}
        bool exists(int v,int u){ return (0<=v&&v<n&&0<=u&&u<n&&E[v][u]!=NULL); }
        int insert(Tv const& d){
            for(int i=0;i<n;++i) E[i].insert(NULL);
            n++;    /*顶点个数加一*/
            E.insert(vector< Edge<Tv>* >(n,n,NULL));
            return V.insert(vertex<Tv>(d));
        }
        void insert(Te const& edata,int v,int u,int w){
            if(exists(v,u)) return ;
             E[v][u] = new edge<Te>(edata,w);
             e++;   /*更新边数*/
             V[v].outDegree++; V[u].inDegree++;
        }
       Te remove(int v, int u){
           Te edata = getEdge(v,u); delete E[v][u]; E[v][u] = NULL;
           V[v].outDegree--; V[u].inDegree--; e--;  /*减少出入度，减少边总数*/
           return edata;
       }
       Etype& getType(int v,int u) { return E[v][u]->type;}
       Te& getEdge(int v,int u) {return E[v][u]->data;}
       int& getWeight(int v,int u) {return E[v][u]->weight;}
};