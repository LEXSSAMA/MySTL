#pragma once
/*有序向量去重复*/
template <typename T> int vector<T>::uniquify(){
	Rank i = 0; Rank j = 0;
	while(++j<_size){
		if(_elem[i]!=_elem[j]) _elem[++i] = _elem[j];
	}
	_size = ++i; shrink();	/*有必要的话缩减容量shrink()*/
	return j-i;
}
