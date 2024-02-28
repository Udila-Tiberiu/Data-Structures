//
// Created by user on 6/4/2023.
//

#include "testScurt.h"
#include "colectie.h"
#include "iterator.h"
#include <cassert>

void testAll() {
    Colectie c{rel};
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

    Colectie c1{ rel };
    c1.adauga(5);
    c1.adauga(6);
    c1.adauga(0);
    assert(c1.dim() == 3);
    assert(c1.elementeCuFrecventaData(1) == 3);
    assert(c1.elementeCuFrecventaData(2) == 0);
    c1.adauga(6);
    assert(c1.dim() == 4);
    assert(c1.elementeCuFrecventaData(2) == 1);

    try{
        int x = c1.elementeCuFrecventaData(0);
        assert(false);
    } catch(std::exception& ) {
        assert(true);
    }
    try{
        int x = c1.elementeCuFrecventaData(-2);
        assert(false);
    } catch(std::exception& ) {
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