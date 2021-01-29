/*二分查找，前提是有序向量*/
template <typename T> static Rank vector<T>::binsearch(T* S, T const& e, Rank lo, Rank hi){
	while(lo < hi){	/*每步迭代要做两次判断，有三个分支*/
		Rank mid = (lo + hi) >> 1;
		if(S[mid]<e) lo = mid + 1;
		else if (e<S[mid]) hi = mid;
		else 
			return mid;
	}
	return -1;
}
