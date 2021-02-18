#pragma once

template <typename Tv, typename Te>
void graphic<Tv,Te>::dfs(int s){
    reset(); int v = s; int clock = 0;
    do{
        if(UNDISCOVERED == getStatus(v))
            DFS(v,clock);
    }while (s != (v = (++v % n)));
}

template <typename Tv , typename Te>
void graphic<Tv,Te>::DFS(int v , int& clock){
    getStatus(v) = DISCOVERED; getDTime(v) = ++clock;
    for(int u = getFirstNbr(v); -1<u; u = getNextNbr(v,u)){
        switch(getStatus(u)){
            case UNDISCOVERED : 
                getType(v,u) = TREE; getParent(u) = v; DFS(u,clock); break;
            case DISCOVERED :
                getType(v,u) = BACKWARD; break;
            case VISITED :
                getType(v,u) = getDTime(v) < getDTime(u) ? FORWARD : CROSS; break;
        }
    }
    getStatus(v) = VISITED; getFTime(v) = ++clock;
}
