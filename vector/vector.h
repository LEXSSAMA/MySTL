#include<stdlib.h>
#pragma once 
#define DEFAULT_CAPACITY 3
typedef int Rank;
template <typename T> class vector{
	protected:
		/*...内部函数...*/
		Rank _size ; int _capacity ; T* _elem;
		void expand();

		void copyFrom(T const* A,Rank lo, Rank hi);

		void shrink();
	public:
		/*...构造函数*/
		vector(int c = DEFAULT_CAPACITY){ /*默认*/
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
		Rank insert(Rank r,T const& e);
		Rank insert(T const& e){return insert(_size,e);}
		const T& operator[] (Rank r) const {	/*重载下标操作符[] --> const*/
			return _elem[r];
		}
		int remove(Rank lo,Rank hi);	/*区间删除*/
		T remove(Rank r);	/*删除单个元素*/
		Rank find(T const& e) const{return find(e,0,_size);}
		Rank find(T const& e, Rank lo, Rank hi) const;
		int deduplicate();	/*无序向量去重*/
		template <typename VST> void traverse(VST & visit);
		void traverse(void (*visit) (T&));
		int disordered() const;
		int uniquify();
		Rank search(const T& e, Rank lo,Rank hi);	
		void sort(Rank lo,Rank hi);
		void sort(){sort(0,_size);}
		int size() const{return _size;}
		bool empty() const {return !_size;}
		int get(Rank r){ return _elem[r];}
		int put(Rank r,T const& e){
			if(r>=_size)
				return -1;
			_elem[r] = e;
			return 0;
		}
};

#include "vector_implementation.h"
