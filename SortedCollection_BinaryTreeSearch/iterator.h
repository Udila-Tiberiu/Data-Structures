//
// Created by user on 6/4/2023.
//

#ifndef LAB7_ITERATOR_H
#define LAB7_ITERATOR_H

#include <stack>
#include "colectie.h"


class Colectie;
typedef int TElem;

class IteratorColectie
{
    friend class Colectie;

private:
    //constructorul primeste o referinta catre Container
    //iteratorul va referi primul element din container
    IteratorColectie(const Colectie& c);

    //contine o referinta catre containerul pe care il itereaza
    const Colectie& col;

    int poz;
    std::stack<int>stiva;

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

    //returneaza frecventa elementului din container referit de iterator
    //arunca exceptie daca iteratorul nu e valid
    TElem frecventa() const;


};



#endif //LAB7_ITERATOR_H
