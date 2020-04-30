/*!
 * file: test.cpp
 * written: 23/03/2020
 */
#include "Database.h"

int main() {
    Database base;
    cout << "WITHOUT SUBS:" << endl;
    base.LoadFromFile("input.csv");
    base.DisplayAll();

    cout << "WITH SUBS:" << endl;
    base.ArrangeSubordinates();
    base.DisplayAll();
    
    cout << "HIRE EMP:" << endl;
    Employee emp("Guf", "Fuf", 40, 7);
    emp.SetSalary(1000);
    emp.SetDepartment("IT");
    base.HireEmployee(&emp);
    Manager man("Guf", "Fuf", 40,8);
    man.SetSalary(1000);
    man.SetDepartment("Z");
    Employee emp2(emp);
    Manager man2(man);
    base.HireEmployee(&man2);
    base.HireEmployee(&emp2);
    base.HireEmployee(&man);
    base.DisplayAll();

    cout << "FIRE EMP:" << endl;
    cout << base.FireEmployee(0) << endl;
    cout << base.FireEmployee(10) << endl;
    base.DisplayAll();

    cout << "Operators:" << endl << endl;
    Manager man3 = man;
    Employee emp3 = emp;
    man = man;
    emp3 = emp3;
    man.Display(1);
    man3.Display(1);
    emp.Display(1);
    emp3.Display(1);

    cout << " SQL :" << endl << endl;
    vector<Person*>vec = base.SQL("age", "le", "15");
    base.ShowRecordSet(vec);
    vec = base.SQL("age", "ge", "15");
    base.ShowRecordSet(vec);

    //vec = base.SQL("agde", "ge", "15");
    
    cout << "DisplayDepartmentEmployees :" << endl << endl;
    base.DisplayDepartmentEmployees("IT");
    return 0;
}