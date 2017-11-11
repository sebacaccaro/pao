#include "conto.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){
    ContoDiRisparmio c1(30);
    ContoDiRisparmio c2(20);

    cout << "Saldo c1: " << c1.getSaldo() << endl;
    cout << "Saldo c2: " << c2.getSaldo() << endl;

    cout << "Preleva su c1: ";
    double pre;
    cin >> pre;
    cout << c1.preleva(pre) << endl;

    cout << "Deposita su c2: ";
    double dep;
    cin >> dep;
    cout << c2.deposita(dep) << endl;
}