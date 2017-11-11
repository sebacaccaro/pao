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

    //Gets
    double getSaldo();
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

class ContoDiRisparmio: public ContoBancario{
public:
    //Costruttori
    ContoDiRisparmio(const double& = 0.0);

    //Operazioni sul conto
    double preleva(const double&);
};

class ContoArancio: public ContoDiRisparmio{
private:
    ContoCorrente& appoggio;
public:
    //Costruttori
    ContoArancio(ContoCorrente&, const double& =0);

    //Operazioni sul conto
    double deposita(const double&);
    double preleva(const double&);

};




















#endif