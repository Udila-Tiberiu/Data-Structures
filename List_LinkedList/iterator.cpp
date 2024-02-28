//
// Created by user on 5/09/2023.
//
#include "iterator.h"
#include "list.h"
#include <exception>
#include <stdexcept>

//Complexitate:
//Caz favorabil: CF
//Caz nefavorabil: CN
//Caz mediu: CM

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
IteratorLP::IteratorLP(const Lista& l):list(l) {
    if (list.vida())
        currentNode = nullptr;
    else
        currentNode = list.first;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
void IteratorLP::prim(){
    currentNode = list.first;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
void IteratorLP::urmator(){
    if (!valid()) {
        throw std::invalid_argument("Eroare");
    }
    currentNode = currentNode->getNext();
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
bool IteratorLP::valid() const{
    return currentNode != nullptr;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
TElem IteratorLP::element() const{
    if (!valid()) {
        throw std::invalid_argument("Eroare.");
    }
    return currentNode->getElement();
}

//CF = θ(1) (cand nodul curent este nullptr)
//CN = θ(k) (cand nodul curent nu este nullptr, iar k este valid
//CM = θ(k), deci complexitatea este θ(k).
void IteratorLP::kPasi(int k) {
    int i = k;
    Node* nod = currentNode;
    while(i > 0){
        if(nod == nullptr)break;
        i --;
        nod = nod->getNext();
    }
    if(!valid() || k <= 0){
        throw std::invalid_argument("Eroare.");
    }
    i = k;
    while(i > 0){
        urmator();
        i --;
    }
}


