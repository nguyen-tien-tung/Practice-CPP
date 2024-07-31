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
  template<size_t N>
  TungVector<T>::TungVector(T (&array)[N]) : _size(N), _capacity(MIN_CAPACITY) {
    // make_shared _arr and assign array values
    cout << "INITIALIZE VECTOR..." << endl;
    cout << N << endl;
    _arr = std::shared_ptr<T[]>(new T[_capacity] {0}, std::default_delete<T[]>());
    resizeArray(_size);
    for (int i = 0; i < N; i++){
      _arr.get()[i] = array[i];
    }
    _size = N;
  }

  template<class T>
  TungVector<T>::TungVector(int wantedCapacity) : _size(0), _capacity(MIN_CAPACITY) {
    _arr = std::shared_ptr<T[]>(new T[_capacity] {0}, std::default_delete<T[]>());
    resizeArray(wantedCapacity);
    _size = wantedCapacity;
  }

  template<class T>
  void TungVector<T>::resizeArray(int wantedCapacity){
    if(wantedCapacity <= MIN_CAPACITY || ((wantedCapacity >= _capacity / SHRINK_FACTOR) && (wantedCapacity <= _capacity)))
      return;
    else if (wantedCapacity < _capacity){
      // * Shrink by SHRINK_FACTOR
      if(wantedCapacity < _capacity / SHRINK_FACTOR){
        cout << "Shrink" << endl;
        _capacity = _capacity / SHRINK_FACTOR;
        std::shared_ptr<T[]> newArr(new T[_capacity] {0}, std::default_delete<T[]>());
        for (int i = 0; i < _capacity; i++)
        {
          newArr.get()[i] = _arr.get()[i];
        }
        _arr = newArr;
      }
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
    T res = _arr.get()[_size];
    _arr.get()[_size] = T();
    resizeArray(_size - 1);
    _size--;
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
    _size++;
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
  void TungVector<T>::deleteAt(int index){
    cout << "REMOVE !!!!!!!" << endl;
    for (int i = index; i < _size - 1; i ++){
      _arr.get()[i] = _arr.get()[i + 1];
    }
    resizeArray(_size - 1);
    _size--;
    cout << "SIZE AFTER RM: " << _size << endl;
  }

  template<class T>
  void TungVector<T>::remove(T value) {
    std::shared_ptr<T[]> newArray(new T[_capacity]);
    int size = 0;
    int initialSize = _size;
    std::cout << "OG SIZE: " << _size << std::endl;
    for (int i = 0; i < initialSize; i++) {
      if (_arr.get()[i] != value) {
        newArray.get()[size] = _arr.get()[i];
        size++;
      }else {
        _size--;
      }
    }
    _arr = newArray;
    for (int i = 0; i < _capacity; i++){
      std::cout << _arr.get()[i] << std::endl;
    }
    resizeArray(size + 1);
    std::cout << "new SIZE: " << _size << std::endl;
  }

  template<class T>
  T TungVector<T>::getValueAt(int index){
    if(index >= _size || index < 0)
      throw std::out_of_range("Index out of range");
    cout << "VALUE AT " << index << " :" << _arr.get()[index] << endl;
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
