
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "SubscriptionList.h"

class Menu {
public:

    static void displayMenu() {
        std::cout << "Subscription Management System Menu\n";
        std::cout << "1. Добавить подписку\n";
        std::cout << "2. Редактировать подписку\n";
        std::cout << "3. Удалить подписку\n";
        std::cout << "4. Найти подписку\n";
        std::cout << "5. Отобразить подписки\n";
        std::cout << "6. Выйти\n";
    }

    static int getUserChoice() {
        int choice;
        std::cout << "Введите пункт меню: ";
        std::cin >> choice;
        return choice;
    }
};

#endif
