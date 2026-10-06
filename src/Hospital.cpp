#include "../include/Hospital.h"

Hospital::Hospital()
{
    hospitalID = 0;
    hospitalName = "";
    location = "";
    totalAmbulances = 0;
}

void Hospital::inputHospital()
{
    cout << "Enter Hospital ID: ";
    cin >> hospitalID;

    cin.ignore();

    cout << "Enter Hospital Name: ";
    getline(cin, hospitalName);

    cout << "Enter Location: ";
    getline(cin, location);

    cout << "Enter Total Ambulances: ";
    cin >> totalAmbulances;
}

void Hospital::displayHospital() const
{
    cout << "\nHospital ID: " << hospitalID << endl;
    cout << "Hospital Name: " << hospitalName << endl;
    cout << "Location: " << location << endl;
    cout << "Total Ambulances: " << totalAmbulances << endl;
}

int Hospital::getHospitalID() const
{
    return hospitalID;
}

string Hospital::getHospitalName() const
{
    return hospitalName;
}

string Hospital::getLocation() const
{
    return location;
}

int Hospital::getTotalAmbulances() const
{
    return totalAmbulances;
}

void Hospital::setTotalAmbulances(int total)
{
    totalAmbulances = total;
}