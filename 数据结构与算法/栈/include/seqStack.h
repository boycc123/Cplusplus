#pragma once

#include "stack.h"

template <class elemType>
class SeqStack : Stack<elemType> {
public:
    SeqStack(int initSize);
    bool isEmpty() const;
    void push(const elemType &x);
    elemType pop();
    elemType top() const;
    ~SeqStack() {delete []data;}

private:
    elemType *data;
    int size;
    int maxSize;
    void doubleSpace();
};

template <class elemType>
SeqStack<elemType>::SeqStack(int initSize) : maxSize(initSize){
    data = new elemType[initSize];
    size = -1;
}

template <class elemType>
void SeqStack<elemType>::doubleSpace() {
    elemType *tmp = data;
    data = new elemType[maxSize * 2];
    for (int i = 0; i < size; i++) {
        data[i] = tmp[i];
    }
    maxSize *= 2;
    delete []tmp;
}

template <class elemTtype>
bool SeqStack<elemTtype>::isEmpty() const {
    return size == -1;
}


template <class elemType>
void SeqStack<elemType>::push(const elemType &x) {
    if (size == maxSize - 1) {
        doubleSpace();
    }
    data[++size] = x;


}

template <class elemType>
elemType SeqStack<elemType>::pop() {
    return data[size--];
}

template <class elemType>
elemType SeqStack<elemType>::top() const {
    return data[size];
}