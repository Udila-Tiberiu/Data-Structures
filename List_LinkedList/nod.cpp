//
// Created by user on 5/09/2023.
//

#include "nod.h"

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
Node::Node(TElem element, Node *next) : element(element), next(next) {}


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
TElem Node::getElement() const {
    return element;
}


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
void Node::setElement(TElem element) {
    this->element = element;
}


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
Node *Node::getNext() const {
    return next;
}


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
void Node::setNext(Node *next) {
    this->next = next;
}


