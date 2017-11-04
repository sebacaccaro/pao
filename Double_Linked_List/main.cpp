#include "DLList.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){
  dList<int> lA(5,7);
  dList<int> lB(5,7);
  lA.insertBack(1);
  lB.insertBack(2);
  cout << "Lista A --> ";
  Print(std::cout,lA);
  cout << endl;
  cout << "Lista B --> ";
  Print(std::cout,lB);
  cout << endl;
  cout << "lA < lB? -->" << (lA < lB)<<endl;
  cout << "lB < lA? -->" << (lB < lA)<<endl;
}
