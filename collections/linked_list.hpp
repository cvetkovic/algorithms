//
// Created by jugos000 on 10/8/2020.
//

#ifndef TESTGROUND_LINKED_LIST_HPP
#define TESTGROUND_LINKED_LIST_HPP

#include <iostream>
#include <string>

using namespace std;

template<class T>
struct ListNode {
    T item;
    ListNode *next;

    ListNode(T item) : item(item), next(nullptr) {}
};

template<class T>
class List {
private:
    ListNode<T> *head = 0;
    ListNode<T> *tail = 0;

public:
    ~List();

    void AddToHead(T item);

    void AddToTail(T item);

    ListNode<T> *GetMiddleElement() const;
    ListNode<T> *GetMiddleElement2() const;

    friend ostream &operator<<(ostream &ostream, const List<T> &list) {
        if (list.head != nullptr) {
            ListNode<T> *current = list.head;

            while (current != nullptr) {
                ostream << current->item;
                current = current->next;
            }
        }

        return ostream;
    }
};

template<class T>
List<T>::~List() {
    ListNode<T> *current = head;

    while (current != nullptr) {
        ListNode<T> *next = current->next;
        delete current;
        current = next;
    }
}

template<class T>
void List<T>::AddToHead(T item) {
    ListNode<T> *newNode = new ListNode<T>(item);

    if (head == nullptr)
        head = tail = newNode;
    else {
        newNode->next = head;
        head = newNode;
    }
}

template<class T>
void List<T>::AddToTail(T item) {
    ListNode<T> *newNode = new ListNode<T>(item);

    if (head == nullptr)
        head = tail = newNode;
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

template<class T>
ListNode<T> *List<T>::GetMiddleElement() const {
    ListNode<T> *slow = head, *fast = head;

    if (slow == nullptr)
        throw runtime_error("List is empty!");

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

template<class T>
ListNode<T> *List<T>::GetMiddleElement2() const {
    ListNode<T> *current = head, *mid = head;

    if (current == nullptr)
        throw runtime_error("List is empty!");

    bool toggle = false;

    while (current != nullptr) {
        if (toggle)
            mid = mid->next;

        toggle = !toggle;
        current = current->next;
    }

    return mid;
}

#endif //TESTGROUND_LINKED_LIST_HPP
