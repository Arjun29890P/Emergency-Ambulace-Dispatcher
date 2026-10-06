#include <iostream>
#include <string>
#include <limits>
#include "../include/Dispatcher.h"
#include "../include/Utils.h"

using namespace std;

int main()
{
    Dispatcher dispatcher;
    int choice;

    do
    {
        Utils::printHeader("EMERGENCY AMBULANCE DISPATCHER");
        cout << "1. Register Hospital\n";
        cout << "2. Register Ambulance (BLS/ICU)\n";
        cout << "3. Register Patient\n";
        cout << "4. Add Emergency Request (Priority Queue)\n";
        cout << "5. Add Road Edge (City Graph)\n";
        cout << "6. Display All Records & Graph\n";
        cout << "7. Dispatch Highest Priority Emergency (Smart Match)\n";
        cout << "8. Undo Last Dispatch (Stack)\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        
        cin >> choice;

        // Prevent infinite loops if user enters letters or invalid input
        if (cin.fail())
        {
            cout << "\n[ERROR] Invalid input! Please enter a valid number.\n";
            cin.clear(); // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            Hospital h;
            h.inputHospital();
            dispatcher.registerHospital(h);
            cout << "\nHospital registered successfully!\n";
            break;
        }
        case 2:
        {
            Ambulance a;
            a.inputAmbulance();
            dispatcher.registerAmbulance(a);
            cout << "\nAmbulance registered successfully!\n";
            break;
        }
        case 3:
        {
            Patient p;
            p.inputPatient();
            dispatcher.registerPatient(p);
            cout << "\nPatient registered successfully!\n";
            break;
        }
        case 4:
        {
            int id, sev;
            string name, loc, time;
            cout << "\n--- Enter Emergency Request ---\n";
            cout << "Enter Request ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Patient Name: ";
            getline(cin, name);
            cout << "Enter Location: ";
            getline(cin, loc);
            cout << "Enter Severity (1-5, higher = critical): ";
            cin >> sev;
            cin.ignore();
            cout << "Enter Timestamp: ";
            getline(cin, time);

            EmergencyRequest req(id, name, loc, sev, time);
            dispatcher.addEmergencyRequest(req);
            cout << "\nEmergency request added to priority queue!\n";
            break;
        }
        case 5:
        {
            string u, v;
            int weight;
            cout << "\n--- Add City Road Edge ---\n";
            cout << "Enter Source Location: ";
            cin >> u;
            cout << "Enter Destination Location: ";
            cin >> v;
            cout << "Enter Distance (km): ";
            cin >> weight;
            cin.ignore(); // <--- ADD THIS LINE TO CLEAR THE BUFFER
            
            dispatcher.addRoadEdge(u, v, weight);
            cout << "\nRoad edge added to graph network!\n";
            break;
        }
        case 6:
        {
            dispatcher.displayAllRecords();
            dispatcher.displayGraph();
            break;
        }
        case 7:
        {
            dispatcher.dispatchHighestPriority();
            break;
        }
        case 8:
        {
            dispatcher.undoLastDispatch();
            break;
        }
        case 9:
            cout << "\nExiting Emergency Dispatcher System. Stay safe!\n";
            break;
        default:
            cout << "\nInvalid choice! Choose between 1-9.\n";
        }

    } while (choice != 9);

    return 0;
}