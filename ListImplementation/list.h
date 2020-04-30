/*!
 * file: list_test.cpp
 * list class declaration
 * written: 29/02/2020
 */
#pragma once
#include <string>
#include <iostream>

using namespace std;


struct node {
    int data;
    node* next;
};

class List {
public:
    List();
    List(size_t count, int val);
    List(const List& other);
    ~List(void);
    const node& back() const;
    node& back();
    const node& begin() const;
    node& begin();
    void clear();
    bool empty() const;
    void erase(size_t pos);
    void erase(size_t first, size_t last);
    void insert(int value, size_t pos);
    void insert(int val, unsigned pos, unsigned count);
    void insert(size_t pos, int* v, size_t count);
    void merge(List& other);
    void pop_back();
    void pop_front();
    void push_back(int val);
    void push_front(int value);
    void remove(int value);
    void resize(size_t count, int value);
    void resize(size_t count);
    void reverse();
    size_t size() const;
    void sort();
    void splice(size_t pos, List& other);
    void swap(List& other);
    void unique();
    void display();
    operator int() const;
    bool operator==(const List&);
    List& operator=(const List&);
private:
    int length;
    node* head, * tail;
};




