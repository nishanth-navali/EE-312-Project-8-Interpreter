//
// Created by nishanth on 5/8/20.
//


#include "linkedlist.hpp"
#include <iostream>
#include <list>
#include <string>

using namespace std;

LinkedList::LinkedList(void) : head(NULL), size(0) {
}

LinkedList::~LinkedList(void) {
    destroy();
}

LinkedList::LinkedList(const LinkedList &other) {
    head = NULL;
    copy(other);
}

LinkedList& LinkedList::operator=(const LinkedList &other) {
    if (this == &other) {
        return *this;
    }
    destroy();
    copy(other);
    return *this;
}

void LinkedList::copy(const LinkedList &other) {
    Node *current = other.head;
    while (current != NULL) {
        insert(current->val);
        current = current->next;
    }
}

void LinkedList::destroy(void) {
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL) {
        prev = current;
        current = current->next;
        delete prev;
    }
    head = NULL;
}

void LinkedList::insert(string s, int el) {
    Node *node = new Node;
    node->val = el;
    node->name = s;
    node->next = head;
    head = node;
    size++;
}

void LinkedList::set(string s, int el) {
    find(name)->val = el;
}

bool LinkedList::exists(string n) {
    Node *current = head;
    while (current != NULL) {
        if (current->name == n) {
            return true;
        }
        current = current->next;
    }
    return false;
}

Node* LinkedList::find(string name) {
    Node *current = head;
    Node *output = NULL;
    while (current != NULL) {
        if (current->name == n) {
            output = current;
        }
        current = current->next;
    }
    return output;
}

bool LinkedList::remove(int el) {
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL) {
        if (current->val == el) {
            break;
        }
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return false;
    }

    if (prev == NULL) {
        // remove from head
        head = current->next;
    } else {
        // removing from the middle of the list
        prev->next = current->next;
    }
    delete current;
    size--;
    return true;
}

void LinkedList::print() const {
    Node *current = head;
    while (current != NULL) {
        // printf("%d\n", current->val);
        cout << current->val << endl;
        current = current->next;
    }
}

//LinkedList findSomeValues(LinkedList ll) {
//    cout << ll.find(77) << endl;
//    cout << ll.find(55) << endl;
//    ll.insert(88);
//    return ll;
//}
//
//int main() {
//    LinkedList ll;
//    ll.insert(55);
//    ll.insert(66);
//    ll.print();
//
//    LinkedList ll2 = findSomeValues(ll);
//
//    cout << ll.find(88) << endl;
//    cout << ll2.find(88) << endl;
//
//    ll = ll2;
//    cout << ll.find(88) << endl;
//
//    //list l;
//    //l.push_back();
//
//    return 0;
//}
