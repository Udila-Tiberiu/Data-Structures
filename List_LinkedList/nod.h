//
// Created by user on 5/10/2023.
//

#ifndef LAB3_NOD_H
#define LAB3_NOD_H


typedef int TElem;

class Node {
private:
    TElem element;
    Node* next;

public:
    //Constructor
    Node(TElem element = 0, Node *next = nullptr);

    //returneaza elementul
    TElem getElement() const;

    //schimba valoarea elementului
    void setElement(TElem element);

    //returneaza nodul urmator
    Node *getNext() const;

    //schimba valoarea nodului urmator
    void setNext(Node *next);

};



#endif //LAB3_NOD_H
