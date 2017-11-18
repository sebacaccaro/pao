#include "auto.h"

/////////////////////
//       AUTO      //
/////////////////////

int Auto::euro_cv = 5;

Auto::Auto(int iCv): cv(iCv){};

int Auto::tassa(){
    return cv*euro_cv;
}

/////////////////////
//       DIESEL    //
/////////////////////

int Diesel::add_fiscale = 100;

Diesel::Diesel(int iCv): Auto(iCv){};

int Diesel::tassa(){
    return Auto::tassa() + add_fiscale;
}

/////////////////////
//       BENZINA   //
/////////////////////

Benzina::Benzina(int iCv, bool E5): Auto(iCv), Euro5(E5){};

int Benzina::detrazione = 50;

int Benzina::tassa(){
    if(Euro5)
        return Auto::tassa() - detrazione;
    return
        Auto::tassa();
}

/////////////////////
//       ACI       //
/////////////////////

void ACI::addAuto(Auto* a){
    lista.push_back(a);
}

int ACI::IncassaBolli(){
    vector<Auto*>::iterator i;
    int sum = 0;
    for(i = lista.begin(); i < lista.end(); i++)
        sum += (*i)->tassa();
    return sum;
}

