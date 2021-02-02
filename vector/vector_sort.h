#pragma once

template <typename T> 
void vector<T>::sort (Rank lo,Rank hi){
    switch (rand()%2){
    case 1:
        bubbleSort(_elem,lo,hi);  
        break;
    default:
        mergeSort(_elem,lo,hi);
        break;
    }
}