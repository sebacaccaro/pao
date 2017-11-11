#include "conto.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){
    ContoCorrente c1(30);
    ContoArancio c2(c1,20);

    cout << "Saldo c1: " << c1.getSaldo() << endl;
    cout << "Saldo c2: " << c2.getSaldo() << endl;

    cout << "Preleva su c2: ";
    double pre;
    cin >> pre;
    c2.preleva(pre);
    cout << "Saldo c1: " << c1.getSaldo() << endl;
    cout << "Saldo c2: " << c2.getSaldo() << endl;

    cout << "Deposita su c2: ";
    double dep;
    cin >> dep;
    c2.deposita(dep);
    cout << "Saldo c1: " << c1.getSaldo() << endl;
    cout << "Saldo c2: " << c2.getSaldo() << endl;
}