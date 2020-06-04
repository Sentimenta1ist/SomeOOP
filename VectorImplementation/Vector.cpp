#include "vector.h"

vector::vector() {
	_array = nullptr;
	_capacity = 0;
	_length = 0;
}

vector::vector(size_t sz) {
	if (sz == 0) abort();
	_array = new int[sz];
	_capacity = sz;
	_length = 0;
}

vector::vector(size_t sz, int value) {
	if (sz == 0) abort();
	_array = new int[sz];
	_capacity = sz;
	_length = sz;
	for (int i = 0; i < sz; i++) _array[i] = value;
}

vector::vector(const vector& other) {
	*this = other; 
}

vector::vector(const int* v, size_t vsz, size_t sz) {
	_length = vsz;
	_capacity = sz;
	_array = new int[sz];
	for (int i = 0; i < vsz; i++) {
		_array[i] = v[i];
	}
}

vector::~vector() {
}

void vector::pop_back() {
	erase(size() - 1);
}

void vector::push_back(int element) {
	insert(size(), element);
}

void vector::assign(size_t count, int value) {
	int old_capacity = _capacity;
	clear();
	reserve(old_capacity);
	for (int i = 0; i < count; i++) {
		push_back(value);
	}
}

void vector::assign(const vector& other) {
	int old_capacity = _capacity;
	clear();
	*this = other;
	reserve(old_capacity);
}

int& vector::at(size_t pos) {
	if (empty()) abort();
	if (_length > pos&& pos >= 0) return _array[pos];
	else throw out_of_range("at: out of range!");
}

int& vector::front() {
	if (empty()) abort();
	return at(0);
}

const int& vector::const_front() {
	if (empty()) abort();
	return at(0);
}

int& vector::back() {
	if (empty()) abort();
	return at(_length - 1);
}

const int& vector::const_back() {
	if (empty()) abort();
	return at(_length - 1);
}

size_t vector::capacity() {
	return size_t(_capacity);
}

size_t vector::size() {
	return size_t(_length);
}

void vector::clear() {
	if (empty()) return;
	delete[] _array;
	_capacity = 0;
	_length = 0;
}

void vector::erase(size_t pos) {
	if (pos >= _length || pos < 0) return;
	int* tmp = new int[_length];
	int count = 0;
	for (int i = 0; i < pos; i++) tmp[count++] = _array[i];
	for (int i = pos + 1; i < _length; i++) tmp[count++] = _array[i];
	_array = tmp;
	_length--;
}


bool vector::empty() {
	if (_length == 0)return true;
	else return false;
}

void vector::insert(size_t _where, int _val) {
	if (_where > _length)return;
	_length++;
	reserve(_length);
	int* new_arr = new int[_length];
	if (empty()) {
		_array[0] = _val;
		return;
	}
	for (auto i = 0; i < _where; i++) new_arr[i] = _array[i];
	new_arr[_where] = _val;
	for (auto i = _where + 1; i < _length; i++) {
		new_arr[i] = _array[i - 1];
	}
	_array = new_arr;
}

void vector::insert(size_t _where, size_t _count, int _val)
{
	for (int i = 0; i < _count; i++) {
		insert(_where, _val);
	}
}

void vector::reverse() {
	if (empty()) return;
	int* new_arr = new int[_length];
	for (int i = _length - 1; i >= 0; i--) {
		new_arr[_length - 1 - i] = _array[i];
	}
	_array = new_arr;
}

void vector::swap(vector& other) {
	vector one = other;
	other = *this;
	*this = one;
}

void vector::reserve(size_t size) {
	if (size <= _capacity) return;
	_capacity = size;
	int* new_array = new int[size];
	for (auto i = 0; i < this->size(); i++) {
		new_array[i] = _array[i];
	}
	_array = new_array;
}

void vector::resize(size_t count, int value) {
	if (empty()) return;
	if (count <= _length)
		while (_length != count) pop_back();
	if (count > _length)
		while (_length != count) push_back(value);
		
}

void vector::resize(size_t count) {
	resize(count, 0);
}

vector::operator int() const {
	int res = 0;
	for (auto i = 0; i < _length; i++) res += _array[i];
	return res;
}

bool vector::operator==(const vector& other) {
	if (_length != other._length) return false;
	for (int i = 0; i < _length; i++) {
		if (_array[i] != other._array[i]) return false;
	}
	return true;
}

vector& vector::operator=(const vector& other) {
	if (this == &other)return *this;
	reserve(other._capacity);
	resize(other._capacity);
	for (int i = 0; i < other._length; i++)
		_array[i] = other._array[i];
	_length = other._length;
	_capacity = other._capacity;
	return *this;
}

void vector::erase(size_t first, size_t last) {
	for (int i = 0; i < last - first; i++) {
		erase(first);
	}
}

void vector::sort() {
	for (int i = 0; i < _length - 1; i++)
		for (int j = 0; j < _length - i - 1; j++)
			if (_array[j] > _array[j + 1]){
				int tmp = _array[j];
				_array[j] = _array[j + 1];
				_array[j + 1] = tmp;
			}
}

size_t vector::unique() {
	if (empty()) return 0;
	sort();

	for (int i = 1; i < _length; i++) {
		if (_array[i] == _array[i - 1]) {
			erase(i); i--;
		}
	}
	return size_t(_length);
}

void vector::print(){
	if (_length < 0) return;
	if (empty()) cout << "- none -";
	for (int i = 0; i < _length; i++) {
		cout << _array[i] << ' ';
	}
	cout << endl << "length - " << _length;
	cout << endl << "capacity - " << _capacity << endl << endl;
}