#include "../include/Dispatcher.h"
#include <iostream>

using namespace std;

void Dispatcher::registerHospital(const Hospital& h) { hospitals.push_back(h); }
void Dispatcher::registerAmbulance(const Ambulance& a) { ambulances.push_back(a); }
void Dispatcher::registerPatient(const Patient& p) { patients.push_back(p); }
void Dispatcher::addEmergencyRequest(const EmergencyRequest& req) { emergencyQueue.push(req); }
void Dispatcher::addRoadEdge(string u, string v, int weight) { cityGraph.addEdge(u, v, weight); }

void Dispatcher::displayAllRecords() const
{
    cout << "\n========== REGISTERED HOSPITALS ==========\n";
    if (hospitals.empty()) cout << "No hospitals registered.\n";
    for (size_t i = 0; i < hospitals.size(); ++i) hospitals[i].displayHospital();

    cout << "\n========== REGISTERED AMBULANCES ==========\n";
    if (ambulances.empty()) cout << "No ambulances registered.\n";
    for (size_t i = 0; i < ambulances.size(); ++i) ambulances[i].displayAmbulance();

    cout << "\n========== REGISTERED PATIENTS ==========\n";
    if (patients.empty()) cout << "No patients registered.\n";
    for (size_t i = 0; i < patients.size(); ++i) patients[i].displayPatient();
}

void Dispatcher::displayGraph() const { cityGraph.displayGraph(); }

void Dispatcher::dispatchHighestPriority()
{
    cout << "\n========== EMERGENCY DISPATCH SYSTEM ==========\n";
    if (emergencyQueue.empty())
    {
        cout << "No pending emergency requests in the queue.\n";
        return;
    }

    EmergencyRequest topReq = emergencyQueue.top();
    emergencyQueue.pop();

    cout << "CRITICAL EMERGENCY FETCHED:\n";
    topReq.displayRequest();

    // Capability Matching Rule: Severity >= 4 requires ICU, else BLS
    string requiredType = (topReq.getSeverity() >= 4) ? "ICU" : "BLS";

    Ambulance* selectedAmbulance = nullptr;
    for (size_t i = 0; i < ambulances.size(); ++i)
    {
        if (ambulances[i].isAvailable() && ambulances[i].getAmbulanceType() == requiredType)
        {
            selectedAmbulance = &ambulances[i];
            break;
        }
    }

    // Fallback: If preferred type isn't available, pick any available ambulance
    if (selectedAmbulance == nullptr)
    {
        for (size_t i = 0; i < ambulances.size(); ++i)
        {
            if (ambulances[i].isAvailable())
            {
                selectedAmbulance = &ambulances[i];
                break;
            }
        }
    }

    if (selectedAmbulance == nullptr)
    {
        cout << "ALERT: No available ambulances at the moment! Putting request back into queue.\n";
        emergencyQueue.push(topReq);
        return;
    }

    // Push state to Stack history before marking busy
    dispatchHistory.push({topReq, *selectedAmbulance});

    selectedAmbulance->setAvailability(false);
    cout << "\n[DISPATCH SUCCESSFUL - Matched Type: " << requiredType << "]\n";
    cout << "Assigned Ambulance ID: " << selectedAmbulance->getAmbulanceID() << endl;
    cout << "Ambulance Type: " << selectedAmbulance->getAmbulanceType() << endl;
    cout << "Ambulance status successfully updated to: BUSY\n";
}

void Dispatcher::undoLastDispatch()
{
    cout << "\n========== UNDO LAST DISPATCH ==========\n";
    if (dispatchHistory.empty())
    {
        cout << "No dispatch history found to undo.\n";
        return;
    }

    auto lastDispatch = dispatchHistory.top();
    dispatchHistory.pop();

    for (size_t i = 0; i < ambulances.size(); ++i)
    {
        if (ambulances[i].getAmbulanceID() == lastDispatch.second.getAmbulanceID())
        {
            ambulances[i].setAvailability(true);
            break;
        }
    }

    cout << "[SUCCESS] Last dispatch undone. Ambulance ID " 
         << lastDispatch.second.getAmbulanceID() << " is now AVAILABLE again.\n";
}