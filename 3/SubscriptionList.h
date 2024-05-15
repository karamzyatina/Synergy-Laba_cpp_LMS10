
#ifndef SUBSCRIPTIONLIST_H
#define SUBSCRIPTIONLIST_H

#include <iostream>
#include <vector>
#include <stdexcept>

class SubscriptionItem {
public:
    std::string fullName;
    std::string address;
    std::string publicationName;
    float subscriptionCost;
    std::string endDate;

    SubscriptionItem(const std::string& fullName, const std::string& address, 
                     const std::string& publicationName, float subscriptionCost, 
                     const std::string& endDate)
        : fullName(fullName), address(address), publicationName(publicationName), 
          subscriptionCost(subscriptionCost), endDate(endDate) {}
};

template<typename T>
class SubscriptionList {
private:
    std::vector<T> items;

public:
    void addItem(const T& item) {
        items.push_back(item);
    }

    void editItem(int index, const T& newItem) {
        if (index < 0 || index >= items.size())
            throw std::out_of_range("Index out of range");

        items[index] = newItem;
    }

    void deleteItem(int index) {
        if (index < 0 || index >= items.size())
            throw std::out_of_range("Index out of range");

        items.erase(items.begin() + index);
    }

    T getItem(int index) const {
        if (index < 0 || index >= items.size())
            throw std::out_of_range("Index out of range");

        return items[index];
    }

    int getSize() const {
        return items.size();
    }
};

#endif 
