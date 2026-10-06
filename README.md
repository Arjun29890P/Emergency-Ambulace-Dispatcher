# Emergency Ambulance Dispatcher (C++ DSA Project)

A robust, modular C++ console application designed to simulate an intelligent emergency dispatch center. The project implements core **Data Structures and Algorithms (DSA)** principles—including graph networks, priority queues, and stacks—to manage hospitals, triage medical emergencies, map city routes, and handle ambulance dispatches efficiently.

---

## 🚀 Key Features

* **Severity-Based Triage (Priority Queue)**: Emergency requests are automatically prioritized using a max-priority queue based on patient severity, ensuring critical cases are handled first.
* **Smart Capability Matching**: Automatically matches patient severity levels to appropriate ambulance types (**BLS** for standard care vs. **ICU** for critical/high-severity trauma or cardiac cases).
* **City Road Network Mapping (Graph)**: Utilizes an adjacency list graph representation with weighted edges (distances in km) to model city roads and support shortest-path routing (Dijkstra's algorithm).
* **Dispatch History & Undo (Stack)**: Tracks completed dispatches in a Last-In, First-Out (LIFO) stack, allowing operators to audit or instantly undo the last dispatch operation.
* **Robust Input Validation**: Built with stream error handling (`std::cin.fail()`) and buffer clearing to prevent infinite loop errors during terminal interaction.

---

## 📂 Project Structure

```text
├── include/
│   ├── Ambulance.h
│   ├── Dispatcher.h
│   ├── EmergencyRequest.h
│   ├── Graph.h
│   ├── Hospital.h
│   ├── Patient.h
│   ├── Report.h
│   └── Utils.h
├── src/
│   ├── Ambulance.cpp
│   ├── Dispatcher.cpp
│   ├── EmergencyRequest.cpp
│   ├── Graph.cpp
│   ├── Hospital.cpp
│   ├── Patient.cpp
│   ├── Report.cpp
│   ├── Utils.cpp
│   └── main.cpp
└── README.md