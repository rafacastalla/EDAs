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
  void insert(const T&);
  bool first(T*);
  bool get(T*, int idx);
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

template<typename T> bool Carray<T>::add(const T &t) {
  if ( full() ) {
    return false;
  } else {
    int end = (front + count) % size;
    data[end] = t;
    count++;
    return true;
  }
}

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

template<typename T> void Carray<T>::insert(const T &t) {
  int end = (front + count) % size;
  data[end] = t;
  front++;
  front = front % size;
  if ( !full() ) {
    count++;
  }
}

template<typename T> bool Carray<T>::first(T *t) {
  if ( empty() ) {
    return false;
  } else {
    *t = data[front];
    return true;
  }
}

template<typename T> bool Carray<T>::get(T *t, int idx) {
  if ( empty() ) {
    return false;
  } else {
    int end = (front + idx) % size;
    *t = data[end];
    return true;
  }
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



