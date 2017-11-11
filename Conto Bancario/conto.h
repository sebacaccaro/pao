#ifndef CONTO_H
#define CONTO_H

class ContoBancario{
private:
    double saldo;
public:
    //Costruttori
    ContoBancario(const double& = 0.0);

    //Operazioni sul conto
    double deposita(const double&);
    double preleva(const double&);
};

class ContoCorrente: public ContoBancario{
private:
    const double fisso;
public:
    //Costruttori
    ContoCorrente(const double& = 0.0,const double& = 1.0);

    //Operazioni sul conto
    double deposita(const double&);
    double preleva(const double&);
};




















#endif