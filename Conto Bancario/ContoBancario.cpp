#include "conto.h"

ContoBancario::ContoBancario(const double& sommaIniziale): saldo(sommaIniziale){};

double ContoBancario::deposita(const double& delta){
    saldo += delta;
    return saldo;
}

double ContoBancario::preleva(const double& delta){
    saldo -= delta;
    return saldo;
}
