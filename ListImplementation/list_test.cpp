/*
 * file: list_test.cpp
 * list class declaration
 * written: 29/02/2020
 */
#include "list.h"

int main() {

    cout << endl << "check constr:" << endl;
    List ls1;
    for (int i = 0; i < 10; i++) {
        ls1.push_back(i);
    }
    List ls2(5, 5);
    List ls3(ls2);
    ls1.display();
    ls2.display();
    ls3.display();

    cout << endl << "check back() begin()" << endl;
    node tmp1 = ls2.back();
    node tmp2 = ls2.begin();
    const node tmp3 = ls2.back();
    const node tmp4 = ls2.begin();
    cout << tmp1.data << tmp2.data << tmp3.data << tmp4.data << endl;

    cout << endl << "clear()" << endl;
    ls2.display();
    ls2.clear();
    ls2.display();

    for (int i = 0; i < 10; i++) {
        ls2.push_back(i);
    }

    cout << endl << "empty()" << endl;
    ls2.display();
    if (ls2.empty()) cout << "true" << endl;
    else cout << "false" << endl;
    ls3.display();
    if (ls3.empty()) cout << "true" << endl;
    else cout << "false" << endl;

    cout << endl << "erase()" << endl;
    ls1.display();
    ls1.erase(0);
    ls1.display();
    ls1.erase(3,7);
    ls1.display();

    cout << endl << "insert()" << endl;
    ls1.display();
    ls1.insert(1,2,3);
    ls1.display();
    int mas[6] = { 9,9,9,9,9,9 };
    ls1.insert(5, mas, 6);
    ls1.display();

    cout << endl << "sort()" << endl;
    ls1.display();
    ls1.sort();
    ls1.display();

    cout << endl << "merge()" << endl;
    ls1.display();
    ls3.display();
    ls1.merge(ls3);
    ls1.display();
    ls3.display();

    cout << endl << "pop_back() pop_front()" << endl;
    ls1.display();
    ls1.pop_back();
    ls1.pop_front();
    ls1.display();

    cout << endl << "push_back() push_front()" << endl;
    ls1.display();
    ls1.push_back(2);
    ls1.push_front(8);
    ls1.display();

    cout << endl << "remove()" << endl;
    ls1.display();
    ls1.remove(2);
    ls1.display();

    cout << endl << "resize()" << endl;
    ls1.display();
    ls1.resize(10);
    ls1.display();
    ls1.resize(12,10);
    ls1.display();

    cout << endl << "reverse()" << endl;
    ls1.display();
    ls1.reverse();
    ls1.display();

    cout << endl << "size():" << endl;
    ls1.display();
    cout << ls1.size() << endl;

    cout << endl << "splice():" << endl;
    ls1.display(); 
    ls2.display();
    ls1.splice(1, ls2);
    ls1.display();
    ls2.display();

    cout << endl << "swap():" << endl;
    ls1.display();
    ls2.display();
    ls1.swap(ls2);
    ls1.display();
    ls2.display();

    cout << endl << "unique():" << endl;
    ls2.display();
    ls2.unique();
    ls2.display();

    cout << endl << "operator int():" << endl;
    ls2.display();
    cout << int(ls2) << endl;

    cout << endl << "operator ==: operator =" << endl;
    ls2.display();
    ls3.display();
    if (ls2 == ls3) cout << "true" << endl;
    else cout << "false" << endl;
    ls3 = ls3;
    ls3 = ls2;
    ls2.display();
    ls3.display();
    if (ls3 == ls2) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}