//
// Created by Eyup on 29.11.2025.
//

#ifndef VIZECALISMATREE_NODE_H
#define VIZECALISMATREE_NODE_H


class Node {
public:
    Node* left;
    Node* right;
    int data;
    Node(int value) {
        this->data = value;
        left = nullptr;
        right = nullptr;
    }
};


#endif //VIZECALISMATREE_NODE_H