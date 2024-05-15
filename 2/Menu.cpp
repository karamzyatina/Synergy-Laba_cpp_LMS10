#include "Menu.h"

void Menu::displayMenu() {
    std::cout << "1. Вставить запись\n"
              << "2. Удалить запись\n"
              << "3. Найти запись\n"
              << "4. Редактировать запись\n"
              << "5. Отобразить журнал\n"
              << "6. Выйти\n"
              << "Введите свой выбор: ";
}

int Menu::handleChoice(LinkedList<std::string>& journal) {
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1: {
            std::string entry;
            std::cout << "Введите запись: ";
            std::cin.ignore();
            std::getline(std::cin, entry);
            journal.insert(entry);
            break;
        }
        case 2: {
            std::string entry;
            std::cout << "Введите запись, которую нужно удалить: ";
            std::cin.ignore();
            std::getline(std::cin, entry);
            try {
                journal.remove(entry);
            } catch (const std::exception& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
            }
            break;
        }
        case 3: {
            std::string entry;
            std::cout << "Введите запись для поиска: ";
            std::cin.ignore();
            std::getline(std::cin, entry);
            bool found = journal.search(entry);
            if (found) {
                std::cout << "Запись найдена в журнале.\n";
            } else {
                std::cout << "Запись в журнале не найдена.\n";
            }
            break;
        }
        case 4: {
            std::string oldEntry, newEntry;
            std::cout << "Введите запись для редактирования: ";
            std::cin.ignore();
            std::getline(std::cin, oldEntry);
            std::cout << "Введите новую запись: ";
            std::getline(std::cin, newEntry);
            try {
                journal.edit(oldEntry, newEntry);
            } catch (const std::exception& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
            }
            break;
        }
        case 5: {
            std::cout << "Записи в журнале:\n";
            journal.display();
            break;
        }
        case 6:
            std::cout << "Выход...\n";
            break;
        default:
            std::cerr << "Неверный выбор. Пожалуйста, введите число от 1 до 6.\n";
    }
    return choice;
}
