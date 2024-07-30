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
    template<size_t N>
    TungVector(T (&array)[N]);
    TungVector(int capacity);

    void resizeArray(int wantedCapacity);

    int getSize();
    int getCapacity();
    bool isEmpty();
    void push(T x);
    T pop();
    void prepend(T x);
    void insert(int index, T value);
    void deleteAt(int index);
    void remove(T value);
    T getValueAt(int index);
    int find(T value);
  };
}