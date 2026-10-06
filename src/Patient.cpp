#include "../include/Patient.h"

void Patient::inputPatient()
{
    cout << "\n===== PATIENT DETAILS =====\n";

    cout << "Enter Patient ID : ";
    cin >> patientID;
    cin.ignore();

    cout << "Enter Patient Name : ";
    getline(cin, patientName);

    cout << "Enter Age : ";
    cin >> age;
    cin.ignore();

    cout << "Enter Disease : ";
    getline(cin, disease);

    cout << "Enter Location : ";
    getline(cin, location);
}

void Patient::displayPatient() const
{
    cout << "\nPatient ID : " << patientID << endl;
    cout << "Patient Name : " << patientName << endl;
    cout << "Age : " << age << endl;
    cout << "Disease : " << disease << endl;
    cout << "Location : " << location << endl;
}