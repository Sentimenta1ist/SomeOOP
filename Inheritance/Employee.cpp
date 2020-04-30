/*!
 * file: Employee.ñpp
 * written: 23/03/2020
 */
#include "Employee.h"


string Employee::GetDepartment() { return department; }

int Employee::GetId() { return id; }

int Employee::GetSalary() { return salary; }

int Employee::GetAge() { return age; }

void Employee::SetDepartment(string dept) { this->department = dept; }

void Employee::SetId(int id) { this->id = id; }

void Employee::SetSalary(int salary) { this->salary = salary; }

void Employee::Display(bool a) {
	if (a) {
		cout << endl;
		cout << " Employment type: Employee" << endl;
		cout << " id: " << GetId() << endl;
		cout << " " << f_name << " " << l_name << "   age: " << age << "   salary: " << GetSalary() << endl;
		cout << " Department: " << GetDepartment() << endl << endl;
	}
	else {
		cout << "\t\t" << " Employment type: Employee" << endl;
		cout << "\t\t" << " id: " << GetId() << endl;
		cout << "\t\t" << " " << f_name << " " << l_name << "   age: " << age << "   salary: " << GetSalary() << endl;
		cout << "\t\t" << " Department: " << GetDepartment() << endl << endl;
	}
}

Employee::Employee(const Employee& e) {
	if (&e == nullptr) return;
	this->f_name = e.f_name;
	this->l_name = e.f_name;
	this->age = e.age;
	this->SetId(e.id);
	this->SetDepartment(e.department);
	this->SetSalary(e.salary);
}

Employee& Employee::operator=(const Employee& e) {
	if (&e == nullptr) return *this;
	this->f_name = e.f_name;
	this->l_name = e.f_name;
	this->age = e.age;
	this->SetId(e.id);
	this->SetDepartment(e.department);
	this->SetSalary(e.salary);
	return *this;

}