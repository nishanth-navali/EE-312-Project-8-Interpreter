//
// Created by nishanth on 5/6/20.
//

#include "exptree.hpp"

#include <vector>
#include <string>
#include <iostream>
#include "exptree.hpp"

ExpTree::Node* ExpTree::parse(vector<string> &expr) {
    if (expr.size() == 0) {
        return nullptr;
    }

    string token = expr[0];
    expr.erase(expr.begin());
    if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%" || token == "&&" ||
        token == "||" || token == ">" || token == "<" || token == "==" || token == "!=" || token == "<=" ||
        token == ">=" || token == "!" || token == "~") {
        Node *left = parse(expr);
        Node *right = parse(expr);
        return new Node(token, left, right);
    } else {
        return new Node(stoi(token));
    }
}

ExpTree::ExpTree(vector<string> expr) {
    this->root = parse(expr);
}

void ExpTree::printInfix() const {
    // TODO
}

void ExpTree::printPrefix() const {
    // TODO
}

int32_t ExpTree::eval() const {
    if (root == nullptr) {
        return 0;
    } else {
        return root->eval();
    }
}