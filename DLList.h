#ifndef DLList_H
#define DLList_H

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
    iteratore& operator++();
    iteratore& operator--();
  };

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
};



//###############################
//#            NODO             #
//###############################

//Costruttore nuovo nodo
dList<T>::nodo::nodo(const T& t, nodo* nPre, nodo* nNext): info(t), pre(nPre), next(nNext) {};

//###############################
//#            DLIST            #
//###############################

//Costruttore di lista con k nodi identici di con info=T
dList<T>::dList(int k, const T& t){
  if (k == 0)
    return dList<T>(0,0);

  nodo* p = new nodo(T);
  nodo* primo = p;
  k--;
  while(k > 0){
    nodo* q = new nodo(T,p);
    p->next = q;
    p = q;
    k--;
  }
  first = primo;
  last = p;
}

//Ridefinisco il costruttore standard
dList<T>::dList(nodo* f = 0, nodo* l = 0): first(f), last(l) {};

//Controllo se una lista è vuota
bool dList<T>::isEmpty() const{
  return (first == 0);
}

//Inserimento di un valore a inizio lista
void dList<T>::insertFront(const T&){
  if(!isEmpty()){
    nodo* p = new nodo(T,0,first);
    first->pre = p;
    first = p;
  }
  else{
    first = new nodo(T);
    last = first;
  }
}

//Inserimento di un valore a fine lista
void dList<T>::insertBack(const T&){
  if(!isEmpty()){
    nodo* p = new nodo(T,last,0);
    last->next = p;
    last = p;
  }
  else{
    first = new nodo(T);
    last = first;
  }
}

T& dList<T>::operator[](iteratore it) const{
  return it.punt->info;
}
///MANCANO ANCORA DEI METODI!!!!!!!!

//###############################
//#         ITERATORE           #
//###############################

//Overload del ++ prefisso
dList<T>::iteratore& dList<T>::iteratore::operator++(){
  if (punt)
    punt = punt->next;
  return *this;
}

//Overload del -- prefisso
dList<T>::iteratore& dList<T>::iteratore::operator--(){
  if (punt)
    punt = punt->pre;
  return *this;
}

//Overload dell'operatore booleano di ugualianza
bool dList<T>::iteratore::operator==(iteratore) const{

}

#endif
