#include <stdexcept>
#include <iostream>

#ifndef CARRAY_H
#define CARRAY_H

template<typename T> class Carray {
  T *data;
  int front;
  int count;
public:
  const int size;

  Carray(int);
  ~Carray();

  bool empty() { return count == 0; }
  bool full() { return count == size; }
  int  length() { return count; }
  bool add(const T&);
  bool insert(const T&);
  bool remove(T*);
  void print();
};

template<typename T> Carray<T>::Carray(int sz): size(sz) {
  if (sz<=0) throw std::invalid_argument("size cannot be zero");
  data = new T[sz];
  front = 0;
  count = 0;
}
template<typename T> Carray<T>::~Carray() {
  delete data;
}

// returns true if add was successful, false if the buffer is already full
template<typename T> bool Carray<T>::add(const T &t) {
  if ( full() ) {
    return false;
  } else {
    // find index where insert will occur
    int end = (front + count) % size;
    data[end] = t;
    count++;
    return true;
  }
}

// returns true if there is something to remove, false otherwise
template<typename T> bool Carray<T>::remove(T *t) {
  if ( empty() ) {
    return false;
  } else {
    *t = data[front];
    
    front = front == size ? 0 : front + 1;
    //front = (front == size - 1) ? 0 : front + 1;
    count--;
    return true;
  }
}

// Insert object
template<typename T> bool Carray<T>::insert(const T &t) {
  int end = (front + count) % size;
  data[end] = t;
  front++;
  front = front % size;
  if ( !full() ) {
    count++;
  }
  return true;
}

template<typename T> void Carray<T>::print(){
  std::cout << "Buffer\n"; 
  if ( empty() ){
    std::cout << "Is empty!\n";
  } else {
    for(int i = 0; i < count; i++)
      std::cout << data[(front + i) % size] << " ";
    std::cout << "\n";  
  }
}

#endif



