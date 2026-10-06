#include "../include/Report.h"
#include <iostream>

using namespace std;

void Report::generateSystemSummary(const vector<Hospital>& hospitals,
                                   const vector<Ambulance>& ambulances,
                                   const vector<Patient>& patients)
{
    cout << "\n========================================\n";
    cout << "      SYSTEM SUMMARY & STATISTICS       \n";
    cout << "========================================\n";
    cout << "Total Registered Hospitals  : " << hospitals.size() << endl;
    cout << "Total Registered Ambulances : " << ambulances.size() << endl;
    
    int availableCount = 0;
    for (size_t i = 0; i < ambulances.size(); ++i)
    {
        if (ambulances[i].isAvailable()) 
        {
            availableCount++;
        }
    }
    
    cout << "Available Ambulances        : " << availableCount << endl;
    cout << "Busy/Dispatched Ambulances  : " << (ambulances.size() - availableCount) << endl;
    cout << "Total Registered Patients   : " << patients.size() << endl;
    cout << "========================================\n";
}