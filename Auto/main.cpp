#include "auto.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){
    Auto A(50);
    Benzina B(50,true);
    Benzina C(50,false);
    Diesel D(50);

    cout << A.tassa() << endl;
    cout << B.tassa() << endl;
    cout << C.tassa() << endl;
    cout << D.tassa() << endl;

    cout << endl;

    Auto* A1 = &A;
    Auto* B1 = &B;
    Auto* C1 = &C;
    Auto* D1 = &D;

    cout << A1->tassa() << endl;
    cout << B1->tassa() << endl;
    cout << C1->tassa() << endl;
    cout << D1->tassa() << endl;

    cout << endl;

    ACI pd;
    pd.addAuto(A1);
    pd.addAuto(B1);
    pd.addAuto(C1);
    pd.addAuto(D1);

    cout << pd.IncassaBolli() << endl;
}