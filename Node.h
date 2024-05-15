#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
public:
    std::string department;
    std::string patientName;
    std::string arrivalDate;
    std::string dischargeDate;
    std::string diagnosis;
    Node* next;

    Node(std::string department, std::string patientName, std::string arrivalDate, std::string dischargeDate, std::string diagnosis);
};

#endif
