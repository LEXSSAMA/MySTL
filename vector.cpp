#include<algorithm>
#include<new>
#define DEFAULT_CAPACITY 3
typedef int Rank;
template <typename T> class vector{
	private: 
		Rank _size ; int _capacity ; T* _elem;
	protected:
		/*...内部函数...*/
	public:
		/*...构造函数*/

		vector(int c = DEFAULT_CAPCITY){ /*默认*/
			_elem = new T[_capacity = c]; _size = 0;
		}
		vector(T const* A, Rank lo, Rank hi){	/*数组之间的复制*/
			copyFrom(A,lo,hi);
		}
		vector(vector<T> const& V, Rank lo, Rank hi){ /*向量区间的复制*/
			copyFrom(V._elem,lo,hi);
		}
		vector(vector<T> const& V){	/*向量整体复制*/
			copyFrom(V._elem,0,V._size);
		}

		/*...析构函数*/

		~vector(){	/*释放内部空间*/
			delete[] _elem;
		}

		T& operator[] (Rank r) {	/*重载下标操作符[] --> non-const*/
			return _elem[r];
		}

		void expand();

		void copyFrom(T const* A,Rank lo, Rank hi);

		Rank insert(Rank r,T const& e);

		const T& operator[] (Rank r) const {	/*重载下标操作符[] --> const*/
			return _elem[r];
		}

		int remove(Rank lo,Rank hi);	/*区间删除*/

		T remove(Rank r);	/*删除单个元素*/

		Rank find(T const& e, Rank lo, Rank hi) const;

		int deduplicate();	/*无序向量去重*/

		template <typename VST> void traverse(VST & visit);
		
		int disordered() const;

		int uniquify();

		Rank search(const T& e, Rank lo,Rank hi);	
};


template <typename T> /*T为基本类型，或者已经重载赋值操作符号*/
void vector<T>::copyFrom (T const* A, Rank lo, Rank hi){
	_elem = new [_capacity = 2*(hi-lo)];	/*分配空间*/
	_size = 0;	/*规模清零*/
	while(lo<hi){	/*将A[lo,hi)内的元素，逐一复制到_elem[0,hi-lo)*/
		_elem[size++] = A[lo++];
	}
}


template <typename T> void vector<T>::expand(){
	if(_size<_capacity) return ;	/*尚未满员时,不必扩张*/
	_capacity = max(_capacity,DEFAULT_CAPACITY);	/*不低于最小容量*/
	T* oldElem = _elem ; _elem = new [_capacity<<=1]; /*容量加倍*/
	for(int i=0;i<_size;++i){
		_elem[i] = oldElem[i];
	}
	delete[] oldElem;	/*释放原空间*/
}

template <typename T> Rank vector<T>::insert(Rank r, T const& e){	/*插入操作*/
	expand();
	for(int i=_size;i>r;--i){	/*自后向前*/
		_elem[i] = _elem[i-1];	/*后继元素顺次后移一个单位*/
	}
	_elem[r] = e; ++_size; return r;	/*置入新元素，更新容量，返回秩*/
}

template <typename T> int  vector<T>::remove(Rank lo, Rank hi){	/*区间删除*/
			if(lo == hi)	return 0;
			while(hi<_size){	/*将hi后方元素前移动(如果有元素的话)*/
				_elem[lo++] = _elem[hi++];
			}
			_size = lo;	shrink();	/*更新规模，有必要的话缩容*/
			return hi-lo;	/*返回被删除的元素个数*/
}

template <typename T> T vector<T>::remove(Rank r){
	T e = _elem[r];	/*备份*/
	remove(r,r+1);	/*利用区间删除来删除单个元素,将单个元素视作区间删除的特例*/
	return e;
}


template <typename T> Rank vector<T>::find(T const& e , Rank lo , Rank hi) const{
	while( (lo<hi--) && (e!=_elem[hi]) );	/*逆向查找,hi<lo意味着失败，否则hi即为命中者的Rank,(多次命中时，返回最大的Rank)*/
	return hi;
}
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

template <typename T> template <typename VST> 
void vector<T>::traverse (VST & visit){
	for(int i=0;i<_size;++i)
		visit(_elem[i]);
}

template <typename T> vector<T>::disordered(){
	int n = 0;	/*相邻逆序对的计数器*/
	for(int i=1;i<_size;++i)
		n += (_elem[i-1]>_elem[i]);
	return n;
}

/*有序向量去重复*/
template <typename T> vector<T>::uniquify(){
	Rank i = 0; Rank j = 0;
	while(++j<_size){
		if(_elem[i]!=_elem[j]) _elem[++i] = _elem[j];
	}
	_size = ++i; shrink();	/*有必要的话缩减容量shrink()*/
	return j-i;
}

/*有序向量的搜索的统一接口*/
template <typename T> vector<T>::search(T const& e, Rank lo , Rank hi){
	return (rand()%2) ? binSearch(_elem,e,lo,hi) : fibSearch(_elem,e,lo,hi);
}
