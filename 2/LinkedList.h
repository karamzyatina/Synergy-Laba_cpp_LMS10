#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(const T& newData) : data(newData), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}
    ~LinkedList();

    void insert(const T& data);
    void remove(const T& data);
    bool search(const T& data) const;
    void edit(const T& oldData, const T& newData);

    void display() const;
    int getSize() const { return size; }
};

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void LinkedList<T>::insert(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template <typename T>
void LinkedList<T>::remove(const T& data) {
    if (head == nullptr) {
        throw std::out_of_range("Список пуст");
    }

    Node<T>* current = head;
    Node<T>* prev = nullptr;

    while (current != nullptr && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        throw std::invalid_argument("Элемент не найден");
    }

    if (prev == nullptr) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
    size--;
}

template <typename T>
bool LinkedList<T>::search(const T& data) const {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
void LinkedList<T>::edit(const T& oldData, const T& newData) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == oldData) {
            current->data = newData;
            return;
        }
        current = current->next;
    }
    throw std::invalid_argument("Элемент не найден");
}

template <typename T>
void LinkedList<T>::display() const {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif
