#ifndef REPORT_H
#define REPORT_H

#include <vector>
#include "Hospital.h"
#include "Ambulance.h"
#include "Patient.h"

class Report
{
public:
    static void generateSystemSummary(const std::vector<Hospital>& hospitals,
                                      const std::vector<Ambulance>& ambulances,
                                      const std::vector<Patient>& patients);
};

#endif