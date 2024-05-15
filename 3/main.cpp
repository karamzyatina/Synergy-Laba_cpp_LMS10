

#include <iostream>
#include <stdexcept>
#include "SubscriptionList.h"
#include "Menu.h"

void displaySubscriptions(const SubscriptionList<SubscriptionItem>& subscriptionList) {
    std::cout << "Подписки:\n";
    for (int i = 0; i < subscriptionList.getSize(); ++i) {
        SubscriptionItem item = subscriptionList.getItem(i);
        std::cout << "Номер: " << i << ", Полное имя: " << item.fullName
                  << ", Адрес: " << item.address << ", Публикация: " << item.publicationName
                  << ", Стоимость: " << item.subscriptionCost << ", Дата окончания: " << item.endDate << "\n";
    }
}

int main() {
    SubscriptionList<SubscriptionItem> subscriptionList;
    
    bool exit = false;
    while (!exit) {
        Menu::displayMenu();
        int choice = Menu::getUserChoice();

        switch (choice) {
            case 1: {
                std::string fullName, address, publicationName, endDate;
                float subscriptionCost;

                std::cout << "Введите полное ФИО: ";
                std::cin >> fullName;
                std::cout << "Введите адрес: ";
                std::cin >> address;
                std::cout << "Введите имя публикации: ";
                std::cin >> publicationName;
                std::cout << "Введите стоимость подписки: ";
                std::cin >> subscriptionCost;
                std::cout << "Введите окончание даты: ";
                std::cin >> endDate;

                SubscriptionItem newItem(fullName, address, publicationName, 
                                          subscriptionCost, endDate);
                subscriptionList.addItem(newItem);
                std::cout << "Подписка успешно добавлена.\n";
                break;
            }
            case 2: {
                int index;
                std::cout << "Введите номер подписки для редактирования: ";
                std::cin >> index;

                try {
                    SubscriptionItem currentItem = subscriptionList.getItem(index);

                    std::string fullName, address, publicationName, endDate;
                    float subscriptionCost;

                    std::cout << "Введите новое ФИО: ";
                    std::cin >> fullName;
                    std::cout << "Введите новый адрес: ";
                    std::cin >> address;
                    std::cout << "Введите новое название публикации: ";
                    std::cin >> publicationName;
                    std::cout << "Введите новую стоимость подписки: ";
                    std::cin >> subscriptionCost;
                    std::cout << "Введите новую дату окончания: ";
                    std::cin >> endDate;

                    SubscriptionItem newItem(fullName, address, publicationName, 
                                              subscriptionCost, endDate);
                    subscriptionList.editItem(index, newItem);
                    std::cout << "Подписка успешно отредактирована.\n";
                } catch (const std::out_of_range& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }
            case 3: {
                int index;
                std::cout << "Введите индекс подписки для удаления: ";
                std::cin >> index;

                try {
                    subscriptionList.deleteItem(index);
                    std::cout << "Подписка успешно удалена.\n";
                } catch (const std::out_of_range& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                std::string searchName;
                std::cout << "Введите имя для поиска: ";
                std::cin >> searchName;

                // Поиск подписки по имени
                bool found = false;
                for (int i = 0; i < subscriptionList.getSize(); ++i) {
                    SubscriptionItem item = subscriptionList.getItem(i);
                    if (item.fullName == searchName) {
                        std::cout << "Подписка найдена по индексу " << i << ":\n";
                        std::cout << "ФИО: " << item.fullName << ", Адрес: " << item.address
                                  << ", Публикация: " << item.publicationName << ", Стоимость: " << item.subscriptionCost
                                  << ", Конец подписки: " << item.endDate << "\n";
                        found = true;
                    }
                }
                if (!found) {
                    std::cout << "Подписка не найдена.\n";
                }
                break;
            }
            case 5: {
                displaySubscriptions(subscriptionList);
                break;
            }
            case 6:
                exit = true;
                break;
            default:
                std::cout << "Неверный вариант. Пожалуйста, введите число от 1 до 6.\n";
                break;
        }
    }
    
    std::cout << " Работу выполнил студент: Саблин Дмитрий Владимирович, ДБИ-101кр " << std::endl;
    
    return 0;
}
