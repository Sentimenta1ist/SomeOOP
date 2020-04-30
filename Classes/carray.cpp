/*
 * file: carray.cpp
 * cArray class declaration
 * written: 29/11/2019
 */
#include "carray.h"

cArray::cArray() {
	buf = NULL;
}

cArray::~cArray() {
	delete[] buf;
}

int cArray::Getsize() const {
	if (buf == NULL) return 0;
	return size;
}

int cArray::Getcount() const {
	if (buf == NULL) return 0;
	return count_of_element;
}

int cArray::Getupperbound() const {
	if (buf == NULL) return 0;
	return upperbound;
}

bool cArray::IsEmpty()const {
	if (buf == NULL) return false;
	if (count_of_element <= 0) return true;
	else return false;
}

void cArray::SetSize(int newsize) {
	if (newsize < 0) return;
	int * temp = new int[newsize];
	if (newsize < size) {
		size = newsize;
		count_of_element = size;
		upperbound = count_of_element - 1;
		for (int i = 0; i < size; i++) {
			temp[i] = buf[i];
		}
	}
	else if (newsize == size)return;
	else if (newsize > size) {
		for (int i = 0; i < size; i++) {
			temp[i] = buf[i];
		}
		size = newsize;
	}
	delete[] buf;
	buf = temp;
}

void cArray::FreeExtra() {
	if (buf == NULL) return;
	size = upperbound + 1;
	int * temp = new int[size];
	for (int i = 0; i < size; i++) {
		temp[i] = buf[i];
	}
	delete[] buf;
	buf = temp;
}

void cArray::RemoveAll(){
	upperbound = -1;
	count_of_element = 0;
}

int cArray::GetAt(int indx)const {
	if (indx < 0 || indx >= count_of_element) abort();
	return buf[indx];
}

void cArray::Add(int n) {
	if (count_of_element < size)SetAt(n, count_of_element);
	if (count_of_element == size) {
		int* temp = new int[size+GROWBY];
		for (int i = 0; i < size; i++) {
			temp[i] = buf[i];
		}
		size += GROWBY;
		delete[] buf;
		buf = temp;
		SetAt(n, count_of_element);
	}
}

void cArray::SetAt(int n, int indx) {
	if (indx > count_of_element || indx < 0) abort();
	buf[indx] = n;
	count_of_element++;
	upperbound = count_of_element - 1;
}

void cArray::Append(cArray*arr) {
	if (arr == NULL)return;
	double n = ((double)arr->Getsize() - (double)(size - count_of_element)) / (double)GROWBY;
	if (arr->Getsize() < (size - count_of_element)) n = 0;
	else n = ceil(n);	
	int* temp = new int[size + n * GROWBY];
	for (int i = 0; i < count_of_element; i++) {
		temp[i] = buf[i];
	}
	for (int i = 0; i < arr->Getsize(); i++) {
		temp[i + count_of_element] = arr->buf[i];
	}
	count_of_element += arr->Getsize();
	upperbound = count_of_element - 1;
	size += n * GROWBY;
	delete[] buf;
	buf = temp;
}

void cArray::Copy(cArray*arr) {
	if (arr == NULL) {
		size = 0;
		count_of_element = 0;
		upperbound = -1;
		buf = NULL;
		return;
	}
	double n = ((double)arr->Getsize() / (double)GROWBY);
	n = ceil(n);
	int* temp = new int[n * GROWBY];
	for (int i = 0; i < arr->Getsize(); i++) {
		temp[i] = arr -> buf[i];
	}
	size = n * GROWBY;
	count_of_element = arr->count_of_element;
	upperbound = count_of_element - 1;
	delete[] buf;
	buf = temp;
}

void cArray::printArr() {
	if (buf == NULL) {
		cout << "null";
		return;
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << " " << buf[i] << " ";
	}
	cout << endl << endl;
}

void cArray::InsertAt(int n, int indx) {
	if (indx > count_of_element || indx < 0) abort();
	if (count_of_element < size) {
		int* temp = new int[size];
		for (int i = 0; i < indx; i++) {
			temp[i] = buf[i];
		}
		temp[indx] = n;
		for (int i = indx ; i < size - 1 ; i++) {
			temp[i + 1] = buf[i];
		}
		count_of_element++;
		upperbound++;
		delete[] buf;
		buf = temp;
	}
	else if (count_of_element = size) {
		int* temp = new int[size + 1];
		for (int i = 0; i < indx; i++) {
			temp[i] = buf[i];
		}
		temp[indx] = n;
		for (int i = indx; i < size; i++) {
			temp[i + 1] = buf[i];
		}
		count_of_element++;
		upperbound++;
		size++;
		delete[] buf;
		buf = temp;
	}
}

void cArray::RemoveAt(int indx) {
	if (indx >= count_of_element || indx < 0) abort();
	int* temp = new int[size - 1];
	for (int i = 0; i < indx; i++) {
		temp[i] = buf[i];
	}
	for (int i = indx + 1; i < size; i++) {
		temp[i - 1] = buf[i];
	}
	size--;
	count_of_element--;
	upperbound--;
	delete[] buf;
	buf = temp;
}

int& cArray::operator[](int indx) {
	if (indx < 0 || indx >= count_of_element) abort();
	return buf[indx];
}
