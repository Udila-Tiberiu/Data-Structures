#include "testScurt.h"
#include "colectie.h"
#include "iterator.h"
#include <cassert>
#include <iostream>

using namespace std;

void testAll() {
    Colectie c;
    assert(c.dim() == 0);
    assert(c.vida() == true);

    c.adauga(5);
    c.adauga(6);
    c.adauga(0);
    c.adauga(5);
    c.adauga(10);
    c.adauga(8);
    assert(c.dim() == 6);
    assert(c.nrAparitii(5) == 2);

    assert(c.sterge(5) == true);
    assert(c.dim() == 5);

    assert(c.cauta(6) == true);
    assert(c.vida() == false);

    c.adaugaAparitiiMultiple(3, 6);
    assert(c.dim() == 8);
    assert(c.nrAparitii(6) == 4);

    c.adaugaAparitiiMultiple(2,2);
    assert(c.dim() == 10);
    assert(c.nrAparitii(2) == 2);

    try{
        c.adaugaAparitiiMultiple(-2, 4);
        assert(false);
    }
    catch(exception&) {
        assert(true);
    }

    IteratorColectie ic = c.iterator();
    assert(ic.valid() == true);
    while (ic.valid()) {
        ic.element();
        ic.urmator();
    }
    assert(ic.valid() == false);
    ic.prim();
    assert(ic.valid() == true);
}
