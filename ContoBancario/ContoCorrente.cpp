#include "conto.h"

ContoCorrente::ContoCorrente(const double& saldoIniziale,const double& soldiOperazione):
    ContoBancario(saldoIniziale), fisso(soldiOperazione) {};

double ContoCorrente::deposita(const double& delta){
    return ContoBancario::deposita(delta - fisso);
}

double ContoCorrente::preleva(const double& delta){
    return ContoBancario::preleva(delta + fisso);
}