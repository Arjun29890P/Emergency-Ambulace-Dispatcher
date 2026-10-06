#include "../include/EmergencyRequest.h"
#include <iostream>

using namespace std;

EmergencyRequest::EmergencyRequest()
{
    requestID = 0;
    patientName = "";
    location = "";
    severity = 1;
    timestamp = "";
}

EmergencyRequest::EmergencyRequest(int id, string name, string loc, int sev, string time)
{
    requestID = id;
    patientName = name;
    location = loc;
    severity = sev;
    timestamp = time;
}

bool EmergencyRequest::operator<(const EmergencyRequest& other) const
{
    return this->severity < other.severity;
}

void EmergencyRequest::displayRequest() const
{
    cout << "\n--- Emergency Request Details ---" << endl;
    cout << "Request ID : " << requestID << endl;
    cout << "Patient Name : " << patientName << endl;
    cout << "Location : " << location << endl;
    cout << "Severity : " << severity << endl;
    cout << "Timestamp : " << timestamp << endl;
}

int EmergencyRequest::getSeverity() const { return severity; }