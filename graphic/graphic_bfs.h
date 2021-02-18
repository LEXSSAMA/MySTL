#pragma once

template <typename Tv , typename Te >
void graphic<Tv,Te>::bfs(int s){
    reset(); int clock = 0; int v = s;
    do{
        if(UNDISCOVERED == getStatus(v))
            BFS(v,clock);
    }while(s != (v = (++v % n)));
}

template <typename Tv,typename Te> 
void graphic<Tv,Te>::BFS(int v, int& clock){
    queue<int> Q; Q.enqueue(v); getStatus(v) = DISCOVERED;
    while(!Q.empty()){
        v = Q.dequeue(); getDTime(v) = ++clock;
        for(int u = getFirstNbr(v);-1<u;u = getNextNbr(v,u)){
            if(UNDISCOVERED == getStatus(u)){
                getStatus(u) = DISCOVERED; Q.enqueue(u);
                getType(v,u) = TREE; getParent(u) = v;
            }else
                getType(v,u) = CROSS;
        }
        getStatus(v) = VISITED;
    }
}