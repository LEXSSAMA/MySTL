#pragma once

template <typename T> 
void vector<T>::sort (Rank lo,Rank hi){
    switch (2){
    case 1:
        bubbleSort(_elem,lo,hi);  
        break;
    case 2:
        mergeSort(_elem,lo,hi);
        break;
    }
}