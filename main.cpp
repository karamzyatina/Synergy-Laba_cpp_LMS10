#include <iostream>
#include "LinkedList.h"
#include "CustomException.h"

int main() {
    LinkedList hospital;

    try {
        hospital.insertNode("Emergency", "John Doe", "2024-05-15", "2024-05-20", "Flu");
        hospital.insertNode("Cardiology", "Jane Smith", "2024-05-10", "2024-05-18", "Heart Attack");

        hospital.displayList();

        hospital.editNode("John Doe", "John Smith", "2024-05-15", "2024-05-21", "Recovered");
        hospital.displayList();

        hospital.deleteNode("John Smith");
        hospital.displayList();
    } catch (CustomException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    std::cout << " Работу выполнил студент: Саблин Дмитрий Владимирович, ДБИ-101кр " << std::endl;
    
    return 0;
}
