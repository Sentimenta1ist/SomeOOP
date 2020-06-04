#pragma once
#pragma once

#include <iostream>
#include <set>
#include <iterator>

using namespace std;

class vector {

public:
	explicit vector();
	explicit vector(size_t sz);

	vector(size_t sz, int value);
	vector(const vector& other);
	vector(const int* v, size_t vsz, size_t sz);
	~vector();

	void pop_back();
	void push_back(int);
	void assign(size_t count, int value);
	void assign(const vector& other);
	int& at(size_t pos);
	int& front();
	const int& const_front();
	int& back();
	const int& const_back();
	size_t capacity();
	size_t size();
	void clear();
	void erase(size_t pos);
	void print();
	void erase(size_t first, size_t last);

	void sort();
	size_t unique();
	bool empty();
	void insert(size_t _where, int _val);
	void insert(size_t _where, size_t _count, int _val);
	void reverse();
	void swap(vector& other);
	void reserve(size_t size);
	void resize(size_t count, int value);
	void resize(size_t count);

	operator int() const;
	bool operator==(const vector&);
	vector& operator=(const vector&);


private:
	int* _array;
	int _capacity;
	int _length;

};
