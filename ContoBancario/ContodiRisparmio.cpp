#include "conto.h"

ContoDiRisparmio::ContoDiRisparmio(const double& saldoInziale): 
    ContoBancario(saldoInziale) {};

#include <iostream>
double ContoDiRisparmio::preleva(const double& delta){
    if (delta > getSaldo())
    {
        std::cout << "Il saldo disponibile e' minore dell'importo inserito\n";
        return getSaldo();
    }
    else
        return ContoBancario::preleva(delta); 
}