#include <iostream>
#include "LinkedList.h"
#include "Menu.h"

int main() {
    LinkedList<std::string> journal;

    int choice;
    do {
        Menu::displayMenu();
        choice = Menu::handleChoice(journal);
    } while (choice != 6);
    
    std::cout << " Работу выполнил студент: Саблин Дмитрий Владимирович, ДБИ-101кр " << std::endl;
    
    return 0;
}
