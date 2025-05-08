#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "passenger.h"

class Node {
private:
    int data;
    Node* next;
public:
    Node() {
        data = 0;
        next = nullptr;
    }

    Node(int data) {
        this->data = data;
        next = nullptr;
    }

    friend class LinkedList;
    friend class Random;

};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    Node* get_head() {
        return head;
    }

    void insertAtHead(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        newNode->next = this->head;
        this->head = newNode;
    }

    void insertAtTail(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void clearList() {
        Node* temp = head;
        head = nullptr;

        while (temp != nullptr) {
            Node* temp2 = temp->next;
            delete temp;
            temp = temp2;
        }
    }

    bool empty() {
        if (head == nullptr) {
            std::cout << "Empty";
            return true;
        }
        return false;
    }

    void print() {

        if (head == nullptr) {
            std::cout << "Empty";
            return;
        }

        Node* temp = head;
        while (temp != nullptr ) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }

        std::cout << "NULL";
    }

    friend class Random;

};
#endif // LINKEDLIST_H
