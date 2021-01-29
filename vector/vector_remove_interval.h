#pragma once
template <typename T> int  vector<T>::remove(Rank lo, Rank hi){	/*区间删除*/
			if(lo == hi)	return 0;
			while(hi<_size){	/*将hi后方元素前移动(如果有元素的话)*/
				_elem[lo++] = _elem[hi++];
			}
			_size = lo;	shrink();	/*更新规模，有必要的话缩容*/
			return hi-lo;	/*返回被删除的元素个数*/
}
