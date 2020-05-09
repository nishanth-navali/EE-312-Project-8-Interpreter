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
vector <string> line;
string text;

string toStr(const char *a) {
    string s = "";
    int i = 0;
    while (a[i] != 0) {
        s = s + a[i];
        i++;
    }
    return s;
}

bool checkToken(string str) {
    if (str == "set") {
        return false;
    } else if (str == "var") {
        return false;
    } else if (str == "output") {
        return false;
    } else if (str == "text") {
        return false;
    } else {
        return true;
    }
}

void readLine() {

    while (checkToken(text)) {
        if (ll.exists(text)) {
            line.push_back(to_string(ll.find(str)->val));
        } else {
            line.push_back(str);
        }
        read_next_token();
        text = toStr(next_token());
        if (text == "//") {
            skip_line();
        }
    }
}

void set() {
    read_next_token();
    text = toStr(next_token());
    if (ll.exists(text)) {
        string name = text;
        read_next_token();
        text = toStr(next_token());
        readLine();
        expTree = new ExpTree(&line);
        ll.set(name, expTree.eval());
        expTree.clear();
    } else {
        cout << "variable " << text << " not declared" << endl;
    }
}

void var() {
    read_next_token();
    text = toStr(next_token());
    if (ll.exists(text)) {
        string name = text;
        read_next_token();
        text = toStr(next_token());
        readLine();
        expTree = new ExpTree(&line);
        ll.set(name, expTree.eval())
        expTree.clear();
        cout << "variable " << name << " incorrectly re-initialized" << endl;
    } else {
        string name = text;
        read_next_token();
        text = toStr(next_token());
        readLine();
        expTree = new ExpTree(&line);
        ll.insert(name, expTree.eval());
        expTree.clear();
    }
}

void output() {
    read_next_token();
    text = toStr(next_token());
    readLine();
    expTree = new ExpTree(&line);
    cout << to_string(expTree.eval()) << endl;
    expTree.clear();
}

void text() {
    read_next_token();
    text = toStr(next_token());
    string s = text;
    while (checkToken(text)) {
        read_next_token();
        text = toStr(next_token());
        if (text == "//") {
            skip_line();
        }
        s = s + " " + text;
    }
    cout << s << endl;
}

void reset() {
    // TODO: Implement these methods
    ll.clear();
    expTree.clear();
    line.erase();
}


void selectFunction() {
    if (text == "set") {
        set();
    } else if (text == "var") {
        var();
    } else if (text == "output") {
        output();
    } else if (text == "text") {
        text();
    } else {
        cout << "Error: selectFunction did not call any default function" << endl;
    }
}

void run() {
    // loops at the beginning of each line
    while (next_token_type != END) {
        text = toStr(next_token());
        if (next_token_type == NAME) {
            selectFunction();
        } else {
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



