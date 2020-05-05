#pragma once
#include "Iterator.h"
#include "Bus.h"

template <class T>
class List {

	struct ListNode {
		T data;
		ListNode* next;
		ListNode() {
			next = NULL;
		}
		ListNode(T dat) {
			data = dat;
		}
		void Print() {
			cout << data;
		}
	};

public:
	typedef ListNode node_type;
	typedef _iterator<node_type> iterator;
	//constructors / destructors
	List();
	~List();

	//methods
	iterator begin();//Returns an iterator addressing the first element 
	iterator end();//Returns an iterator that addresses the location 
   //succeeding the last element
	bool load(const char* filename);

	void clear();//Erases all the elements of a list.
	bool empty();//Tests if a list is empty.

	iterator find(const node_type& value);//Returns an iterator to the 
// first element in a list that 
//match a specified value.

	void pop_front();//Deletes the element at the beginning of a list.

	void push_front(const node_type value);//Adds an element to the beginning 
  //of a list.
	void remove(const node_type value);//Erases first element in a list that 
   //match a specified value.


	int size();//Returns the number of elements in a list.

	void splice(iterator _Where, List<T>& _Right);//Removes element from //the target list and inserts it in first
// position of the argument list.
	void	Print();//Dumps list into the screen
private:
	node_type* head;
	iterator* first, * last;
};


template <class T>
List<T>::List() {
	head = nullptr;
	first = new iterator(nullptr);
	last = new iterator(nullptr);
}

template <class T>
List<T>::~List() {
	clear();
}

template <class T>
void List<T>::clear() {
	ListNode* tmp;
	while (head) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

template <class T>
bool List<T>::empty() {
	if (size()) return false;
	else return true;
}

template <class T>
int List<T>::size() {
	int size = 0;
	iterator it = begin();
	if (begin() == nullptr)return size;
	while (!it.empty()) {
		size++;
		it++;
	}
	return size;
}

template <class T>
typename List<T>::iterator List<T>::begin() {
	if (first->empty()) {
		return iterator(nullptr);
	}
	return iterator(*first);
}

template <class T>
typename List<T>::iterator List<T>::end() {
	return iterator(*last);
}

template <class T>
void List<T>::push_front(const node_type value) {
	if (nullptr == head) {
		head = new node_type(value);
		head->next = nullptr;
		first = new iterator(head);
		last = new iterator(head);
	}
	else {
		node_type* tmp;
		tmp = new ListNode(value);
		tmp->next = head;
		head = tmp;
		delete first;
		first = new iterator(head);
	}
}

template <class T>
void List<T>::remove(const node_type value) {

}

template <class T>
bool List<T>::load(const char* filename) {
	char str[512];
	char* res;
	FILE* file = fopen(filename, "r+");
	if (NULL == file) return false;
	while (!feof(file)) {
		if (fgets(str, 512, file)) {
			res = strdup(str);		// strdup()Returns a pointer to a null-terminated byte string, which is a duplicate of the string pointed .
			//cout << res << endl; 
			
			Bus obj;
			char* interval = strtok(res, " ;");
			int j = 0;
			while (interval != NULL && j < 3){
				switch (j) {
				case 0: obj.SetBus(interval); break;
				case 1: obj.SetDriver(interval); break;
				case 2: obj.SetRoute(interval);;  break;
				}
				interval = strtok(NULL, ";");
				j++;
			}
			this->push_front(obj);
			
		}
	}
	return true;
}

template <class T>
void List<T>::Print() {
	if (empty()) {
		cout << " - none - ";
		return;
	}
	for (iterator it = begin(); it != nullptr ; it++) 
		cout << (*it).data;
}

template <class T>
void List<T>::splice(iterator _Where, List<T>& _Right) {

}