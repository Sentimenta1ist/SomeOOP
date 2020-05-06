#pragma once
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;


class Bus
{
public:
//methods
	Bus();
	Bus(const char* _driver, const char* _bus_number, const char* _route_number);
	char* GetDriver();
	char* GetBus();
	char* GetRoute();
	void SetDriver(const char*);
	void SetBus(const char*);
	void SetRoute(const char*);
	bool operator==(const Bus&);
	Bus& operator=(const Bus&);
	friend ostream& operator<<(ostream& stream, Bus& obj);
private:
	char* bus_number;
	char* driver;
	char* route_number;
};
