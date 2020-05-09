//
// Created by nishanth on 5/8/20.
//

#ifndef EE_312_PROJECT_8_INTERPRETER_LINKEDLIST_HPP
#define EE_312_PROJECT_8_INTERPRETER_LINKEDLIST_HPP

#include <iostream>
#include <string>

using namespace std;

typedef struct node {
    int val;
    string name
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
    void insert(string s, int el);

    // remove given element
    bool remove(int el);

    void set(string s, int el);

    // true/false if element is inside
    bool exists(string n);

    Node* find(string name);

    //void print(ostream &os) const;
    void print() const;
};


#endif //EE_312_PROJECT_8_INTERPRETER_LINKEDLIST_HPP
