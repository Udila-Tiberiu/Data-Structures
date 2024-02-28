//
// Created by user on 5/24/2023.
//

#include "nod.h"

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
TElem Nod::getElement() const {
    return element;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
void Nod::setElement(TElem element) {
    Nod::element = element;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
int Nod::getPrev() const {
    return prev;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
void Nod::setPrev(int prev) {
    Nod::prev = prev;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
int Nod::getNext() const {
    return next;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
void Nod::setNext(int next) {
    Nod::next = next;
}


Nod::Nod(TElem element, int prev, int next) : element(element), prev(prev), next(next) {}
