/*!
 * file: Manager.cpp
 * written: 23/03/2020
 */
#include "Manager.h"



Manager::Manager(const Manager& m) {
	if (&m == nullptr)return;
	this->f_name = m.f_name;
	this->l_name = m.f_name;
	this->age = m.age;
	this->SetId(m.id);
	this->SetDepartment(m.department);
	this->SetSalary(m.salary);
	this->subordinates = m.subordinates;
}
Manager& Manager::operator=(const Manager& m) {
	if (&m == nullptr)return *this;
	this->f_name = m.f_name;
	this->l_name = m.f_name;
	this->age = m.age;
	this->SetId(m.id);
	this->SetDepartment(m.department);
	this->SetSalary(m.salary);
	this->subordinates = m.subordinates;
	return *this;

}


void Manager::Display(bool a) {
	cout << " Employment type: Manager" << endl;
	cout << " id: " << GetId() << endl;
	cout << " " << f_name << " " << l_name << "   age: " << age << "   salary: " << GetSalary() << endl;
	cout << " Department: " << GetDepartment() << endl;
	DisplaySubordinates();
}

Person* Manager::AddSubordinate(Person* p) {
	if (typeid(*p) == typeid(Manager))return nullptr;
	if (typeid(*p) == typeid(Employee)) {
		if (dynamic_cast<Employee*>(p)->GetDepartment() == this->GetDepartment()) {
			for (Person* one : subordinates) {
				if (dynamic_cast<Employee*>(p)->GetId() == dynamic_cast<Employee*>(one)->GetId()) {
					return nullptr;
				}
			}
			subordinates.push_back(p);
		}
	}
	return nullptr;
}
void Manager::DisplaySubordinates() {
	cout << " Subordinates:" << endl;
	if (subordinates.size() == 0) {
		cout << "\t\t" << "none" << endl;
		return;
	}
	for (Person* p : subordinates) {
		p->Display(0);
	}
	cout << endl;
}

void Manager::DeleteSubs(int id) {
	for (list<Person*>::iterator p = subordinates.begin(); p != subordinates.end(); p++) {
		if (dynamic_cast<Employee*>(*p)->GetId() == id) {
			p = subordinates.erase(p);
			return;
		}
	}
}
