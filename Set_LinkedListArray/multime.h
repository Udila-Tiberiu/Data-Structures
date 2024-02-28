//
// Created by user on 5/22/2023.
//

#ifndef LAB4_MULTIME_H
#define LAB4_MULTIME_H

#include "nod.h"
typedef int TElem;

class IteratorMultime;

class Multime {
    friend class IteratorMultime;

private:
    int head;
    int tail;
    Nod *elements;
    int size;
    int cap;
    int firstFreePosition;
    void reajustare();

public:
    //constructorul implicit
    Multime();

    //adauga un element in multime
    //returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
    bool adauga(TElem e);

    //sterge un element din multime
    //returneaza adevarat daca elementul a existat si a fost sters
    bool sterge(TElem e);

    //verifica daca un element se afla in multime
    bool cauta(TElem elem) const;


    //intoarce numarul de elemente din multime;
    int dim() const;

    //verifica daca multimea e vida;
    bool vida() const;

    //returneaza un iterator pe multime
    IteratorMultime iterator() const;

    // destructorul multimii
    ~Multime();

    //adauga toate elementele din multimea b in multimea curenta
    void reuniune(const Multime& b);
};



#endif //LAB4_MULTIME_H
