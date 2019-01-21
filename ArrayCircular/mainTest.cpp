#include <iostream>
#include "carray.h"

int main() {
  std::cout << "Hello World!\n";

  int step = 0;
  int size = 15;
  Carray<int> buff(size);
  buff.print();

  std::cout << "\n";
  std::cout << "Step " << step << "\n";
  step++;
  for(int i = 0; i < buff.size; i++){
    buff.add(i);
  }
  buff.print();

  std::cout << "\n";
  std::cout << "Step " << step << "\n";
  step++;
  for(int i = buff.size; i > 0; i--){
    buff.add(i);
  }
  buff.print();

  std::cout << "\n";
  std::cout << "Step " << step << "\n";
  step++;
  for(int i = buff.size/2; i > 0; i--){
    buff.insert(i);
  }
  buff.print();

  std::cout << "\n";
  std::cout << "Step " << step << "\n";
  step++;
  int r;
  for(int i = buff.size/2; i > 0; i--){
    buff.remove(&r);
  }
  buff.print();

  std::cout << "\n";
  std::cout << "Step " << step << "\n";
  step++;
  for(int i = 0; i < buff.size; i++){
    buff.add(i);
  }
  buff.print();

  std::cout << "\n";
  std::cout << "Step " << step << "\n";
  step++;
  for(int i = 0; i < buff.size; i++){
    buff.insert(i);
  }
  buff.print();
}