//
// Created by nishanth on 5/6/20.
//

#ifndef EE_312_PROJECT_8_INTERPRETER_EXPTREE_HPP
#define EE_312_PROJECT_8_INTERPRETER_EXPTREE_HPP
#include <vector>
#include <string>
#include <cstdint>
#include <stdio.h>

using namespace std;


class ExpTree {

    class Node {
    public:
        /* says if the node is operator or operand */
        bool is_operand;

        /* value of the operand if this is an operand node */
        int operand;

//        int optr_type;

        string optr;

        /* left subtree */
        Node *left;

        /* right subtree */
        Node *right;

    public:
        Node(const int operand) {
            this->is_operand = true;
            this->operand = operand;
//            this->optr_type = 0;
            this->optr = '0';
            this->left = nullptr;
            this->right = nullptr;
        }

        Node(string optr, Node* left, Node *right) {
            this->is_operand = false;
            this->operand = 0;
            this->optr = optr;
            this->left = left;
            this->right = right;
//            this->optr_type = operatorType();

        }

        int32_t toInt(bool b) const{
            if(b) return 1;
            else {
                return 0;
            }
        }

        // TODO: Figure this out
        int32_t eval() const {
            if (is_operand) {
                return operand;
            } else {
                int32_t lv = left->eval();
                int32_t rv = right->eval();
                if (optr == "+") {
                    return lv + rv;
                } else if (optr == "*") {
                    return lv * rv;
                } else if (optr == "-") {
                    return lv - rv;
                } else if (optr == "/") {
                    return lv/rv;
                } else if (optr == "%") {
                    return lv % rv;
                } else if (optr == "&&") {
                    return this->toInt(lv && rv);
                } else if (optr == "||") {
                    return this->toInt(lv || rv);
                } else if (optr == "<") {
                    return this->toInt(lv < rv);
                } else if (optr == ">") {
                    return this->toInt(lv > rv);
                } else if (optr == "==") {
                    return this->toInt(lv == rv);
                } else if (optr == "!=") {
                    return this->toInt(lv != rv);
                } else if (optr == "<=") {
                    return this->toInt(lv <= rv);
                } else if (optr == ">=") {
                    return this->toInt(lv >= rv);
                } else if (optr == "~") {
                    return -lv;
                } else if (optr == "!") {
                    return this->toInt(!lv);
                }

            }
        }

//        int32_t operatorType() {
//            string a = this->optr;
//            if(a == "+" || a == "-" || a == "*" || a == "/" || a == "%") return 1;
//            else if(a == "&&" || a == "||") return 2;
//            else if(a == "<" || a == ">" || a == "==" || a == "!=" || a == "<=" || a == ">=") return 3;
//            else if(a == "~" || a == "!") return 4;
//            else {
//                return 0;
//            }
//        }

        /* TODO: Copy constructor */
        // Node(const Node &other);

        ~Node() {
            delete this->left;
            delete this->right;
            delete this;
        }

        /* TODO: Assignment operator */
        // Node& operator=(const Node &other);

//        void printInfix() const {
//            if (is_operand) {
//                cout << operand << ' ';
//            } else {
//                if (left != nullptr) {
//                    left->printInfix();
//                }
//                cout << optr << ' ';
//                if (right != nullptr) {
//                    right->printInfix();
//                }
//            }
//        }
//
//        void printPrefix() const {
//            if (is_operand) {
//                cout << operand << ' ';
//            } else {
//                cout << optr << ' ';
//                if (left != nullptr) {
//                    left->printPrefix();
//                }
//                if (right != nullptr) {
//                    right->printPrefix();
//                }
//            }
//        }
//    };

    /* root of the expression tree */
    Node *root;

    Node* parse(vector<string> &expr);

    void printInfix(const Node *n) const;

    void printPrefix(const Node *n) const;

public:

    ExpTree(vector<string> expr);

    // ExpTree(const ExpTree &other);
    // ~ExpTree();
    // ExpTree& operator=(const ExpTree &other);

    /* Print the tree by doing in-order traversal */
    void printInfix() const;

    /* Print the tree by doing pre-order traversal */
    void printPrefix() const;

    /* Evaluate the tree and return the value */
    int32_t eval() const;

    void clear() const;
};



#endif //EE_312_PROJECT_8_INTERPRETER_EXPTREE_HPP
