#pragma once
template <typename T> T vector<T>::remove(Rank r){
	T e = _elem[r];	/*备份*/
	remove(r,r+1);	/*利用区间删除来删除单个元素,将单个元素视作区间删除的特例*/
	return e;
}
