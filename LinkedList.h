#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "CustomException.h"
#include <iostream>

class LinkedList {
private:
    Node* head;
public:
    LinkedList();
    ~LinkedList();

    void insertNode(std::string department, std::string patientName, std::string arrivalDate, std::string dischargeDate, std::string diagnosis);
    void editNode(std::string oldPatientName, std::string newPatientName, std::string newArrivalDate, std::string newDischargeDate, std::string newDiagnosis);
    void deleteNode(std::string patientName);
    Node* findNode(std::string patientName);
    void displayList();
};

#endif
