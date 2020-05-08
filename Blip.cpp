//
// Created by nishanth on 5/6/20.
//

#include "Parse.h"
#include "exptree.hpp"
#include "linkedlist.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string>

using namespace std;

LinkedList ll;
ExpTree expTree;
const char* text;

void set();
void var();
void output();
void text();

void reset() {
    // TODO: Implement these methods
    ll.clear();
    expTree.clear();
}

void selectFunction() {
    if(strcmp(text, "set") == 0) {
        set();
    } else if(strcmp(text, "var") == 0) {
        var();
    } else if(strcmp(text, "output") == 0) {
        output();
    } else if(strcmp(text, "text") == 0) {
        text();
    } else {
        cout << "Error: selectFunction did not call any default function" << endl;
    }
}

void run() {
    // loops at the beginning of each line
    while(next_token_type != END)  {
        text = next_token();
        if(next_token_type == NAME) {
            selectFunction();
        }
        else {
            cout << "Error: Next token type was not NAME" << endl;
        }
        read_next_token();
    }
    reset();
}

int main(void) {
    set_input("test1.blip");
    run();
    set_input("test2.blip");
    run();
    set_input("test3.blip");
    run();
    return 0;
}



