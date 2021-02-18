#pragma once

template <typename T>
vector<T>& vector<T>::operator=(vector<T> const& that){
   T* local_elem = new T[that._capacity];
   for(int i=0;i<that._size;++i)
      local_elem[i] = that._elem[i];
   delete[] _elem;
   this->_size = that._size;
   this->_capacity = that._capacity;
   this->_elem = local_elem;
   return *this;
}