#pragma once

#include "list.h"
#include <iostream>

// 两个异常类
class OutOfBound{};

class IlligalSize{};

// 线性表类
template <class elemType>
class SeqList : public List<elemType>{
public:
    SeqList() = delete;
    SeqList(int initSize);
    int length() const;
    int search(const elemType &x) const;
    elemType visit(const int i) const;
    void insert(int i, const elemType &x);
    void remove(int i);
    void clear();
    void traverse() const;
    ~SeqList();
private:
    elemType *data;
    int currentLength;
    int maxSize;
    void doubleSpace();
};

template <class elemType>
SeqList<elemType>::SeqList(int initSize) {
    this->data = new elemType[initSize];
    if(!data) throw IlligalSize();
    
    this->maxSize = initSize;
    this->currentLength = 0;
}

template <class elemType>
void SeqList<elemType>::doubleSpace() {
    elemType *tmp = new elemType[this->maxSize * 2];
    if (!tmp) {
        throw IlligalSize();
    }
    for (int i = 0; i < this->currentLength; i++) {
        tmp[i] = data[i];
    }
    delete []data;
    this->data = tmp;
    maxSize *= 2;
}

template <class elemType>
int SeqList<elemType>::length() const {
    return this->currentLength;
}

template <class elemType>
int SeqList<elemType>::search(const elemType &x) const {
    for (int i = 0; i < this->currentLength; i++) {
        if (data[i] == x) {
            return i;
        }
    }
    return -1;
}

template <class elemType>
elemType SeqList<elemType>::visit(const int i) const {
    if (0 <= i && i < this->currentLength) {
        return data[i];
    }else {
        throw OutOfBound();
    }
}

template <class elemType>
void SeqList<elemType>::insert(int i, const elemType &x) {
    if (i < 0 || i > this->currentLength) {
        return;
    }
    if (this->currentLength == this->maxSize) {
        this->doubleSpace();
    }
    for (int j = this->currentLength - 1; j >= i; j--) {
        data[j + 1] = data[j];
    }
    data[i] = x;
    this->currentLength++;
}

template <class elemType>
void SeqList<elemType>::remove(int i) {
    if (i < 0 || i >= this->currentLength) {
        return;
    }
    for (int j = i; j < this->currentLength - 1; j++) {
        data[j] = data[j + 1];
    }
    this->currentLength--;
}

template <class elemType>
void SeqList<elemType>::clear() {
    this->currentLength = 0;
}

template <class elemType>
void SeqList<elemType>::traverse() const {
    if (this->currentLength == 0) {
        std::cout << "NO things" << std::endl;
        return;
    }
    for (int i = 0; i < this->currentLength; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <class elemType>
SeqList<elemType>::~SeqList() {
    delete []data;
}