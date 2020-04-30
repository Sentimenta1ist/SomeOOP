/*!
 * file: Database.h
 * written: 23/03/2020
 */
#pragma once
#include "Manager.h"

class Database {

public:
	Database() {};
	~Database() {};//no need in destructor

	bool LoadFromFile(const char* file);
	void ArrangeSubordinates();
	Person* HireEmployee(Person* p);
	void DisplayDepartmentEmployees(string _department);
	bool FireEmployee(int id);
	void DisplayAll();
	vector<Person*> SQL(const char* field, const char* cond, const char* value);
	void ShowRecordSet(vector<Person*> rs);

private:
	vector<Person*> employees;
};
