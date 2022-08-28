#pragma once

#include <iostream>

template <class elemType>
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}
    BinaryTree(const elemType &x) {
        root = new Node(x);
    }
    BinaryTree(Node *p) : root(p) {}
    elemType getRoot() {
        return root->data;
    }

    elemType getLeft() {
        return root->left->data;
    }

    elemType getRight() {
        return root->right->data;
    }

    void makeTree(const elemType &x, BinaryTree &lt, BinaryTree &rt) {
        root = new Node(x, lt.root, rt.root);
        lt.root = nullptr;
        lt.root = nullptr;
    }

    void delLeft() {
        BinaryTree tmp = root->left;
        root->left = nullptr;
        tmp.clear();
    }

    void delRight() {
        BinaryTree tmp = root->right;
        root->right = nullptr;
        tmp.clear();
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    void clear() {
        if(root != nullptr) {
            clear(root);
            root = nullptr;
        }
    }

    int size() const {
        return _size(root);
    }

    int height() const {
        return _height(root);
    }

    void preOrder() const {
        if(root != nullptr) {
            std::cout << "\n前序遍历";
            _preOrder(root);
        }
    }
    void postOrder() const {
        if(root != nullptr) {
            std::cout << "\n后序遍历";
            _postOrder(root);
        }
    };
    void midOrder() const {
        if(root != nullptr) {
            std::cout << "\n中序遍历"
            _midOrder(root);
        }
    };
    void createTree(elemType flag);
private:
    struct Node
    {
        Node *left, *right;
        elemType data;
        Node() : left(nullptr), right(nullptr) {};
        Node(elemType _data, node *_left = nullptr, node *_right = nullptr)
        : data(_data), left(_left), right(_right) {}
        ~Node() {}
    };
    Node *root;
    void clear(Node *t);
    int _height(Node *t) const;
    int _size(Node *t) const;
    void _preOrder(Node *t) const;
    void _postOrder(Node *t) const;
    void _midOrder(Node *t) const;
};

template <class elemType>
int BinaryTree<elemType>::_height(Node *t) const {
    if(t == nullptr) {
        return 0;
    }else {
        int lt = height(t->left);
        int rt = height(t->right);
        return 1 + ((lt > rt) ? lt : rt);
    }
}

template <class elemType>
void BinaryTree<elemType>::_preOrder(Node *t) const {
    if(t = nullptr) {
        return 0;
    }else {
        std::cout << t->data << " ";
        _preOrder(t->left);
        _preOrder(t->right);
    }
}

template <class elemType>
void BinaryTree<elemType>::_postOrder(Node *t) const {
    if(t = nullptr) {
        return 0;
    }else {
        _postOrder(t->left);
        _postOrder(t->right);
        std::cout << t->data << " ";
    }
}

template <class elemType>
void BinaryTree<elemType>::_midOrder(Node *t) const {
    if(t = nullptr) {
        return 0;
    }else {
        _postOrder(t->left);
        std::cout << t->data << " ";
        _postOrder(t->right);
    }
}

template <class elemType>
int BinaryTree<elemType>::_size(Node *t) const{
    if(t->left != nullptr) {
        clear(t->left);
    }
    if(t->right !=nullptr) {
        clear(t->right);
    }
    delete t;
}