//
// Created by user on 5/22/2023.
//

#include "testScurt.h"
#include <cassert>
#include "multime.h"
#include "iterator.h"

void testAll() { //apelam fiecare functie sa vedem daca exista
    Multime m;
    assert(m.vida() == true);
    assert(m.dim() == 0); //adaug niste elemente
    assert(m.adauga(5)==true);
    assert(m.adauga(1)==true);
    assert(m.adauga(10)==true);
    assert(m.adauga(7)==true);
    assert(m.adauga(1)==false);
    assert(m.adauga(10)==false);
    assert(m.adauga(-3)==true);
    assert(m.dim() == 5);
    assert(m.cauta(10) == true);
    assert(m.cauta(16) == false);
    assert(m.sterge(1) == true);
    assert(m.sterge(6) == false);
    assert(m.dim() == 4);

    Multime m2;
    assert(m2.vida() == true);
    m2.reuniune(m);
    assert(m2.dim() == 4);
    m2.reuniune(m);
    assert(m2.dim() == 4);
    assert(m.adauga(11) == true);
    m2.reuniune(m);
    assert(m2.dim() == 5);
    Multime m3;
    m2.reuniune(m3);
    assert(m3.vida() == true);
    assert(m2.dim() == 5);


    IteratorMultime im = m.iterator();
    im.prim();
    int s = 0;
    while (im.valid()) {
        TElem e = im.element();
        s += e;
        im.urmator();
    }
    assert(s == 30);

}
