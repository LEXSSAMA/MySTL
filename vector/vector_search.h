#pragma once 
/*有序向量的搜索的统一接口*/
template <typename T> Rank vector<T>::search(T const& e, Rank lo , Rank hi){
	return (rand()%2) ? binSearch(_elem,e,lo,hi) : fibSearch(_elem,e,lo,hi);
}

