//
// Created by user on 5/24/2023.
//

#include <cmath>
#include "dictionar.h"
#include "iterator.h"

//Complexitati:
//Caz favorabil: CF
//Caz nefavorabil: CN
//Caz mediu: CM


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
int Dictionar::hashCode(TCheie c) const {
    return abs(c);
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
int Dictionar::hashDivisionFn(TCheie c) const {
    return hashCode(c) % ht.cap;
}

//CF=CN=CM= θ(cap), deci complexitatea este θ(cap).
void Dictionar::resize() {
    int oldCapacity = this->ht.cap;
    this->ht.cap *= 2;
    Nod** newT = new Nod*[this->ht.cap];
    for (int i = 0; i < this->ht.cap; i++) {
        newT[i] = NULL;
    }
    Nod* prevNode = NULL;
    for (int i = 0; i < oldCapacity; i++) {
        Nod* currentNode = this->ht.T[i];
        while (currentNode != NULL) {
            prevNode = currentNode;

            int position = this->hashDivisionFn(currentNode->info.first);

            Nod* newNode = new Nod();
            newNode->info = currentNode->info;
            newNode->next = newT[position];
            newT[position] = newNode;

            currentNode = currentNode->next;
            delete prevNode;
        }
    }
    delete[] this->ht.T;
    this->ht.T = newT;
}

//CF=CN=CM= θ(cap), deci complexitatea este θ(cap).
Dictionar::Dictionar() {
    this->ht.cap = 23;
    this->ht.size = 0;
    this->ht.T = new Nod*[this->ht.cap];
    for (int i = 0; i < this->ht.cap; i++) {
        this->ht.T[i] = NULL;
    }
}

//CF=CN=CM= θ(cap * size), deci complexitatea este θ(cap * size).
Dictionar::~Dictionar() {
    for (int i = 0; i < this->ht.cap; i++) {
        Nod* currentNode = this->ht.T[i];
        Nod* prevNode = NULL;
        while (currentNode != NULL) {
            prevNode = currentNode;
            currentNode = currentNode->next;
            delete prevNode;
        }
    }
    delete this->ht.T;
}

//CF = θ(1) (cand lista este goala)
//CN = CM = θ(size), deci complexitatea este θ(size).
TValoare Dictionar::adauga(TCheie c, TValoare v){
    if (this->ht.size == this->ht.cap - 1) {
        this->resize();
    }
    int position = this->hashDivisionFn(c);
    Nod* currentNode = this->ht.T[position];
    while(currentNode != NULL){
        if(currentNode->info.first == c)break;
        currentNode = currentNode->next;
    }
    if(currentNode != NULL){
        TValoare val = currentNode->info.second;
        currentNode->info.second = v;
        return val;
    }
    else {
        Nod* newNode = new Nod();
        newNode->info.first = c;
        newNode->info.second = v;
        newNode->next = this->ht.T[position];
        this->ht.T[position] = newNode;
        this->ht.size++;
        return NULL_TVALOARE;
    }
}

//CF = θ(1) (cand lista este goala)
//CN = CM = θ(size), deci complexitatea este θ(size).
TValoare Dictionar::cauta(TCheie c){
    int position = this->hashDivisionFn(c);
    Nod* currentNode = this->ht.T[position];
    while (currentNode != NULL) {
        if (currentNode->info.first == c)break;
        currentNode = currentNode->next;
    }
    if(currentNode != NULL)return currentNode->info.second;
    return NULL_TVALOARE;
}

//CF = θ(1) (cand lista este goala)
//CN = CM = θ(size), deci complexitatea este θ(size).
TValoare Dictionar::sterge(TCheie c){
    int position = this->hashDivisionFn(c);
    Nod* currentNode = this->ht.T[position];
    Nod* prevNode = NULL;
    while (currentNode != NULL) {
        if(currentNode->info.first == c)break;
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode != NULL) {
        if (prevNode == NULL) {
            this->ht.T[position] = this->ht.T[position]->next;
        }
        else {
            prevNode->next = currentNode->next;
            currentNode->next = NULL;
        }
        TValoare val = currentNode->info.second;
        delete currentNode;
        this->ht.size--;
        return val;
    }
    return NULL_TVALOARE;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
int Dictionar::dim() const {
    return ht.size;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
bool Dictionar::vid() const{
    return ht.size == 0;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
IteratorDictionar Dictionar::iterator() const {
    return  IteratorDictionar(*this);
}

//CF = θ(d.size * d.size) (cand fiecare cheie din d se afla deja in dictionarul nostru
//CN=CM= θ(d.size * size), deci complexitatea este θ(1).
int Dictionar::adaugaInexistente(Dictionar &d) {
    int nr = 0;
    IteratorDictionar it = d.iterator();
    it.prim();
    while(it.valid()){
        TCheie c = it.element().first;
        TValoare v = it.element().second;
        if(cauta(c) == NULL_TVALOARE){
            nr ++;
            int position = this->hashDivisionFn(c);
            Nod* newNode = new Nod();
            newNode->info.first = c;
            newNode->info.second = v;
            newNode->next = this->ht.T[position];
            this->ht.T[position] = newNode;
            this->ht.size++;
        }
        it.urmator();
    }
    return nr;
}



