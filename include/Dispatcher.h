#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <vector>
#include <queue>
#include <stack>
#include <string>
#include "Hospital.h"
#include "Ambulance.h"
#include "Patient.h"
#include "EmergencyRequest.h"
#include "Graph.h"

using namespace std;

class Dispatcher
{
private:
    vector<Hospital> hospitals;
    vector<Ambulance> ambulances;
    vector<Patient> patients;
    priority_queue<EmergencyRequest> emergencyQueue;
    Graph cityGraph;
    stack<pair<EmergencyRequest, Ambulance>> dispatchHistory; // Stack for history and undo operations

public:
    void registerHospital(const Hospital& h);
    void registerAmbulance(const Ambulance& a);
    void registerPatient(const Patient& p);
    void addEmergencyRequest(const EmergencyRequest& req);
    void addRoadEdge(string u, string v, int weight);

    void displayAllRecords() const;
    void displayGraph() const;

    void dispatchHighestPriority(); // Smart matched dispatch
    void undoLastDispatch();        // Stack undo operation
};

#endif