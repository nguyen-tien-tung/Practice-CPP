#pragma once

namespace myVector {
  template<class T> class TungVector{
    static const int MIN_CAPACITY = 16;
    static const int GROWTH_FACTOR = 2;
    static const int SHRINK_FACTOR = 4;

    std::unique_ptr<T[]> _arr;
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