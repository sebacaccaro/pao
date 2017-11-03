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

  nodo* now;

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
  dList(int k, const T& t); // lista di k nodi tutti con valori k
  dList(); //lista vuota
  //Void
  void insertFront(const T&); //inserisce valore alla fine
  void insertBack(const T&); //Inserisce valore all'inizio
  //Operatori
  bool operator<(const dList<T>&) const; // Ordinamento lessicografico
  T& operator[](iteratore); //overload per l'iteratore
  //Metodi per iteratore
  iteratore begin();//???
  iteratore end();//??
};










#endif
