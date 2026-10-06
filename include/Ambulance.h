#ifndef AMBULANCE_H
#define AMBULANCE_H

#include <string>
#include <iostream>

using namespace std;

class Ambulance
{
private:
    int ambulanceID;
    string driverName;
    string location;
    bool available;
    string ambulanceType; // "BLS" (Basic) or "ICU" (Advanced)

public:
    Ambulance();
    Ambulance(int id, string name, string loc, string type);

    void inputAmbulance();
    void displayAmbulance() const;

    int getAmbulanceID() const;
    string getLocation() const;
    bool isAvailable() const;
    void setAvailability(bool status);
    string getAmbulanceType() const;
};

#endif