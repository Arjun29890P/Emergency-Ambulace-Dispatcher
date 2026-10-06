#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <string>

using namespace std;

class Hospital
{
private:
    int hospitalID;
    string hospitalName;
    string location;
    int totalAmbulances;

public:
    Hospital();

    void inputHospital();
    void displayHospital() const; // Must have const here!

    int getHospitalID() const;
    string getHospitalName() const;
    string getLocation() const;
    int getTotalAmbulances() const;

    void setTotalAmbulances(int total);
};

#endif