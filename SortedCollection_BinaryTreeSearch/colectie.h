//
// Created by user on 6/4/2023.
//

#ifndef LAB7_COLECTIE_H
#define LAB7_COLECTIE_H

#define null (-9999)

typedef int TElem;

typedef bool(*Relatie)(TElem, TElem);

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem, TElem);

class IteratorColectie;

class Colectie {

    friend class IteratorColectie;

private:

    int cap;
    TElem *elements;
    TElem *frecv;
    int *left;
    int *right;
    int root;
    int firstFREE;
    int size;

    Relatie r;
    void resize();
    int add_rec(int p, TElem e, int& ok);
    void first_free();
    int min(int nod);
    int sterge_rec(int p, TElem e, int& found, int& fr);
public:
    //constructorul implicit
    Colectie(Relatie r);

    //adauga un element in colectie
    void adauga(TElem e);

    //sterge o aparitie a unui element din colectie
    //returneaza adevarat daca s-a putut sterge
    bool sterge(TElem e);

    //verifica daca un element se afla in colectie
    bool cauta(TElem elem) const;

    //returneaza numar de aparitii ale unui element in colectie
    int nrAparitii(TElem elem) const;


    //intoarce numarul de elemente din colectie;
    int dim() const;

    //verifica daca colectia e vida;
    bool vida() const;

    //returneaza un iterator pe colectie
    IteratorColectie iterator() const;

    // destructorul colectiei
    ~Colectie();

    //returneaza numarul de elemente care apar de frecventa ori in colectie
    //arunca exceptie in cazul in care frecventa este negativa sau 0
    int elementeCuFrecventaData(int frecventa) const;


};



#endif //LAB7_COLECTIE_H
