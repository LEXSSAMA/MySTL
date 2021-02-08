#pragma once

#include "math/math.h"

template <typename T>  int binTree<T>::updateHeight(binNodePos(T) x){
    return x->height = 1+max(stature(x->leftchild),stature(x->rightchild));
}