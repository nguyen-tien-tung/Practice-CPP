#include<string>
#include<iostream>
#include "my_vector.h"

using namespace std;

namespace MyVector {

  template<class T>
  const int TungVector<T>::MIN_CAPACITY = 16;
  template<class T>
  const int TungVector<T>::GROWTH_FACTOR = 2;
  template<class T>
  const int TungVector<T>::SHRINK_FACTOR = 4;

  template<class T>
  TungVector<T>::TungVector(T array[]) : _size(array.length()), _capacity(MIN_CAPACITY) {
    // make_shared _arr and assign array values
    _arr = std::shared_ptr<T[]>(new T[_capacity] {0}, std::default_delete<T[]>());
    resizeArray(_size);
    for (int i = 0; i < array.length(); i++){
      _arr.get()[i] = array[i];
    }
  }

  template<class T>
  TungVector<T>::TungVector(int wantedCapacity) : _size(0), _capacity(MIN_CAPACITY) {
    _arr = std::shared_ptr<T[]>(new T[_capacity] {0}, std::default_delete<T[]>());
    resizeArray(wantedCapacity);
  }

  template<class T>
  void TungVector<T>::resizeArray(int wantedCapacity){
    if(wantedCapacity <= MIN_CAPACITY || ((wantedCapacity >= _capacity / SHRINK_FACTOR) && (wantedCapacity <= _capacity)))
    // * No need to shrink or grow
      return;
    else if (wantedCapacity < _capacity){
      // * Shrink by SHRINK_FACTOR
      cout << "Shrink" << endl;
      while(_capacity / SHRINK_FACTOR > wantedCapacity){
        _capacity = _capacity / SHRINK_FACTOR;
      }
      std::shared_ptr<T[]> newArr(new T[_capacity] {0}, std::default_delete<T[]>());
      for (int i = 0; i < _capacity; i++)
      {
        newArr.get()[i] = _arr.get()[i];
      }
      _arr = newArr;
    }
    else {
      // * Need to grow by GROW_FACTOR
      cout << "Grow" << endl;
      int i = 1;
      for (; MIN_CAPACITY * GROWTH_FACTOR * i < wantedCapacity; i++){
      }
      int oldCapacity = _capacity;
      _capacity = MIN_CAPACITY * GROWTH_FACTOR * i;
      std::shared_ptr<T[]> newArr(new T[_capacity] {0}, std::default_delete<T[]>());
      for (int i = 0; i < oldCapacity; i++)
      {
        newArr[i] = _arr.get()[i];
      }
      _arr = newArr;
    }
    _size = wantedCapacity;
  }

  template<class T>
  int TungVector<T>::getSize(){
    return _size;
  }

  template<class T>
  int TungVector<T>::getCapacity(){
    return _capacity;
  }

  template<class T>
    bool TungVector<T>::isEmpty(){
        return _size == 0;
    }

  template<class T>
  void TungVector<T>::push(T x){
    resizeArray(_size + 1);
    _arr.get()[_size] = x;
    _size++;
  }

  template<class T>
  T TungVector<T>::pop(){
    T res = *(_arr + _size);
    *(_arr + _size) = NULL;
    resizeArray(_size - 1);
    return res;
  }

  template<class T>
  void TungVector<T>::prepend(T x){
    resizeArray(_size + 1);
    T temp = x;
    for (int i = 0; i < _size + 1; i++)
    {
      T currentValue = _arr.get()[i];
      _arr.get()[i] = temp;
      temp = currentValue;
    }
  }

  template <class T>
  void TungVector<T>::insert(int index, T value){
    if (index > _size || index < 0)
      return;
    
    resizeArray(_size + 1);
    T temp = value;
    for (int i = index; i < _size + 1; i++){
      T currentValue = _arr.get()[i];
      _arr.get()[i] = temp;
      temp = currentValue;
    }
    _size++;
  }

  template<class T>
  void TungVector<T>::remove(int index){
    for (int i = index; i < _size - 1; i ++){
      _arr.get()[i] = _arr.get()[i + 1];
    }
    resizeArray(_size - 1);
  }

  template<class T>
  T TungVector<T>::getValueAt(int index){
    if(index >= _size || index < 0)
      throw std::out_of_range("Index out of range");
    return _arr.get()[index];
  }

  template<class T>
  // ! Only work with types comparable by "==" sign
  int TungVector<T>::find(T value){
    for (int i = 0; i < _size; i++){
      if(_arr.get()[i] == value){
        return i;
      }
    }
    return -1;
  }
}
