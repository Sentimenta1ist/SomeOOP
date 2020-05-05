#include "Bus.h"


Bus::Bus()
{
	this->driver = nullptr;
	this->bus_number = nullptr;
	this->route_number = nullptr;
}

char* Bus::GetDriver() {return this->driver;}

char* Bus::GetBus() {return this->bus_number;}

char* Bus::GetRoute(){return this->route_number;}

void Bus::SetDriver(const char* source) {
	if (!strlen(source))return;
	this->driver = new char[strlen(source) + 1];
	strcpy(this->driver, source);
}
void Bus::SetBus(const char* source) {
	if (!strlen(source))return;
	this->bus_number = new char[strlen(source) + 1];
	strcpy(this->bus_number, source);
}
void Bus::SetRoute(const char* source) {
	if (!strlen(source))return;
	this->route_number = new char[strlen(source) + 1];
	strcpy(this->route_number, source);
}

ostream& operator<<(ostream& stream, Bus& obj) {
	if (obj.GetBus() == nullptr) cout << "Bus # --- " << endl;
	else cout << "Bus # " << obj.GetBus() << endl;

	if (obj.GetDriver() == nullptr) cout << "Driver - \"none\" " << endl;
	else cout << "Driver - " << obj.GetDriver() << endl;

	if (obj.GetRoute() == nullptr) cout << "Route -> --- " << endl << endl;
	else cout << "Route -> " << obj.GetRoute() << endl << endl;

	return stream;
}