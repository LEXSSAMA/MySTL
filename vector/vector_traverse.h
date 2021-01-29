#pragma once
template <typename T> template <typename VST> 
void vector<T>::traverse (VST & visit){
	for(int i=0;i<_size;++i)
		visit(_elem[i]);
}
