#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insertNode(std::string department, std::string patientName, std::string arrivalDate, std::string dischargeDate, std::string diagnosis) {
    Node* newNode = new Node(department, patientName, arrivalDate, dischargeDate, diagnosis);
    newNode->next = head;
    head = newNode;
}

void LinkedList::editNode(std::string oldPatientName, std::string newPatientName, std::string newArrivalDate, std::string newDischargeDate, std::string newDiagnosis) {
    Node* current = head;
    while (current) {
        if (current->patientName == oldPatientName) {
            current->patientName = newPatientName;
            current->arrivalDate = newArrivalDate;
            current->dischargeDate = newDischargeDate;
            current->diagnosis = newDiagnosis;
            return;
        }
        current = current->next;
    }
    throw CustomException("Patient not found.");
}

void LinkedList::deleteNode(std::string patientName) {
    Node* current = head;
    Node* prev = nullptr;
    while (current) {
        if (current->patientName == patientName) {
            if (prev)
                prev->next = current->next;
            else
                head = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
    throw CustomException("Patient not found.");
}

Node* LinkedList::findNode(std::string patientName) {
    Node* current = head;
    while (current) {
        if (current->patientName == patientName) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void LinkedList::displayList() {
    Node* current = head;
    while (current) {
        std::cout << "Department: " << current->department << std::endl;
        std::cout << "Patient Name: " << current->patientName << std::endl;
        std::cout << "Arrival Date: " << current->arrivalDate << std::endl;
        std::cout << "Discharge Date: " << current->dischargeDate << std::endl;
        std::cout << "Diagnosis: " << current->diagnosis << std::endl << std::endl;
        current = current->next;
    }
}
