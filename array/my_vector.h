#pragma once
#include <memory>

namespace MyVector {
  template<class T> class TungVector{
    static const int MIN_CAPACITY;
    static const int GROWTH_FACTOR;
    static const int SHRINK_FACTOR;

    std::shared_ptr<T[]> _arr;
    int _capacity;
    int _size;
  public:
    TungVector(T array[]);
    TungVector(int capacity);

    void resizeArray(int wantedCapacity);

    int getSize();
    int getCapacity();
    void push(T x);
    T pop();
    void prepend(T x);
    void insert(int index, T value);
    void remove(int index);
    T getValueAt(int index);
    int find(T value);
  };
}