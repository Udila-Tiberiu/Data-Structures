//
// Created by user on 5/22/2023.
//

#include "multime.h"
#include "iterator.h"
#include <iostream>

//Complexitate:
//Caz favorabil: CF
//Caz nefavorabil: CN
//Caz mediu: CM


Multime::Multime() : head{-1}, tail{-1}, elements{new Nod[1]}, size{0}, cap{1}, firstFreePosition{0} {}


//CF=CN=CM= θ(cap), deci complexitatea este θ(cap).
void Multime::reajustare() {
    Nod *newElements = new Nod[2 * cap];
    for (int i = 0; i < cap; ++i) {
        newElements[i] = elements[i];
    }
    for (int i = cap; i < cap * 2 - 1; ++i) {
        if (i > cap) {
            newElements[i].setPrev(i - 1);
        }
        newElements[i].setNext(i + 1);
    }
    newElements[cap * 2 - 1].setNext(-1);
    delete[] elements;
    elements = newElements;
    firstFreePosition = cap;
    cap *= 2;
}

//CF = θ(1) (cand elementul pe care vrem sa l adaugam se afla pe prima pozitie)
//CN=CM= θ(size), deci complexitatea este θ(size).
bool Multime::adauga(TElem elem) {
    if (firstFreePosition == -1) {
        reajustare();
    }
    int currentNode = head;
    while (currentNode != -1 && elements[currentNode].getElement() != elem) {
        currentNode = elements[currentNode].getNext();
    }
    if (currentNode == -1) {
        size ++;
        if (head == -1) {
            int nextFreePosition = elements[firstFreePosition].getNext();
            head = firstFreePosition;
            tail = firstFreePosition;
            elements[head].setElement(elem);
            elements[head].setNext(-1);
            elements[head].setPrev(-1);
            firstFreePosition = nextFreePosition;
        }
        else {
            int nextFreePosition = elements[firstFreePosition].getNext();
            elements[firstFreePosition].setElement(elem);
            elements[firstFreePosition].setNext(-1);
            elements[firstFreePosition].setPrev(tail);
            elements[tail].setNext(firstFreePosition);
            tail = firstFreePosition;
            firstFreePosition = nextFreePosition;
        }
        return true;
    }
    return false;
}

//CF = θ(1) (cand elementul pe care vrem sa l stergem se afla pe prima pozitie)
//CN=CM= θ(size), deci complexitatea este θ(size).
bool Multime::sterge(TElem elem) {
    int currentNode = head;

    while (currentNode != -1 && elements[currentNode].getElement() != elem) {
        currentNode = elements[currentNode].getNext();
    }
    if (currentNode == -1)
        return false;
    size --;
    int prevNode = elements[currentNode].getPrev();
    int nextNode = elements[currentNode].getNext();
    if (currentNode == tail) {
        tail = prevNode;
        if (tail == -1) {
            head = -1;
        }
    } else if (currentNode == head) {
        head = nextNode;
        if (head == -1) {
            tail = -1;
        }
    }
    elements[currentNode].setNext(firstFreePosition);
    firstFreePosition = currentNode;
    if (prevNode != -1) {
        elements[prevNode].setNext(nextNode);
    }
    if (nextNode != -1) {
        elements[nextNode].setPrev(prevNode);
    }
    return true;
}

//CF = θ(1) (cand elementul pe care vrem sa l stergem se afla pe prima pozitie)
//CN=CM= θ(size), deci complexitatea este θ(size).
bool Multime::cauta(TElem elem) const {
    int currentNode = head;
    while (currentNode != -1 && elements[currentNode].getElement() != elem) {
        currentNode = elements[currentNode].getNext();
    }
    return currentNode != -1;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
int Multime::dim() const {
    return size;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
bool Multime::vida() const {
    return size == 0;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
Multime::~Multime() {
    delete[] elements;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
IteratorMultime Multime::iterator() const {
    return IteratorMultime(*this);
}

//CF= θ(b.size) ( daca toate elementele din b se afla deja in list curenta)
//CN=CM= θ(b.size * size), deci complexitatea este θ(b.size * size).
void Multime::reuniune(const Multime &b) {
    int currentNode = b.head;
    while (currentNode != -1) {
        adauga(currentNode);
        currentNode = b.elements[currentNode].getNext();
    }
}



