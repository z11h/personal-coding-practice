#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class LinkedList {
    struct Node {
        T data;
        Node* next;
        
        Node(T data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    unsigned int size;
    
    public:
    LinkedList();
    LinkedList(const LinkedList&);
    ~LinkedList();
    
    void append(const LinkedList&);
    void clear();
    T& front() const;
    void push_back(const T&);
    void push_front(const T&);
    unsigned int length() const;
    void pop_front();
    
    LinkedList& operator=(const LinkedList&);
    
    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
        if (list.size == 0) {
            os << "[empty]";
        } else {
            Node* current = list.head;
            if (current) {
                os << current->data;
                current = current->next;
            }
            while (current) {
                os << "-->" << current->data;
                current = current->next;
            }
        }
        return os;
    }
    
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : head(nullptr), tail(nullptr), size(0) {
    append(other);
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const LinkedList& rhs) {
    Node* current = rhs.head;
    while (current) {
        this->push_back(current->data);
        current = current->next;
    }
}

template <typename T>
void LinkedList<T>::clear() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
T& LinkedList<T>::front() const {
    if (size == 0) {
        throw std::out_of_range("empty list");
    }
    return head->data;
}

template <typename T>
void LinkedList<T>::push_back(const T& data) {
    Node* node = new Node(data);
    if (head) {
        tail->next = node;
    } else {
        head = node;
    }
    tail = node;
    size++;
}

template <typename T>
void LinkedList<T>::push_front(const T& data) {
    Node* node = new Node(data);
    if (head) {
        node->next = head;
    } else {
        tail = node;
    }
    head = node;
    size++;
}

template <typename T>
unsigned int LinkedList<T>::length() const {
    return size;
}

template <typename T>
void LinkedList<T>::pop_front() {
    if (size == 0) {
        throw std::out_of_range("empty list");
    }
    if (head == tail) {
        // 1 node
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        // > 1 node
        Node* next = head->next;
        delete head;
        head = next;
    }
    size--;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
    if (this != &rhs) {
        clear();
        append(rhs);
    }
    return *this;
}

#endif