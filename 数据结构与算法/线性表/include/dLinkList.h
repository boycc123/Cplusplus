#pragma once

#include "list.h"
#include  <iostream>

template <class elemType>
class DLinkList : List<elemType> {
public:
    DLinkList();
    ~DLinkList();
    int length() const;
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void insert(int i, const elemType &x);
    void remove(int i);
    void clear();
    void traverse() const;

private:
    struct node
    {
        elemType data;
        node *prev, *next;
        node(elemType &x, node *p = NULL, node *q = NULL) {
            data = x;
            prev = p;
            next = q;
        }
        node() : next(NULL), prev(NULL) {}
        ~node();
    };
    node *head, *tail;
    int currentLength;
    node *move(int i) const;
};