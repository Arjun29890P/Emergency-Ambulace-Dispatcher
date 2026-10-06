#include "../include/Ambulance.h"

Ambulance::Ambulance()
{
    ambulanceID = 0;
    driverName = "";
    location = "";
    available = true;
    ambulanceType = "BLS";
}

Ambulance::Ambulance(int id, string name, string loc, string type)
{
    ambulanceID = id;
    driverName = name;
    location = loc;
    available = true;
    ambulanceType = type;
}

void Ambulance::inputAmbulance()
{
    cout << "\nEnter Ambulance ID : ";
    cin >> ambulanceID;
    cin.ignore();

    cout << "Enter Driver Name : ";
    getline(cin, driverName);

    cout << "Enter Current Location : ";
    getline(cin, location);

    cout << "Enter Ambulance Type (BLS / ICU) : ";
    cin >> ambulanceType;

    available = true;
}

void Ambulance::displayAmbulance() const
{
    cout << "\nAmbulance ID : " << ambulanceID;
    cout << "\nDriver Name : " << driverName;
    cout << "\nLocation : " << location;
    cout << "\nType : " << ambulanceType;
    cout << "\nStatus : " << (available ? "Available" : "Busy") << endl;
}

int Ambulance::getAmbulanceID() const { return ambulanceID; }
string Ambulance::getLocation() const { return location; }
bool Ambulance::isAvailable() const { return available; }
void Ambulance::setAvailability(bool status) { available = status; }
string Ambulance::getAmbulanceType() const { return ambulanceType; }