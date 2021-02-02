#pragma once

template <typename T> void List<T>::sort(Posi(T) p,int n){
    switch (2)
    {
    case 1:
        selectionSort(p,n);
        break;
    case 2:
        mergeSort(p,n);
        break;
    default:
        insertionSort(p,n);
        break;
    }
}