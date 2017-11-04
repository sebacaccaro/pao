#include "DLList.h"
#include <iostream>


int main(){
  dList<int> lA(5,9);
  dList<int> lB(6,7);
  lA.insertBack(1);
  lA.insertFront(18);
  Print(std::cout,lA);
  std::cout << std::endl;
}
