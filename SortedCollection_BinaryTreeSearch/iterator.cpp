//
// Created by user on 6/4/2023.
//

#include "iterator.h"
#include "colectie.h"

//CF=CN=CM= θ(h), deci complexitatea este θ(h).
IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
    int nod = col.root;
    while(nod!=null)
    {
        this->stiva.push(nod);
        nod = col.left[nod];
    }
    if(!this->stiva.empty())
    {
        poz = stiva.top();
    }
    else
        poz = null;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
TElem IteratorColectie::element() const{
    if (!valid())
        throw std::exception();
    return col.elements[poz];
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
bool IteratorColectie::valid() const {
    if (col.vida())
        return false;
    return poz != null;
}

//CF=CN=CM= θ(h), deci complexitatea este θ(h).
void IteratorColectie::urmator() {
    if (!valid())
        throw std::exception();
    int nod = this->stiva.top();
    this->stiva.pop();
    if (col.right[nod] != null) {
        nod = col.right[nod];
        while (nod != null) {
            this->stiva.push(nod);
            nod = col.left[nod];
        }
    }
    if (!this->stiva.empty()) {
        poz = this->stiva.top();
    }
    else {
        poz = null;
    }
}

//CF=CN=CM= θ(h), deci complexitatea este θ(h).
void IteratorColectie::prim() {
    while (!this->stiva.empty()) {
        this->stiva.pop();
    }
    int nod = col.root;
    while (nod != null) {
        this->stiva.push(nod);
        nod = col.left[nod];
    }
    if (!this->stiva.empty()) {
        poz = this->stiva.top();
    }
    else {
        poz = null;
    }
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
TElem IteratorColectie::frecventa() const {
    if (!valid())
        throw std::exception();
    return col.frecv[poz];
}
