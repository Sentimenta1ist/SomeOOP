#include "List.h"



int main() {
	List<Bus> ParkList;   //in the park
	List<Bus> RouteList;  // in the route
	Bus alone;
	alone.SetBus("11");
	alone.SetDriver("Man");
	alone.SetRoute("100");

	if (ParkList.empty()) cout << "List park is empty" << endl;
	else cout << "List park isn't empty" << endl;
	ParkList.Print();

	cout << "Check load func:" << endl;
	ParkList.load("park.csv");
	cout << "Park List:" << endl;
	ParkList.Print();

	if (ParkList.empty()) cout << "List park is empty" << endl;
	else cout << "List park isn't empty" << endl;

	cout <<endl<< "Check SPLICE:" << endl << endl;
	cout << "Park List before splice:" << endl;
	ParkList.Print();
	cout << "Route List before splice:" << endl;
	RouteList.Print();
	ParkList.splice(ParkList.begin(), RouteList);
	ParkList.splice(ParkList.begin(), RouteList);
	ParkList.splice(ParkList.begin(), RouteList);
	RouteList.splice(RouteList.end(), ParkList);
	cout << "Park List after splice:" << endl;
	ParkList.Print();
	cout << "Route List after splice:" << endl;
	RouteList.Print();
	
	cout << endl << "Check push_front & pop_front:" << endl;
	RouteList.pop_front();
	RouteList.push_front(alone);
	RouteList.Print();

	cout << endl << "Check find func:" << endl;
	alone.SetBus("3");
	if (RouteList.find(alone) == nullptr) cout << "null" << endl;
	else cout << (*RouteList.find(alone)).data << endl;
	alone.SetBus("11");
	if (RouteList.find(alone) == nullptr) cout << "null" << endl;
	else cout << (*RouteList.find(alone)).data << endl;

	cout << endl << "Check remove func:" << endl;
	RouteList.remove(alone);
	RouteList.Print();

	RouteList.clear();
	RouteList.load("park.csv");
	cout << endl << "Check Output this route number :" << endl;
	RouteList.Print();
	RouteList.PrintRouteBus("15");
	RouteList.PrintRouteBus("16");

	cout << endl << "Check Change Name :" << endl;
	ParkList.Print();
	ParkList.ChangeDriver("Sasha", "NeSasha");
	ParkList.Print();


	return 0;	
}


