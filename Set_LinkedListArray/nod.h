//
// Created by user on 5/24/2023.
//

#ifndef LAB4_NOD_H
#define LAB4_NOD_H

typedef int TElem;

class Nod {
private:
    //elementul
    TElem element;
    //inainte
    int prev;
    //dupa
    int next;

public:
    //Constructor
    Nod(TElem element = 0, int prev = -1, int next = -1);

    TElem getElement() const;

    void setElement(TElem element);

    int getPrev() const;

    void setPrev(int prev);

    int getNext() const;

    void setNext(int next);

};
#endif //LAB4_NOD_H
