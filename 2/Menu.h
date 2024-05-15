#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "LinkedList.h"

class Menu {
public:
    static void displayMenu();
    static int handleChoice(LinkedList<std::string>& journal);

};

#endif
