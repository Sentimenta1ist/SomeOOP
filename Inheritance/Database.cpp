/*!
 * file: Database.ñpp
 * written: 23/03/2020
 */
#include "Database.h"


void Database::ArrangeSubordinates() {
	for (Person* m : employees) {
		if (typeid(*m) == typeid(Manager)) {
			for (Person* e : employees) {
				dynamic_cast<Manager*>(m)->AddSubordinate(e);
			}
		}
	}
}

void Database::DisplayAll() {
	for (Person* p : employees) {
		if (typeid(*p) == typeid(Manager)) {
			p->Display(1);
		}
		if (typeid(*p) == typeid(Employee)) {
			p->Display(1);
		}
	}
}

Person* Database::HireEmployee(Person* p) {
	if (p == nullptr) return nullptr;
	for (Person* m : employees)
		if (dynamic_cast<Employee*>(m)->GetId() == dynamic_cast<Employee*>(p)->GetId())
			return nullptr;

	if (typeid(*p) == typeid(Manager)) {
		Manager* one = new Manager();
		one = dynamic_cast<Manager*>(p);
		employees.push_back(p);
		return one;
	}

	if (typeid(*p) == typeid(Employee)) {
		Employee* one = new Employee();
		one = dynamic_cast<Employee*>(p);
		employees.push_back(p);
		ArrangeSubordinates();
		return one;
	}
	return nullptr;
}

bool Database::FireEmployee(int id) {
	for (vector<Person*>::iterator p = employees.begin(); p != employees.end(); p++) {
		if ((typeid(**p) == typeid(Employee)) && (dynamic_cast<Employee*>(*p)->GetId() == id)) {
			for (vector<Person*>::iterator p2 = employees.begin(); p2 != employees.end(); p2++) {
				if (typeid(**p2) == typeid(Manager)) {
					dynamic_cast<Manager*>(*p2)->DeleteSubs(id);
				}

			}
			p = employees.erase(p);
			return true;
		}
		if ((typeid(**p) == typeid(Manager)) && (dynamic_cast<Manager*>(*p)->GetId() == id)) {
			p = employees.erase(p);
			return true;
		}
	}
	return false;
}

vector<Person*> Database::SQL(const char* field, const char* cond, const char* value) {
	vector<Person*> result;
	if (field == "age") {
		if (cond == "le") {
			for (Person* p : employees) {
				if ((dynamic_cast<Employee*>(p)->GetAge() <= atoi(value)))result.push_back(p);
			}
		}
		else if (cond == "ge") {
			for (Person* p : employees) {
				if ((dynamic_cast<Employee*>(p)->GetAge() >= atoi(value)))result.push_back(p);
			}
		}
		else abort();
	}
	else if (field == "salary") {
		if (cond == "le") {
			for (Person* p : employees) {
				if ((dynamic_cast<Employee*>(p)->GetSalary() <= atoi(value)))result.push_back(p);
			}
		}
		else if (cond == "ge") {
			for (Person* p : employees) {
				if ((dynamic_cast<Employee*>(p)->GetSalary() >= atoi(value)))result.push_back(p);
			}
		}
		else abort();
	}
	else abort();
	return result;
}

void Database::ShowRecordSet(vector<Person*> rs) {
	if (rs.empty()) return;
	for (Person* p : rs) {
		p->Display(1);
	}
}

void Database::DisplayDepartmentEmployees(string _department) {
	for (Person* p : employees) {
		if (typeid(*p) == typeid(Manager)) {
			if ((dynamic_cast<Manager*>(p)->GetDepartment() == _department)) {
				p->Display(1);
			}
		}
		if (typeid(*p) == typeid(Employee)) {
			if ((dynamic_cast<Employee*>(p)->GetDepartment() == _department)) {
				p->Display(1);
			}
		}
	}
}


bool Database::LoadFromFile(const char* file) {
	ifstream f(file);
	string line;
	string str_tmp;
	vector<string> employ;
	if (f.is_open()) {
		while (getline(f, line)) {
			for (int i = 0; i < line.size(); i++) {
				if (line[i] != ';') {
					str_tmp += line[i];
					continue;
				}
				employ.push_back(str_tmp);
				str_tmp.clear();
			}
			employ.push_back(str_tmp);
			str_tmp.clear();
			if (atoi(employ[0].c_str()) == 0) {
				Employee* one = new Employee(employ[2], employ[3], atoi(employ[4].c_str()), atoi(employ[1].c_str()));
				one->SetDepartment(employ[5]);
				one->SetSalary(atoi(employ[6].c_str()));

				employees.push_back(one);
				employ.clear();
				continue;
			}

			if (atoi(employ[0].c_str()) == 1) {
				Manager* one = new Manager(employ[2], employ[3], atoi(employ[4].c_str()), atoi(employ[1].c_str()));
				one->SetDepartment(employ[5]);
				one->SetSalary(atoi(employ[6].c_str()));

				employees.push_back(one);
				employ.clear();
				continue;
			}

		}

		return true;
	}
	return false;
}