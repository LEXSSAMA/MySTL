#pragma once 
/*有序向量的搜索的统一接口*/
/*约定search()总是返回不大于e的最后一个元素m,m的后继为M==大于e的第一个元素*/
template <typename T> Rank vector<T>::search(T const& e, Rank lo , Rank hi){
	return (rand()%2) ? binSearch(_elem,e,lo,hi) : fibSearch(_elem,e,lo,hi);
}

