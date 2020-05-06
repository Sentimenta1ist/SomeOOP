#include "Bus.h"

Bus::Bus()
{
	this->driver = nullptr;
	this->bus_number = nullptr;
	this->route_number = nullptr;
}

Bus::Bus(const char* _driver, const char* _bus_number, const char* _route_number) {
	SetDriver(_driver);
	SetBus(_bus_number);
	SetRoute(_route_number);
}

char* Bus::GetDriver() {return this->driver;}

char* Bus::GetBus() {return this->bus_number;}

char* Bus::GetRoute(){return this->route_number;}

void Bus::SetDriver(const char* source) {
	if (source == nullptr)return;
	this->driver = new char[strlen(source) + 1];
	strcpy(this->driver, source);
}
void Bus::SetBus(const char* source) {
	if (source == nullptr)return;
	this->bus_number = new char[strlen(source) + 1];
	strcpy(this->bus_number, source);
}
void Bus::SetRoute(const char* source) {
	if (source == nullptr)return;
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

Bus& Bus::operator=(const Bus& bus) {
	if (&bus == nullptr) return *this;
	if (&bus == this) return *this;
	SetBus(bus.bus_number);
	SetDriver(bus.driver);
	SetRoute(bus.route_number);
	return *this;
}


bool Bus::operator ==(const Bus& one) {
	if ((one.driver == nullptr) || (this->driver == nullptr)) return false;
	if (0 == strcmp(one.bus_number,this->bus_number)) {
		if (0 == strcmp(one.driver, this->driver)) {
			if (0 == strcmp(one.route_number,this->route_number)) {
				return true;
			}
		}
	}
	return false;
}