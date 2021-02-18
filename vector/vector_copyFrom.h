#pragma once 
template <typename T> /*T为基本类型，或者已经重载赋值操作符号*/
void vector<T>::copyFrom (T const* A, Rank lo, Rank hi){
	_elem = new T[_capacity = 2*(hi-lo)];	/*分配空间*/
	_size = 0;	/*规模清零*/
	while(lo<hi){	/*将A[lo,hi)内的元素，逐一复制到_elem[0,hi-lo)*/
		_elem[_size++] = A[lo++];
	}
}