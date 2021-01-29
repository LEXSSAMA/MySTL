#pragma once
template <typename T> Rank vector<T>::find(T const& e , Rank lo , Rank hi) const{
	while( (lo<hi--) && (e!=_elem[hi]) );	/*逆向查找,hi<lo意味着失败，否则hi即为命中者的Rank,(多次命中时，返回最大的Rank)*/
	return hi;
}
