#include <stdexcept>
#include "colectie.h"
#include "iterator.h"
#include <iostream>
using namespace std;

//Complexitate:
//Caz Favorabil = CF
//Caz Defavorabil = CD
//Caz Mediu = CM


//CF = CD = CM = θ(1), deci complexitatea este θ(1)
bool rel(TElem e1, TElem e2) {
    if(e1 <= e2){
        return true;
    }
    return false;
}

//CF = CD = CM = θ(n), deci complexitatea este θ(n)
void Colectie::redim() {
    TElem *l = new TElem[2 * cp];
    int *f = new int[2 * cp];
    for (int i = 0; i < n; i++) {
        l[i] = list[i];
        f[i] = frecv[i];
    }
    cp = 2 * cp;
    delete[] list;
    delete[] frecv;
    list = l;
    frecv = f;
}

//CF = CD = CM = θ(1), deci complexitatea este θ(1)
Colectie::Colectie() {
    this->cp = 10;
    list = new TElem[cp];
    frecv = new int[cp];
    this->n = 0;
}

//CF = θ(1)
//CD = CM = θ(n)
//Deci complexitatea este θ(n)
void Colectie::adauga(TElem e) {
    if (n - 2 == cp) {
        redim();
    }
    int i = 0;
    while (i < n) {
        if (rel(e, list[i])) {
            break;
        }
        i++;
    }
    if (i == n) {
        list[i] = e;
        frecv[i] = 1;
        this->n++;
    } else {
        if (e == list[i]) {
            frecv[i]++;
        } else {
            for (int j = n; j > i; j--) {
                list[j] = list[j - 1];
                frecv[j] = frecv[j - 1];
            }
            this->n++;
            list[i] = e;
            frecv[i] = 1;
        }
    }
}

//CF = θ(1)
//CD = CM = θ(n)
//deci complexitatea este θ(n)
bool Colectie::sterge(TElem e) {
    for(int i = 0; i < n; i ++){
        if(e == list[i]){
            if(frecv[i] > 1){
                frecv[i] --;
                return true;
            }
            else {
                for(int j = i; j < n - 1; j ++){
                    list[j] = list[j + 1];
                    frecv[j] = frecv[j + 1];
                }
                this->n --;
                return true;
            }
        }
    }
    return false;
}

//CF = θ(1)
//CD = CM = θ(n)
//deci complexitatea este θ(n)
bool Colectie::cauta(TElem elem) const {
    for(int i = 0; i < n; i ++){
        if(list[i] == elem){
            return true;
        }
    }
    return false;
}

//CF = θ(1)
//CD = CM = θ(n)
//deci complexitatea este θ(n)
int Colectie::nrAparitii(TElem elem) const {
    for(int i = 0; i < n; i ++){
        if(list[i] == elem){
            return frecv[i];
        }
    }
    return 0;
}


//CF = CD = CM = θ(1), deci complexitatea este θ(1)
int Colectie::dim() const {
    int nr = 0;
    for(int i = 0; i < n; i ++){
        nr += frecv[i];
    }
    return nr;
}

//CF = CD = CM = θ(1), deci complexitatea este θ(1)
bool Colectie::vida() const {
    if(n == 0)
        return true;
    else
        return false;
}

//CF = CD = CM = θ(1), deci complexitatea este θ(1)
IteratorColectie Colectie::iterator() const {
    return  IteratorColectie(*this);
}

//CF = CD = CM = θ(1), deci complexitatea este θ(1)
Colectie::~Colectie() {
    delete[] list;
    delete[] frecv;
}

//CF = θ(1)
//CD = CM = θ(n)
//deci complexitatea este θ(n)
void Colectie::adaugaAparitiiMultiple(int nr, TElem elem) {
    if(nr < 0){
        throw std::runtime_error("Numarul de aparitii este negativ");
    }
    int i = 0;
    while(i < n){
        if(rel(elem,list[i])){
            break;
        }
        i ++;
    }
    if(elem == list[i]){
        frecv[i] += nr;
    }
    else {
        for (int j = n; j > i; j--) {
            list[j] = list[j - 1];
            frecv[j] = frecv[j - 1];
        }
        this->n ++;
        list[i] = elem;
        frecv[i] = nr;
    }
    if(i == n){
        list[i] = elem;
        frecv[i] = nr;
        this-> n ++;
    }
}


//void Colectie::afis(){
//    for(int i = 0; i < n; i ++){
//        cout << list[i] << "-" << frecv[i] << '\n';
//    }
//}