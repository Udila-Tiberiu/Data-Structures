//
// Created by user on 6/4/2023.
//

#include "colectie.h"
#include "iterator.h"

using namespace std;

//Complexitati:
//Caz favorabil: CF
//Caz nefavorabil: CN
//Caz mediu: CM
//inaltimea arborului = h


//CF=CN=CM= θ(1), deci complexitatea este θ(1).
bool rel(TElem e1, TElem e2) {
    if (e1 <= e2)return true;
    return false;
}

//CF=CN=CM= θ(cap), deci complexitatea este θ(cap).
Colectie::Colectie(Relatie r) : r{r} {
    cap = 256;
    root = 0;
    size = 0;
    elements = new TElem[cap];
    frecv = new TElem[cap];
    left = new int[cap];
    right = new int[cap];
    firstFREE = 0;
    for (int i = 0; i < cap; i++) {
        left[i] = null;
        right[i] = null;
        elements[i] = null;
        frecv[i] = null;
    }
}

//CF = θ(1) (cand lista este goala sau e este radacina)
//CN = CM = θ(h), deci complexitatea este θ(h).
void Colectie::adauga(TElem e) {
    if (size == cap - 1)resize();
    if (vida()) {
        elements[0] = e;
        frecv[0] = 1;
        size++;
        firstFREE = 1;
    } else {
        int ok = 1;
        add_rec(root, e, ok);
        size += ok;
    }
}

//CF = θ(1) (cand lista este goala sau e este radacina)
//CN = CM = θ(h), deci complexitatea este θ(h).
bool Colectie::sterge(TElem e) {
    int f = 0;
    int fr = 1;
    this->root = sterge_rec(this->root, e, f, fr);
    if (f == 0){
        return false;
    }
    else {
        if(fr == 1)size--;
        return true;
    }
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
bool Colectie::cauta(TElem elem) const {
    int curent = root;
    while (curent != null) {
        if (r(elements[curent], elem)) {
            if (elem == elements[curent])return true;
            curent = right[curent];
        } else {
            curent = left[curent];
        }
    }
    return false;
}

//CF = θ(1) (cand lista este goala sau e este radacina)
//CN = CM = θ(h), deci complexitatea este θ(h).
int Colectie::nrAparitii(TElem elem) const {
    int curent = root;
    while (curent != null) {
        if (r(this->elements[curent], elem)) {
            if (elem == elements[curent])return frecv[curent];
            curent = right[curent];
        } else {
            curent = left[curent];
        }
    }
    return 0;
}

//CF=CN=CM= θ(size), deci complexitatea este θ(size).
int Colectie::dim() const {
    int nr = 0;
    IteratorColectie it = iterator();
    it.prim();
    while(it.valid()){
        nr += it.frecventa();
        it.urmator();
    }
    return nr;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
bool Colectie::vida() const {
    if (size == 0)return true;
    return false;
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
IteratorColectie Colectie::iterator() const {
    return IteratorColectie(*this);
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
Colectie::~Colectie() {
    delete[] elements;
    delete[] frecv;
    delete[] left;
    delete[] right;
}

//CF=CN=CM= θ(cap), deci complexitatea este θ(cap).
void Colectie::resize() {
    int new_cap = 2 * cap;
    TElem *new_elems = new TElem[new_cap];
    TElem *new_frecv = new TElem[new_cap];
    int *new_left = new int[new_cap];
    int *new_right = new int[new_cap];
    for (int i = 0; i < cap; i++) {
        new_elems[i] = elements[i];
        new_frecv[i] = frecv[i];
        new_left[i] = left[i];
        new_right[i] = right[i];
    }
    for (int i = this->cap; i < this->cap * 2; i++) {
        new_elems[i] = null;
        new_frecv[i] = null;
        new_left[i] = null;
        new_right[i] = null;
    }
    delete[] elements;
    delete[] frecv;
    delete[] left;
    delete[] right;
    elements = new_elems;
    frecv = new_frecv;
    left = new_left;
    right = new_right;
    firstFREE = cap;
    cap = new_cap;
}

//CF = θ(1) (cand lista este goala sau e este radacina)
//CN = CM = θ(h), deci complexitatea este θ(h).
int Colectie::add_rec(int p, TElem e, int &ok) {
    if (p == null) {
        elements[firstFREE] = e;
        frecv[firstFREE] = 1;
        int old = firstFREE;
        first_free();
        return old;

    }
    if (e == elements[p]) //
    {
        ok = 0;
        frecv[p]++;
        return p;
    } else if (!r(this->elements[p], e)) {
        this->left[p] = add_rec(this->left[p], e, ok);
        return p;
    } else {
        this->right[p] = add_rec(this->right[p], e, ok);
        return p;
    }
}

//CF=CN=CM= θ(1), deci complexitatea este θ(1).
void Colectie::first_free() {
    if (this->elements[this->firstFREE] != null)
        this->firstFREE++;
}

//CF=CN=CM= θ(h), deci complexitatea este θ(h).
int Colectie::min(int nod) {
    int curent = nod;
    while (this->left[curent] != null) {
        curent = this->left[curent];
    }
    return curent;
}

//CF = θ(1) (cand lista este goala sau e este radacina)
//CN = CM = θ(h), deci complexitatea este θ(h).
int Colectie::sterge_rec(int p, TElem e, int &found, int& fr) {
    if (p == null) {
        return null;
    }
    if (elements[p] == e) {
        found = 1;
        if (frecv[p] > 1) {
            frecv[p]--;
            fr = 0;
            return p;
        } else if (left[p] == null && right[p] == null)
            return null;
        else if (left[p] == null) {
            return right[p];
        } else if (right[p] == null) {
            return left[p];
        } else {
            int minim = min(right[p]);
            elements[p] = elements[minim];
            frecv[p] = frecv[minim];
            right[p] = sterge_rec(right[p], elements[minim], found, fr);
            return p;
        }
    } else if (!r(elements[p], e)) {
        left[p] = sterge_rec(left[p], e, found, fr);
        return p;
    } else {
        right[p] = sterge_rec(right[p], e, found, fr);
        return p;
    }
}

//CF=CN=CM= θ(size), deci complexitatea este θ(size).
int Colectie::elementeCuFrecventaData(int frecventa) const {
    if(frecventa <= 0){
        throw std::exception();
    }
    int nr = 0;
    IteratorColectie it = iterator();
    it.prim();
    while(it.valid()){
        if(it.frecventa() == frecventa)nr ++;
        it.urmator();
    }
    return nr;

}
