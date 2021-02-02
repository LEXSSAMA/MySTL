#pragma once

template <typename T> template <typename VST>
void List<T>::traverse(VST& visit){
    Posi(T) p = first();
    while(p!=trailer)
        visit(p->data);
}

template <typename T> void List<T>::traverse(void (*visit)(T&)){
    Posi(T) p = first();
        while(p!=trailer)
            visit(p->data);
}