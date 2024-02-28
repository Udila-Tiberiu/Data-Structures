//
// Created by user on 5/09/2023.
//

#ifndef LAB3_ITERATOR_H
#define LAB3_ITERATOR_H

#include "list.h"

class IteratorLP{
    friend class Lista;
private:

    //constructorul primeste o referinta catre Container
    //iteratorul va referi primul element din container
    IteratorLP(const Lista& lista);

    //contine o referinta catre containerul pe care il itereaza
    const Lista& list;

    //nodul curent din lista
    Node* currentNode;



public:

    //reseteaza pozitia iteratorului la inceputul containerului
    void prim();

    //muta iteratorul in container
    // arunca exceptie daca iteratorul nu e valid
    void urmator();

    //verifica daca iteratorul e valid (indica un element al containerului)
    bool valid() const;

    //returneaza valoarea elementului din container referit de iterator
    //arunca exceptie daca iteratorul nu e valid
    TElem element() const;

    //muta elementul curent referit de iterator k pasi inainte, sau face iteratorul nevalid in cazul in care
    //exista mai putin de k elemente ramase in lista
    //arunca exeptie in cazul in care iteratorul este nevaid sau in cazul in care k este zero sau negativ
    void kPasi(int k);

};




#endif //LAB3_ITERATOR_H
