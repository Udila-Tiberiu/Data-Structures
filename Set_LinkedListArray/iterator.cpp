//
// Created by user on 5/22/2023.
//

#include <stdexcept>
#include "iterator.h"
#include "multime.h"

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
IteratorMultime::IteratorMultime(const Multime& m) : multime(m){
    prim();
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
void IteratorMultime::prim() {
    if (multime.size > 0) {
        currentNode = multime.head;
    }
    else {
        currentNode = -1;
    }
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
void IteratorMultime::urmator() {
    if (!valid()) {
        throw std::runtime_error("error");
    }
    currentNode = multime.elements[currentNode].getNext();
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
TElem IteratorMultime::element() const {
    if (!valid()) {
        throw std::runtime_error("error");
    }
    return multime.elements[currentNode].getElement();
}

bool IteratorMultime::valid() const {
    return currentNode != -1;
}
