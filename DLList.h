#ifndef DLList_H
#define DLList_H

template<class T>
class dList{

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

  nodo* now;

  /*
  IMPLEMENTO ITERATORE
  */

public:
  //Costruttori
  dList(int k, const T& t); // lista di k nodi tutti con valori k
  dList(); //lista vuota
  //Void
  void insertFront(const T&); //inserisce valore alla fine
  void insertBack(const T&); //Inserisce valore all'inizio
  //Operatori
  bool operator<(const dList<T>&) const; // Ordinamento lessicografico
};










#endif
