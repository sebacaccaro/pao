#include "conto.h"

ContoArancio::ContoArancio(ContoCorrente& app, const double& saldoIniziale):
    ContoDiRisparmio(saldoIniziale), appoggio(app){};

double ContoArancio::deposita(const double& delta){
    appoggio.preleva(delta);
    ContoDiRisparmio::deposita(delta);
}

double ContoArancio::preleva(const double& delta){
    if  (getSaldo() != ContoDiRisparmio::preleva(delta))
        appoggio.deposita(delta);
    return getSaldo();
}