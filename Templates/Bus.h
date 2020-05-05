#pragma once
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;


class Bus
{
public:
	
//methods
	Bus();
	char* GetDriver();
	char* GetBus();
	char* GetRoute();
	void SetDriver(const char*);
	void SetBus(const char*);
	void SetRoute(const char*);
	friend ostream& operator<<(ostream& stream, Bus& obj);
private:
	char* driver;
	char* bus_number;
	char* route_number;
};
