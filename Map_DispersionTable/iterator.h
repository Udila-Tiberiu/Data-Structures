//
// Created by user on 5/24/2023.
//

#ifndef LAB6_ITERATOR_H
#define LAB6_ITERATOR_H

#include "dictionar.h"

class IteratorDictionar
{
    friend class Dictionar;
private:

    //constructorul primeste o referinta catre Container
    //iteratorul va referi primul element din container
    IteratorDictionar(const Dictionar& d);

    //contine o referinta catre containerul pe care il itereaza
    const Dictionar& dict;
    HashTable ht;
    int currentPoz;
    Nod* currentNod;

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
};

#endif //LAB6_ITERATOR_H
