//
// Created by nishanth on 5/8/20.
//

#ifndef EE_312_PROJECT_8_INTERPRETER_LINKEDLIST_HPP
#define EE_312_PROJECT_8_INTERPRETER_LINKEDLIST_HPP

#include <iostream>

using namespace std;

typedef struct node {
    int val;
    struct node *next;
} Node;

class LinkedList {
private:
    Node *head;
    int size;

    void destroy(void);
    void copy(const LinkedList &other);

public:
    LinkedList(void);

    ~LinkedList(void);

    LinkedList(const LinkedList &other);

    LinkedList& operator=(const LinkedList &other);

    // insert at the beginning
    void insert(int el);

    // remove given element
    bool remove(int el);

    // true/false if element is inside
    bool find(int el);

    //void print(ostream &os) const;
    void print() const;
};


#endif //EE_312_PROJECT_8_INTERPRETER_LINKEDLIST_HPP
