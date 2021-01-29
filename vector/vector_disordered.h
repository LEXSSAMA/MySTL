#pragma once
template <typename T> int vector<T>::disordered() const{
	int n = 0;	/*相邻逆序对的计数器*/
	for(int i=1;i<_size;++i)
		n += (_elem[i-1]>_elem[i]);
	return n;
}
