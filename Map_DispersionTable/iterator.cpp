//
// Created by user on 5/24/2023.
//

#include <stdexcept>
#include "iterator.h"
#include "dictionar.h"

using namespace std;


//CF=CN=CM= θ(cap), deci complexitatea este θ(cap).
IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d){
    this->ht = d.ht;
    this->currentPoz = 0;
    while (this->currentPoz < this->ht.cap && ht.T[this->currentPoz] == NULL) {
        this->currentPoz++;
    }
    if (this->currentPoz < this->ht.cap) {
        this->currentNod = this->ht.T[this->currentPoz];
    }
    else {
        this->currentNod = NULL;
    }
}


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
void IteratorDictionar::prim() {
    this->currentPoz = 0;
    while (this->currentPoz < this->ht.cap && ht.T[this->currentPoz] == NULL) {
        this->currentPoz++;
    }
    if (this->currentPoz < this->ht.cap) {
        this->currentNod = this->ht.T[this->currentPoz];
    }
    else {
        this->currentNod = NULL;
    }
}


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
void IteratorDictionar::urmator() {
    if (!this->valid()) {
        throw std::runtime_error("Invalid iterator.");
    }
    this->currentNod = this->currentNod->next;
    if (this->currentNod == NULL) {
        this->currentPoz++;
        while (this->currentPoz < this->ht.cap && ht.T[this->currentPoz] == NULL) {
            this->currentPoz++;
        }
        if (this->currentPoz < this->ht.cap) {
            this->currentNod = this->ht.T[this->currentPoz];
        }
        else {
            this->currentNod = NULL;
        }
    }
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
TElem IteratorDictionar::element() const{
    if (!valid())
        throw std::runtime_error("Error");
    return this->currentNod->info;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
bool IteratorDictionar::valid() const {
    return this->currentNod != NULL && this->currentPoz < this->ht.cap;
}
