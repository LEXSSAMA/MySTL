#pragma once

#include "graphic/graphic.h"
#include "edge.h"
#include "vertex.h"
#include "vector/vector.h"


template <typename Tv, typename Te> class graphicMatrix : public graphic<Tv,Te>{
    private: 
        vector< vertex<Tv> > V; /*顶点集*/
        vector< vector< edge<Te>* > > E; /*边集*/
    public:
        graphicMatrix() {this->n=this->e=0;}
        ~graphicMatrix(){
            for(int i=0;i<this->n;++i){
                for(int j=0;j<this->n;++j)
                    delete E[i][j];
            }
        }
        Tv remove(int r){
            for(int i=0;i<this->n;++i)
            if(exists(r,i)) {delete E[r][i];V[i].inDegree--;this->e--;}
            E.remove(r); Tv data = getVertex(r); 
            V.remove(r); this->n--;
            for(int i=0;i<this->n;++i)
            if(edge<Te>* x = E[i].remove(r)) {delete x,V[i].outDegree--;this->e--;}
            return data;
        }
        Tv& getVertex(int r){return V[r].data;}
        int getInDegree(int r) {return V[r].inDegree;}
        int getOutDegree(int r) {return V[r].outDegree;}
        int getFirstNbr(int r) {return getNextNbr(r,this->n);}
        int getNextNbr(int v,int u){   /*逆序查找,区间是[0,u)*/
            while((0<=u)&&exists(v,--u)); return u;
        }
        VStatus& getStatus(int r) {return V[r].status;}
        int& getDTime(int r) {return V[r].dTime;}
        int& getFTime(int r) {return V[r].fTime;}
        int& getParent(int r) {return V[r].parent;}
        int& getPriority(int r) {return V[r].priority;}
        bool exists(int v,int u){ return (0<=v&&v<this->n&&0<=u&&u<this->n&&E[v][u]!=NULL); }
        int insertV(Tv const& d){   /*插入顶点*/
            for(int i=0;i<this->n;++i) E[i].insert( (edge<Te>*) NULL );
            this->n++;    /*顶点个数加一*/
            E.insert(vector< edge<Te>* >(this->n,this->n,(edge<Te>*) NULL));
            return V.insert(vertex<Tv>(d));
        }
        void insertE(Te const& edata,int v,int u,int w){    /*插入边*/
            if(exists(v,u)) return ;
             E[v][u] = new edge<Te>(edata,w);
             this->e++;   /*更新边数*/
             V[v].outDegree++; V[u].inDegree++;
        }
       Te remove(int v, int u){
           Te edata = getEdge(v,u); delete E[v][u]; E[v][u] = NULL;
           V[v].outDegree--; V[u].inDegree--; this->e--;  /*减少出入度，减少边总数*/
           return edata;
       }
       Etype& getType(int v,int u) { return E[v][u]->type;}
       Te& getEdge(int v,int u) {return E[v][u]->data;}
       int& getWeight(int v,int u) {return E[v][u]->weight;}
};