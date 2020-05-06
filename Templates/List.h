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
												  //position of the argument list.

	void	Print();//Dumps list into the screen

	void PrintRouteBus(const char*);
	void ChangeDriver(const char* oldname, const char* newname);

private:
	node_type* head;
	iterator* first, * last;
};


template <class T>
List<T>::List() {
	head = nullptr;
	first = new iterator(head);
	last = new iterator(nullptr);
}

template <class T>
List<T>::~List() {
	clear();
}

template <class T>
void List<T>::clear() {
	while (head != nullptr) {
		pop_front();
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
	for (iterator it = begin(); it != nullptr; it++) size++;
	return size;
}

template<class T>
void List<T>::pop_front() {
	if (head == nullptr) abort();
	node_type* tmp = head;
	head = head->next;
	*first = iterator(head);
	delete tmp;
}

template <class T>
typename List<T>::iterator List<T>::begin() {
	if (first->empty()) {
		return iterator(nullptr);
	}
	return *first;
}

template <class T>
typename List<T>::iterator List<T>::end() {
	return *last;
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
		node_type* tmp = new node_type(value);
		tmp->next = head;
		head = tmp;
		delete first;
		first = new iterator(head);
	}
}

template <class T>
typename List<T>::iterator List<T>::find(const node_type& value) {
	if (empty())return nullptr;
	for (iterator it = begin(); it != nullptr; it++) 
		if ((*it).data == value.data) {
			//cout << (*it).data;
			return it;
		}
	return nullptr;

}

template <class T>
void List<T>::remove(const node_type value) {
	if (head == nullptr) return;
	if (head->data == value.data) {
		pop_front();
		return ;
	}

	
	node_type* One = head;
	node_type* tmp;
	for (One = head; One->next != nullptr; One = One->next) {
		if (One->next->data == value.data) {
			tmp = One->next->next;
			delete One->next;
			One->next = tmp;			
			return ;
		}
	}
	return ;

}

template <class T>
bool List<T>::load(const char* filename) {
	char str[512];
	char* res;
	FILE* file = fopen(filename, "r+");
	if (NULL == file) return false;
	while (!feof(file)) {
		if (fgets(str, 512, file)) {
			res = strdup(str);
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
			free(res);
			
		}
	}
	return true;
}

template <class T>
void List<T>::Print() {
	cout << endl;
	if (empty()) {
		cout << " - none - " << endl;
		cout << "Size of list - " << size() << endl << endl;
		return;
	}
	for (iterator it = begin(); it != nullptr ; it++) 
		cout << (*it).data;
	cout << "Size of list - " << size() << endl << endl;
}

template <class T>
void List<T>::splice(iterator _Where, List<T>& _Right) {
	if ((this->empty())||(find((*_Where).data) == nullptr)) return;
	_Right.push_front((*_Where).data);
	this->remove((*_Where).data);	
}

template <class T>
void List<T>::PrintRouteBus(const char* route) {
	if ((this->empty()) || (route == nullptr)) return;
	cout << "Route :" << route << endl;
	int flag = 0;
	for (iterator it = begin(); it != nullptr; it++) {
		Bus alone = (*it).data;
		if (0 == strcmp(alone.GetRoute(),route)) {
			cout << alone;
			flag = 1;
		}
	}
	if (flag == 0) cout << " - none -";
	cout << endl;
}

template <class T>
void List<T>::ChangeDriver(const char* oldname, const char* newname ) {
	if (this->empty()) return;
	if (oldname == nullptr || newname == nullptr)return;
	for (iterator it = begin(); it != nullptr; it++) {
		Bus alone = (*it).data;
		if (0 == strcmp(alone.GetDriver(), oldname)) {
			alone.SetDriver(newname);
			(*it).data = alone;
		}
	}
}