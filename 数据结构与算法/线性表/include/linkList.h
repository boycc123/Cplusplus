#pragma once

#include "list.h"
#include <iostream>


class OutOfBound {};

// 单链表类
template <class elemType>
class LinkList : public List<elemType> {
public:
    LinkList();
    ~LinkList();
    int length() const;
    int search(const elemType &x) const;
    elemType visit(const int i) const;
    void insert(int i, const elemType &x);
    void remove(int i);
    void clear();
    void traverse() const;

private:
    struct node
    {
        elemType data;
        node* next;
        node(const elemType &x, node *p = NULL) {
            data = x;
            next = p;
        }
        node() : next(NULL) {}
        ~node() {};
    };
    node *head;

};

template <class elemType>
LinkList<elemType>::LinkList() {
    // 建立头结点
    this->head = new node();
}

template <class elemType>
LinkList<elemType>::~LinkList() {

}

template <class elemType>
int LinkList<elemType>::length() const {
    // 根据next遍历链表
    int len = 0;
    node *p = head->next;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

template <class elemType>
int LinkList<elemType>::search(const elemType &x) const {
    int num = 0;
    node *p = head->next;
    while (p != nullptr && x != p->data)
    {
        p = p->next;
        num++;
    }
    if(p == nullptr) {
        num = -1;
    }
    return num;
}

template <class elemType>
elemType LinkList<elemType>::visit(int i) const {
    int num = 0;
    node *p = head->next;
    while(p->next != nullptr && num != i) {
        p = p->next;
        num++;
    }
    if(p->next == nullptr) {
        throw OutOfBound();
    }
    return p->data;
}

template <class elemType>
void LinkList<elemType>::insert(int i, const elemType &x) {
    if(i < 0) {
        return;
    }
    node *tmp, *p = head;
    for(int j = 0; j < i; j++) {
        p = p->next;
    }
    tmp = new node(x, p->next);
    p->next = tmp;
}

template <class elemType>
void LinkList<elemType>::remove(int i) {
    node* p = head->next;
    node* tmp;
    if(i < 0) {
        return;
    }
    for (int j = 0; p && j < i; j++) {
        p = p->next;
    }
    if(!p || (p->next = nullptr)) {
        return;
    }
    tmp = p->next;
    p->next = tmp->next;
    delete tmp;
}

template <class elemType>
void LinkList<elemType>::clear() {
    node *p = head->next;
    node *tmp;
    while (p != NULL)
    {
        tmp = p;
        p = p->next;
        delete tmp;
    }
    head->next = NULL;
}

template <class elemType>
void LinkList<elemType>::traverse() const {
    node *p = head->next;
    while (p != nullptr)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    
}
