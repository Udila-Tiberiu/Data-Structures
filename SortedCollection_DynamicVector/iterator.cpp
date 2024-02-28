#include <stdexcept>
#include "iterator.h"
#include "colectie.h"
//Complexitate:
//Caz Favorabil = CF
//Caz Defavorabil = CD
//Caz Mediu = CM

//CF = CD = CM = θ(1), deci complexitatea este θ(1)
IteratorColectie::IteratorColectie(const Colectie& c): c(c) {
    curent = 0;
}

//CF = CD = CM = θ(1), deci complexitatea este θ(1)
void IteratorColectie::prim() {
    curent = 0;
}

//CF = CD = CM = θ(1), deci complexitatea este θ(1)
void IteratorColectie::urmator() {
    if (!valid()) {
        throw std::runtime_error("Invalid iterator");
    }
    curent++;
}

//CF = CD = CM = θ(1), deci complexitatea este θ(1)
bool IteratorColectie::valid() const {
    return curent < c.n;
}


//CF = CD = CM = θ(1), deci complexitatea este θ(1)
TElem IteratorColectie::element() const {
    if (!valid()) {
        throw std::runtime_error("Invalid iterator");
    }
    return c.list[curent];
}
