/*
 * file: list.cpp
 * cArray class declaration
 * written: 29/02/2020
 */
#include "list.h"

List::List(){
    head = nullptr;
    tail = nullptr;
    length = 0;
}

List::List(size_t count, int value) {
    head = nullptr;
    tail = nullptr;
    length = 0;
    for (int i = 0; i < count; i++) {
        push_back(value);
    }
}

List::~List(void) {
    clear();
}

List::List(const List& other) {
    head = nullptr;
    tail = nullptr;
    length = 0;
    node* tmp = other.head;
    while(tmp != nullptr){
        push_back(tmp->data);
        tmp = tmp->next;
    }
}

void List::display() {
    if (head == nullptr) cout << "nullptr";
    node* tmp = head;
    while (tmp != nullptr) {
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
    cout << ' ' << "length = " << length << endl;
}

void List::push_back(int value){   
    insert(value, length);
}

void List::push_front(int value) {
    insert(value, 0);
}

void List::insert(int value, size_t pos) {
    if (pos > length) return;
    node* tmp = new node;
    node* tmp_while = head;
    node* tmp_while2 = head;
    size_t cur_pos = 0;
    tmp->data = value;
    length++;
    if (head == nullptr) {
        tmp->next = nullptr;
        head = tmp;
        tail = tmp;
        return;
    }
    if (pos == 0) {
        tmp->next = head;
        head = tmp;
        return;
    }
    if (pos == length - 1) {
        tmp->next = nullptr;
        tail->next = tmp;
        tail = tail->next;
        return;
    }
    while (tmp_while != nullptr) {
        if (cur_pos == pos - 1) {
            tmp_while2 = tmp_while2->next;
            tmp_while->next = tmp;
            tmp->next = tmp_while2;
            return;
        }
        tmp_while2 = tmp_while2->next;
        tmp_while = tmp_while->next;
        cur_pos++;
    }
}

node& List::back() {
    if (tail == nullptr) abort();
    return *tail;
}


const node& List::back() const {
    if (tail == nullptr) abort();
    return *tail;
}

node& List::begin() {
    if (head == nullptr) abort();
    return *head;
}

const node& List::begin() const {
    if (head == nullptr) abort();
    return *head;
}


void List::erase(size_t pos) {
    if (pos >= length) return;
    if (empty()) return;
    if (length == 1) {
        length = 0;
        head = nullptr;
        return;
    }
    node* tmp = head;
    node* tmp2 = head;
    int cur_pos = 0;
    if (pos == 0) {
        head = tmp->next;
        tmp2 = tmp2->next;
        head->next = tmp2->next;
        head->data = tmp->next->data;
        delete tmp;
        length--;
        return;
    }
    while (tmp != nullptr) {
        if (pos == cur_pos + 1) {
            if (pos == length - 1) {
                tail = tmp;
                tail->data = tmp->data;
                tmp = tmp->next;
                length--;
                delete tmp;
                tail->next = nullptr;               
                return;
            }
            tmp2 = tmp2->next;
            tmp->next = tmp2->next;
            tmp2->data = tmp2->next->data;
            delete tmp2;
            length--;
            return;
        }
        cur_pos++;
        tmp = tmp->next;
        tmp2 = tmp2->next;      
    }
}

void List::erase(size_t first, size_t last) {
    if (empty()) return;
    if ((first >= length) || (last >= length))return;
    for (int i = first; i <= last; i++) {
        erase(first);
    }
}

bool List::empty() const {
    if (0 == length) return true;
    return false;
}

void List::clear() {
    while (!empty()) {
        erase(0);
    }
}

void List::pop_back() {
    if (empty())return;
    erase(length - 1);
}

void List::pop_front() {
    if (empty())return;
    erase(0);
}

void List::insert(int val, unsigned pos, unsigned count) {
    for (int i = 0; i < count; i++) {
        insert(val, pos);
    }
}

void List::insert(size_t pos, int* v, size_t count) {
    for (int i = 0; i < count; i++) {
        insert(v[count - 1 - i], pos);
    }
}

void List::resize(size_t count, int value) {
    if (length < count)insert(value, unsigned(length), count - length);
    if (length > count)erase(count, length - 1);
    if (length == count)return;
}

void List::resize(size_t count) {
    resize(count, 0);
}

void List::unique() {
    if (empty())return;
    node* tmp = head;
    int pos = 0;
    while (tmp->next != nullptr) {
        if (tmp->data == tmp->next->data) {
            tmp = tmp->next;
            erase(pos);
            continue;
        }
        tmp = tmp->next;
        pos++;
    }

}

void List::remove(int value) {
    node* tmp = head;
    int pos = 0;
    while (tmp != nullptr) {
        if (tmp->data == value) {
            tmp = tmp->next;
            erase(pos);
            continue;
        }
        tmp = tmp->next;
        pos++; 
    }
}

size_t List::size() const {
    return length;
}

void List::sort() {
    if (empty()) return;
    node* tmp = head;
    int data;
    int flag = 1;
    while (flag) {
        flag = 0;
        tmp = head;
        while (tmp->next != nullptr) {
            if (tmp->data > tmp->next->data) {
                data = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = data;
                flag = 1;
            }
            tmp = tmp->next;
        }
    }
}

void List::splice(size_t pos, List& other) {
    if (other.empty())return;
    if (pos > length) return;
    node* tmp;
    other.reverse();
    while(other.size()){
        tmp = other.head;
        insert(tmp->data, pos);
        other.erase(0);
    }
}

void List::reverse() {
    if (empty())return;
    node* tmp = head;
    while (tmp != nullptr) {
        push_front(tmp->data);
        tmp = tmp->next;
    }
    resize(length / 2);
}

List::operator int() const {
    if (empty())return 0;
    node* tmp = head;
    int sum = tmp->data;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
        sum += tmp->data;
    }
    return sum;
}

bool List::operator==(const List& other) {
    if (length != other.length) return false;
    sort();
    List example(other);
    node* tmp = head;
    node* tmp2 = example.head;
    example.sort();
    while (tmp != nullptr) {
        if (tmp->data != tmp2->data) {
            example.clear();
            return false;
        }
        tmp = tmp->next;
        tmp2 = tmp2->next;
    }
    example.clear();
    return true;
}

List& List::operator=(const List& other) {
    if (this == &other)
        return *this;
    resize(other.length);
    node* tmp = head;
    node* tmp_other = other.head;
    while (tmp != nullptr) {
        tmp->data = tmp_other->data;
        tmp = tmp->next;
        tmp_other = tmp_other->next;
    }
    return *this;
}

void List::swap(List& other) {
    List tmp(*this);
    *this = other;
    other = tmp;
}

void List::merge(List& other) {
    splice(length, other);
    sort();
    unique();
}


