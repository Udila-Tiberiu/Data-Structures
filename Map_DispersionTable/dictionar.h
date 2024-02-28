//
// Created by user on 5/24/2023.
//

#ifndef LAB6_DICTIONAR_H
#define LAB6_DICTIONAR_H

#define NULL_TVALOARE (-1)
typedef int TCheie;
typedef int TValoare;

class IteratorDictionar;

#include <utility>
typedef std::pair<TCheie,TValoare> TElem;

typedef struct Nod {
    TElem info;
    Nod* next;
} Nod;

typedef struct HashTable {
    Nod** T;
    int cap, size;
} HashTable;


class Dictionar {
    friend class IteratorDictionar;

private:
    HashTable ht;

    int hashCode(TCheie c) const;
    int hashDivisionFn(TCheie c) const;

    void resize();

public:

    // constructorul implicit al dictionarului
    Dictionar();

    // adauga o pereche (cheie, valoare) in dictionar
    //daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
    // daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
    TValoare adauga(TCheie c, TValoare v);

    //cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
    TValoare cauta(TCheie c);

    //sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
    TValoare sterge(TCheie c);

    //returneaza numarul de perechi (cheie, valoare) din dictionar
    int dim() const;

    //verifica daca dictionarul e vid
    bool vid() const;

    // se returneaza iterator pe dictionar
    IteratorDictionar iterator() const;


    // destructorul dictionarului
    ~Dictionar();

    //adauga in dictionarul curent toate perechile din d a caror cheie nu se afla deja in dictionar
    //returneaza numarul de perechi adaugate
    int adaugaInexistente(Dictionar &d);

};

#endif //LAB6_DICTIONAR_H
