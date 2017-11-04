#ifndef DLList_H
#define DLList_H

#include <iostream>

template<class T>
class dList{
friend class iteratore;
private:

  class nodo{
  public:
    //Costruttori
    nodo(const T&, nodo* = 0, nodo* =0);

    //Attributi
    T info;
    nodo* pre;
    nodo* next;
  };

  nodo* first;
  nodo* last;

public:

  class iteratore{
  friend class dList<T>;
  private:
    dList<T>::nodo* punt;
  public:
    bool operator==(iteratore) const;
    bool operator!=(iteratore) const;
    iteratore& operator++();
    iteratore& operator--();
  };

  static void Print(std::ostream& , const dList<T>&);

  //Costruttori
  dList(int, const T& ); // lista di k nodi tutti con valori k
  dList(nodo* =0, nodo* =0); //lista vuota
  //Void e altri metodi
  bool isEmpty() const;
  void insertFront(const T&); //inserisce valore alla fine
  void insertBack(const T&); //Inserisce valore all'inizio
  //Operatori
  bool operator<(const dList<T>&) const; // Ordinamento lessicografico
  T& operator[](iteratore) const; //overload per l'iteratore
  //Metodi per iteratore
  iteratore outOfBound() const;
  iteratore begin() const;
  iteratore end() const;
};



//###############################
//#            NODO             #
//###############################

//Costruttore nuovo nodo
template<class T>
dList<T>::nodo::nodo(const T& t, nodo* nPre, nodo* nNext): info(t), pre(nPre), next(nNext) {};

//###############################
//#            DLIST            #
//###############################

//Costruttore di lista con k nodi identici di con info=T
template<class T>
dList<T>::dList(int k, const T& t){
  if (k == 0)
    first = last = 0;
  else{
    nodo* p = new nodo(t);
    nodo* primo = p;
    k--;
    while(k > 0){
      nodo* q = new nodo(t,p);
      p->next = q;
      p = q;
      k--;
    }
    first = primo;
    last = p;
  }
}

//Ridefinisco il costruttore standard
template<class T>
dList<T>::dList(nodo* f, nodo* l): first(f), last(l) {};

//Controllo se una lista è vuota
template<class T>
bool dList<T>::isEmpty() const{
  return (first == 0);
}

//Inserimento di un valore a inizio lista
template<class T>
void dList<T>::insertFront(const T& t){
  if(!isEmpty()){
    nodo* p = new nodo(t,0,first);
    first->pre = p;
    first = p;
  }
  else{
    first = new nodo(t);
    last = first;
  }
}

//Inserimento di un valore a fine lista
template<class T>
void dList<T>::insertBack(const T& t){
  if(!isEmpty()){
    nodo* p = new nodo(t,last,0);
    last->next = p;
    last = p;
  }
  else{
    first = new nodo(t);
    last = first;
  }
}

//Overload dell'operatore parentesi quadre
template<class T>
T& dList<T>::operator[](iteratore it) const{
  return it.punt->info;
}

//Iteratore quando eccedo a destra o a sinistra
template<class T>
typename dList<T>::iteratore dList<T>::outOfBound() const{
  iteratore aux;
  aux.punt = 0;
  return aux;
}

//Iteratore che punta al primo elemento della lista
template<class T>
typename dList<T>::iteratore dList<T>::begin() const{
  iteratore aux;
  aux.punt = first;
  return aux;
}

//Iteratore che punta all'ultimo elemento della lista
template<class T>
typename dList<T>::iteratore dList<T>::end() const{
  iteratore aux;
  aux.punt = last;
  return aux;
}

//Stampa una lista
template<class T>
void Print(std::ostream& os, const dList<T>& t) {
  typename dList<T>::iteratore it = t.begin();
  for(it; it != t.outOfBound(); ++it)
    os << t[it] << " ";
}

//Confronto lessicografico stile dizionario fra 2 liste
template<class T>
bool dList<T>::operator<(const dList<T>& t) const{
  nodo *a = first;
  nodo *b = t.first;
  while (a && b && a->info == b->info) {
    a = a->next;
    b = b->next;
  }
  if (!a)
    return true;
  if (!b)
    return false;
  if (a->info < b->info)
    return true;
  return false;
}

//###############################
//#         ITERATORE           #
//###############################

//Overload del ++ prefisso
template<class T>
typename dList<T>::iteratore& dList<T>::iteratore::operator++(){
  if (punt)
    punt = punt->next;
  return *this;
}

//Overload del -- prefisso
template<class T>
typename dList<T>::iteratore& dList<T>::iteratore::operator--(){
  if (punt)
    punt = punt->pre;
  return *this;
}

//Overload dell'operatore booleano di ugualianza
template<class T>
bool dList<T>::iteratore::operator==(iteratore it) const{
  return (punt == it.punt);
}

//Overload dell'operatore booleano di disuguaglianza
template<class T>
bool dList<T>::iteratore::operator!=(iteratore it) const{
  return (punt != it.punt);
}


#endif
