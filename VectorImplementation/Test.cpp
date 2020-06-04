#include "Vector.h"


int main() {

	vector first_vector(5, 0);
	cout << " INSERT" << endl;
	first_vector.print();
	first_vector.insert(0, 10,1);
	first_vector.print();

	cout << "RESERVE" << endl;
	first_vector.reserve(100);
	first_vector.print();
	first_vector.print();

	cout << " CLEAR" << endl;
	first_vector.clear();
	first_vector.print();

	cout << " PUSH_PACK POP_BACK" << endl;
	for (int i = 0; i < 15; i++) {
		first_vector.push_back(i);
		first_vector.push_back(i);
		if (i % 2 == 0) first_vector.push_back(i);
	}
	first_vector.print();
	cout << "AT" << endl;
	auto i = first_vector.at(0);
	cout << i << endl;

	cout << "FRONT, BACK " << endl;
	cout << first_vector.front() << ' ';
	cout << first_vector.back() << endl;
	cout << first_vector.capacity() << ' ';
	cout << first_vector.size() << endl;

	cout << "ERASE" << endl;
	first_vector.print();
	first_vector.erase(0);
	first_vector.print();

	cout << "REVERSE" << endl;
	first_vector.print();
	first_vector.reverse();
	first_vector.print();

	cout << "SORT" << endl;
	first_vector.print();
	first_vector.reverse();
	first_vector.print();

	cout << "Operator = " << endl;
	vector second_vector;
	second_vector.print();
	first_vector.print();
	second_vector = first_vector;
	first_vector = first_vector;
	second_vector.print();

	cout << "CONSTRUCTOR COPY" << endl;
	vector third_vector(second_vector);
	third_vector.print();
	third_vector.print();

	cout << "UNIQUE" << endl;
	first_vector.print();
	first_vector.unique();
	first_vector.print();

	cout << "ASSIGN_1" << endl;
	first_vector.print();
	first_vector.assign(10, 0);
	first_vector.print();

	cout << "ASSIGN_2" << endl;
	first_vector.print();
	second_vector.print();
	second_vector.assign(first_vector);
	first_vector.print();

	cout << "RESIZE" << endl;
	int v[] = { 1,2,3,4,5,6 };
	vector f_vector(v, 6, 10);
	f_vector.print();
	f_vector.resize(12);
	f_vector.print();

	cout << "SWAP" << endl;
	first_vector.print();
	third_vector.print();
	first_vector.swap(third_vector);
	first_vector.print();
	third_vector.print();

	cout << "OPERATOR ==\n";
	if (first_vector == second_vector) cout << "true\n";
	else cout << "false\n";
	first_vector = second_vector;
	if (first_vector == second_vector) cout << "true\n";
	else cout << "false\n";


	return 0;
}