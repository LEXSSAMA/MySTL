#pragma once
template <typename T> Rank vector<T>::insert(Rank r, T const& e){	/*插入操作*/
	expand();
	for(int i=_size;i>r;--i){	/*自后向前*/
		_elem[i] = _elem[i-1];	/*后继元素顺次后移一个单位*/
	}
	_elem[r] = e; ++_size; return r;	/*置入新元素，更新容量，返回秩*/
}

