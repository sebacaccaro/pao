#include "conto.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(){
    ContoCorrente c1;
    ContoCorrente c2(20,2);

    //cout << "Saldo c1: " << c1.deposita(0) << endl;
    //cout << "Saldo c2: " << c2.deposita(0) << endl;

    cout << "Preleva su c1: ";
    double pre;
    cin >> pre;
    cout << c1.preleva(pre) << endl;

    cout << "Deposita su c2: ";
    double dep;
    cin >> dep;
    cout << c2.deposita(dep) << endl;
}