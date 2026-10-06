#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
using namespace std;

class Patient
{
private:
    int patientID;
    string patientName;
    int age;
    string disease;
    string location;

public:
    void inputPatient();
    void displayPatient() const; // Must have const here!
};

#endif