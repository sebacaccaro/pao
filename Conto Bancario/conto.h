#ifndef CONTO_H
#define CONTO_H

class ContoBancario{
private:
    double saldo;
public:
    ContoBancario(const double& = 0.0);

    //Operazioni sul conto
    double deposita(const double&);
    double preleva(const double&);
};





















#endif