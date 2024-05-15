#include "Node.h"

Node::Node(std::string department, std::string patientName, std::string arrivalDate, std::string dischargeDate, std::string diagnosis)
    : department(department), patientName(patientName), arrivalDate(arrivalDate), dischargeDate(dischargeDate), diagnosis(diagnosis), next(nullptr) {}
