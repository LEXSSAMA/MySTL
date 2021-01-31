#pragma once
template <typename T> void vector<T>::expand(){
	if(_size<_capacity) return ;	/*尚未满员时,不必扩张*/
	if(_capacity<DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;	/*不低于最小容量*/
	T* oldElem = _elem ; _elem = new T[_capacity<<=1]; /*容量加倍*/
	for(int i=0;i<_size;++i){
		_elem[i] = oldElem[i];
	}
	delete[] oldElem;	/*释放原空间*/
}
