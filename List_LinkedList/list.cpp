//
// Created by user on 5/09/2023.
//

#include "list.h"
#include <exception>
#include "iterator.h"
#include <iostream>


//Complexitate:
//Caz favorabil: CF
//Caz nefavorabil: CN
//Caz mediu: CM


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
Lista::Lista() : first{nullptr}, last{nullptr}, n{0} {}


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
int Lista::dim() const {
    return n;
}


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
bool Lista::vida() const {
    return n == 0;
}


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
IteratorLP Lista::prim() const {
    IteratorLP it{*this};
    return it;
}


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
TElem Lista::element(IteratorLP poz) const {
    if (!poz.valid())
        throw std::invalid_argument("Eroare.");
    return poz.element();
}


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
TElem Lista::sterge(IteratorLP& poz) {
    if (!poz.valid())
        throw std::invalid_argument("Eroare.");
    TElem sters = poz.element();
    if (poz.currentNode == first) {
        Node *second = first->getNext();
        first->setNext(nullptr);
        delete first;
        first = second;
    }
    else if (poz.currentNode == last) {
        Node* nod = first;
        Node*currentNode;
        while (nod->getNext() != nullptr) {
            currentNode = nod;
            nod = nod->getNext();
        }
        Node *secondLast = currentNode;
        last->setNext(nullptr);
        delete last;
        last = secondLast;
        if (last != nullptr)
            last->setNext(nullptr);
    }
    else {
        Node *next = poz.currentNode->getNext();
        poz.currentNode->setElement(next->getElement());
        poz.currentNode->setNext(next->getNext());
        delete next;
        next = nullptr;
    }
    --n;
    return sters;
}


//CF = θ(1) (daca elementul cautat se afla pe primul nod)
//CN = θ(n) (daca elementul cautat se afla pe ultimul nod)
//CM = θ(n), deci complexitatea este θ(n).
IteratorLP Lista::cauta(TElem e) const{
    IteratorLP it = prim();
    while (it.valid()) {
        if(it.element() == e){
            return it;
        }
        it.urmator();
    }
    return it;
}


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
TElem Lista::modifica(IteratorLP poz, TElem e) {
    if (!poz.valid())
        throw std::invalid_argument("Eroare");
    TElem modif = poz.currentNode->getElement();
    poz.currentNode->setElement(e);
    return modif;
}


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
void Lista::adauga(IteratorLP& poz, TElem e) {
    if (!poz.valid())
        throw std::invalid_argument("Eroare");
    Node *node = new Node{e};
    if (poz.currentNode == first) {
        adaugaInceput(e);
    }
    else if (poz.currentNode == last) {
        adaugaSfarsit(e);
    }
    else {
        TElem elem = poz.currentNode->getElement();
        node->setNext(poz.currentNode->getNext());
        node->setElement(elem);
        poz.currentNode->setNext(node);
        poz.currentNode->setElement(e);
    }
    ++n;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
void Lista::adaugaInceput(TElem e) {
    Node* nod = new Node(e);
    nod->setNext(first);
    first = nod;
    n ++;
}


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
void Lista::adaugaSfarsit(TElem e) {
    Node *node = new Node(e);
    if (n == 0) {
        first = last = node;
    }
    else {
        node->setNext(nullptr);
        last->setNext(node);
        last = node;
    }
    ++n;
}


//CF=CN=CM= θ(n), deci complexitatea este θ(n).
Lista::~Lista() {
    Node *currentNode;
    while (first != nullptr) {
        currentNode = first;
        first = first->getNext();
        delete currentNode;
    }
}
