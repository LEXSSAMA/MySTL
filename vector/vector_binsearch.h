#pragma once
/*二分查找，前提是有序向量*/
/*复杂度:O(1.50logn)*/
/*找到e返回其秩，找不到则返回-1,比较两次*/
template <typename T> static Rank binSearch_A(T* S, T const& e, Rank lo, Rank hi){
	while(lo < hi){	/*每步迭代要做两次判断，有三个分支*/
		Rank mid = (lo + hi) >> 1;
		if(S[mid]<e) lo = mid + 1;
		else if (e<S[mid]) hi = mid;
		else 
			return mid;
	}
	return -1;
}
/*找到e返回其秩，找不到则返回-1,只比较一次*/
template <typename T> static Rank binSearch_B(T* S, T const& e, Rank lo, Rank hi){
	while(1 < hi-lo){	/*每步迭代要做一次判断，有两个分支*/
		Rank mid = (lo + hi) >> 1;
		(e < S[mid])? hi = mid : lo = mid;
	}
	return (e==S[lo])?lo:-1;
}

/*约定search()总是返回不大于e的最后一个元素m,m的后继为M==大于e的第一个元素*/
template <typename T> static Rank binSearch(T* S,T const& e,Rank lo,Rank hi){
	while (lo<hi){	/*当lo==hi是终止*/
		Rank mid = (lo+hi)>>1;
		(e<S[mid])? hi = mid: lo = mid+1;	/*假设开始搜索的区间为[0,n)即初始时lo=0,hi=n,保证[0,lo)已经永远小于等于e,同时保证(hi,n)永远大于e*/
	}
	return lo-1;	/*返回不大于e的最后一个元素的秩*/
}
