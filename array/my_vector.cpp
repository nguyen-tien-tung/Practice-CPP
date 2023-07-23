#include<string>
#include<iostream>
#include "my_vector.h"

using namespace std;

namespace MyVector {

  template<class T>
  static const int TungVector<T>::MIN_CAPACITY = 16;
  template<class T>
  static const int TungVector<T>::GROWTH_FACTOR = 2;
  template<class T>
  static const int TungVector<T>::SHRINK_FACTOR = 4;

  template<class T>
  TungVector<T>::TungVector(T array[]) {
    // make_unique _arr and assign array values
    _capacity = MIN_CAPACITY;
    _size = array.length();
    resizeArray(_size);
    for (int i = 0; i < array.length(); i++){
      *(_arr + i) = array[i];
    }
  }

  template<class T>
  TungVector<T>::TungVector(int wantedCapacity) {
    _capacity = MIN_CAPACITY;
    _size = 0;
    resizeArray(wantedCapacity);
  }

  template<class T>
  void TungVector<T>::resizeArray(int wantedCapacity){
    if(wantedCapacity <= MIN_CAPACITY || wantedCapacity == _capacity || wantedCapacity >= _capacity / SHRINK_FACTOR)
    // * No need to shrink
      return;
    else if (wantedCapacity < _capacity){
      // * Shrink by SHRINK_FACTOR
      while(_capacity / SHRINK_FACTOR > wantedCapacity){
        _capacity = _capacity / SHRINK_FACTOR;
      }
      std::unique_ptr<T[]> newArr = std::make_unique<T[]>(_capacity);
      for (int i = 0; i < _capacity; i++)
      {
        *(newArr + i) = *(_arr + i);
      }
      _arr = newArr;
    }
    else {
      // * Need to grow by GROW_FACTOR
      int i = 1;
      for (; MIN_CAPACITY * GROWTH_FACTOR * i < wantedCapacity; i++){
      }
      int oldCapacity = _capacity;
      _capacity = MIN_CAPACITY * GROWTH_FACTOR * i;
      std::unique_ptr<T[]> newArr = std::make_unique<T[]>(_capacity);
      for (int i = 0; i < oldCapacity; i++)
      {
        *(newArr + i) = *(_arr + i);
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
  void TungVector<T>::push(T x){
    resizeArray(_size + 1);
    *(_arr + _size - 1) = x;
  }

  template<class T>
  T TungVector<T>::pop(){
    T res = *(_arr + _size);
    *(_arr + _size) = NULL;
    resizeArray(_size - 1)
    return res;
  }

  template<class T>
  void TungVector<T>::prepend(T x){
    resizeArray(_size + 1);
    T temp = x;
    for (int i = 0; i < _size + 1; i++)
    {
      T currentValue = *(_arr + i);
      *(_arr + i) = temp;
      temp = currentValue;
    }
  }

  template <class T>
  void TungVector<T>::insert(int index, T value){
    if(index >= _size || index < 0)
      return;
    resizeArray(_size + 1);
    T temp = value;
    for (int i = index + 1; i < _size + 1; i++){
      T currentValue = *(_arr + i);
      *(_arr + i) = temp;
      temp = currentValue;
    }
  }

  template<class T>
  void TungVector<T>::remove(int index){
    for (int i = index; i < _size - 1; i ++){
      *(_arr + i) = *(_arr + i + 1);
    }
    resizeArray(_size - 1);
  }

  template<class T>
  T TungVector<T>::getValueAt(int index){
    return *(_arr + index);
  }

  template<class T>
  // ! Only work with types comparable by "==" sign
  int TungVector<T>::find(T value){
    for (const i = 0; i < _size; i++){
      if(*(_arr + i) == value){
        return i;
      }
    }
    return -1;
  }
}

int main(){
}