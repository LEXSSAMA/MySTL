#pragma once 
/*无序向量去重*/
template <typename T> int vector<T>::deduplicate(){
	int oldSize = _size; Rank i = 1;
	while(i<_size){
		if(find(_elem[i],0,i)<0)	/*保证区间[0,i)内的元素都不重复*/
			i++;
		else
			remove(i);
	}
	return oldSize - _size;
}

