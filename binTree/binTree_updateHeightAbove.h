#pragma once

template <typename T> void binTree<T>::updateHeightAbove(binNodePos(T) x){
    while(x){updateHeight(x); x=x->parent;}
}