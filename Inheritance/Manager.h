/*!
 * file: Manager.h
 * written: 23/03/2020
 */
#pragma once
#include "Employee.h"

class Manager : public Employee {
public:
	Manager() {};
	Manager(string _f_name, string _l_name, int _age, int _id) :
		Employee(_f_name, _l_name, _age, _id) {};
	Manager(const Manager& m);
	Manager& operator=(const Manager& m);

	virtual void Display(bool) override;
	Person* AddSubordinate(Person* p);
	void DisplaySubordinates();
	void DeleteSubs(int id);

private:
	list <Person*> subordinates;//список підлеглих
};
