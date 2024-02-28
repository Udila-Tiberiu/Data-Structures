//
// Created by user on 5/09/2023.
//

#include "testScurt.h"
#include <cassert>
#include <exception>


#include "list.h"
#include "iterator.h"



using namespace std;

void testAll(){
    Lista lista = Lista();
    assert(lista.dim() == 0);
    assert(lista.vida());

    lista.adaugaSfarsit(1);
    assert(lista.dim() == 1);
    assert(!lista.vida());

    IteratorLP it = lista.cauta(1);
    assert(it.valid());
    assert(it.element() == 1);
    it.urmator();
    assert(!it.valid());
    it.prim();
    assert(it.valid());
    assert(it.element() == 1);

    assert(lista.sterge(it) == 1);
    assert(lista.dim() == 0);
    assert(lista.vida());

    lista.adaugaInceput(1);
    assert(lista.dim() == 1);
    assert(!lista.vida());

    assert(lista.sterge(it) == 1);
    assert(lista.dim() == 0);

    lista.adaugaSfarsit(1);
    lista.adaugaSfarsit(2);
    lista.adaugaSfarsit(3);
    lista.adaugaSfarsit(4);
    assert(lista.dim() == 4);
    it.prim();
    assert(it.element() == 1);
    it.kPasi(2);
    assert(it.element() == 3);
    try{
        it.kPasi(4);
        assert(false);
    } catch(exception&){
        assert(true);
    }
    try{
        it.kPasi(0);
        assert(false);
    } catch(exception&){
        assert(true);
    }
    try{
        it.kPasi(-4);
        assert(false);
    } catch(exception&){
        assert(true);
    }


}


