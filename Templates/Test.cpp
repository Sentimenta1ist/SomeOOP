#include "List.h"



int main() {
	List<Bus> FirstList;   //in the park
	List<Bus> SecondList;  // int the route

	Bus alone;
	cout << alone;
	alone.SetBus("");
	alone.SetDriver("");
	alone.SetRoute("");
	//cout << alone.GetBus();
	cout << alone;
	alone.SetBus("1");
	alone.SetDriver("Chelik");
	alone.SetRoute("Maiamo!");
	cout << alone;
	cout << FirstList.size() << endl;

	if (FirstList.empty()) cout << "empty";
	else cout << "no empty";

	cout << endl;
	//FirstList.push_front(alone);
	if (FirstList.empty()) cout << "empty";
	else cout << "no empty";

	cout << endl;

	FirstList.load("park.csv");

	if (FirstList.empty()) cout << "empty";
	else cout << "no empty";
	cout << "LIST1:" << endl;
	FirstList.Print();
	cout << "LIST2:" << endl;
	SecondList.Print();
	
	return 0;	
}


/*
while (1) {
	cout << " Buses in rout:" << endl;
	cout << "BUS # 2" << endl;
	cout << "----------" << endl;
	cout << "|--|--|--|" << endl;
	cout << "0--------0  ==" << endl;
	cout << "BUS # 4" << endl;
	cout << "----------" << endl;
	cout << "|--|--|--|" << endl;
	cout << "0--------0  ==" << endl << endl;
	cout << " Buses in PARK:" << endl;
	cout << "BUS # 1" << endl;
	cout << "----------" << endl;
	cout << "|--|--|--|" << endl;
	cout << "0--------0 " << endl;
	cout << " Buses in PARK:" << endl;
	cout << "BUS # 3" << endl;
	cout << "----------" << endl;
	cout << "|--|--|--|" << endl;
	cout << "0--------0 " << endl;
	system("cls");
	cout << " Buses in rout:" << endl;
	cout << "BUS # 2" << endl;
	cout << "----------" << endl;
	cout << "|--|--|--|" << endl;
	cout << "0--------0  == ==" << endl;
	cout << "BUS # 4" << endl;
	cout << "----------" << endl;
	cout << "|--|--|--|" << endl;
	cout << "0--------0  == ==" << endl << endl;
	cout << " Buses in PARK:" << endl;
	cout << "BUS # 1" << endl;
	cout << "----------" << endl;
	cout << "|--|--|--|" << endl;
	cout << "0--------0 " << endl;
	cout << " Buses in PARK:" << endl;
	cout << "BUS # 3" << endl;
	cout << "----------" << endl;
	cout << "|--|--|--|" << endl;
	cout << "0--------0 " << endl;
	system("cls");
	cout << " Buses in rout:" << endl;
	cout << "BUS # 2" << endl;
	cout << "----------" << endl;
	cout << "|--|--|--|" << endl;
	cout << "0--------0  == == ===" << endl;
	cout << "BUS # 4" << endl;
	cout << "----------" << endl;
	cout << "|--|--|--|" << endl;
	cout << "0--------0  == == ===" << endl << endl;
	cout << " Buses in PARK:" << endl;
	cout << "BUS # 1" << endl;
	cout << "----------" << endl;
	cout << "|--|--|--|" << endl;
	cout << "0--------0 " << endl;
	cout << " Buses in PARK:" << endl;
	cout << "BUS # 3" << endl;
	cout << "----------" << endl;
	cout << "|--|--|--|" << endl;
	cout << "0--------0 " << endl;
	system("cls");

}
*/



