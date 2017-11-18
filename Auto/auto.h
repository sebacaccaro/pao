#ifndef AUTO_H
#define AUTO_H

class Auto{
private:
    static int euro_cv;
    int cv;
public:
    Auto(int);
    virtual int tassa();
};

class Diesel: public Auto{
private:
    static int add_fiscale;
public:
    Diesel(int);
    virtual int tassa();
};

class Benzina: public Auto{
private:
    bool Euro5;
    static int detrazione;
public:
    Benzina(int, bool =false);
    virtual int tassa();
};

#include <vector>
using std::vector;
class ACI{
private:    
    vector<Auto*> lista;
public:
    void addAuto(Auto*);
    int IncassaBolli();
};







#endif