#ifndef EMERGENCYREQUEST_H
#define EMERGENCYREQUEST_H

#include <string>

using namespace std;

class EmergencyRequest
{
private:
    int requestID;
    string patientName;
    string location;
    int severity;
    string timestamp;

public:
    EmergencyRequest();
    EmergencyRequest(int id, string name, string loc, int sev, string time);

    bool operator<(const EmergencyRequest& other) const;

    void displayRequest() const;
    int getSeverity() const;
};

#endif