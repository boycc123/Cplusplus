/*
一个线性表需要的功能
1.创建表  create    通过构造函数实现
2.求线性表的长度 length
3.搜索某个数据 search   通过数据返回下标
4.访问数据 visit    通过下标返回数据
5.插入数据 insert
6.删除数据 remove
7.清除线性表 clear
8.遍历线性表 traverse

*/

#pragma once


// 线性表的抽象类
template <class elemType>
class List{
public:
    virtual int length() const = 0;
    virtual int search(const elemType &x) const = 0;
    virtual elemType visit(const int i) const = 0;
    virtual void insert(int i, const elemType &x) = 0;
    virtual void remove(int i) = 0;
    virtual void clear() = 0;
    virtual void traverse() const = 0;
    virtual ~List() {}; // 以防内存泄露
private:



};