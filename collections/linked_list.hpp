//
// Created by jugos000 on 10/8/2020.
//

#ifndef TESTGROUND_LINKED_LIST_HPP
#define TESTGROUND_LINKED_LIST_HPP

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

template<class T>
struct ListNode {
    T item;
    ListNode *next;

    bool flag;

    ListNode(T item) : item(item), next(nullptr), flag(false) {}
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

    /// This method is the fastest one because no branch divergence exists
    ListNode<T> *GetMiddleElement() const;

    ListNode<T> *GetMiddleElement_WithIf() const;

    void SetHead(ListNode<T> *head);

    bool CheckIfCycleExists_WithSet() const;

    bool CheckIfCycleExists_WithVisited() const;

    bool CheckIfCycleExists_Floyd() const;

    void ReverseList_SwapPointers();

    void ReverseList_Iterative();

    ListNode<T>* ReverseList_Recursively(ListNode<T>* head);

    ListNode<T>* GetNthElementFromEnd_Counter(int n);

    ListNode<T>* GetNthElementFromEnd_TwoPtrs(int n);

    int CalculateLoopLength();

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

    ListNode<int> *GetHead();
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
ListNode<T> *List<T>::GetMiddleElement_WithIf() const {
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

template<class T>
void List<T>::SetHead(ListNode<T> *head) {
    this->head = head;
}

template<class T>
bool List<T>::CheckIfCycleExists_WithSet() const {
    unordered_set<ListNode<T> *> set;
    ListNode<T> *current = head;

    while (current != nullptr) {
        if (set.find(current) != set.end())
            return true;

        set.insert(current);
        current = current->next;
    }

    return false;
}

template<class T>
bool List<T>::CheckIfCycleExists_WithVisited() const {
    ListNode<T> *current = head;

    while (current != nullptr) {
        if (current->flag)
            return true;

        current->flag = true;
        current = current->next;
    }

    return false;
}

template<class T>
bool List<T>::CheckIfCycleExists_Floyd() const {
    ListNode<T> *slow = head, *fast = head;

    while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

template<class T>
void List<T>::ReverseList_SwapPointers() {
    swap(head, tail);
}

template<class T>
void List<T>::ReverseList_Iterative() {
    ListNode<T> *previous = nullptr, *current = head, *next;

    while (current != nullptr) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous;
}

template<class T>
ListNode<T>* List<T>::ReverseList_Recursively(ListNode<T>* head) {
    if (head == nullptr)
        return nullptr;
    else if (head->next == nullptr)
    {
        this->head = head;
        return head;
    }

    ListNode<T>* next = ReverseList_Recursively(head->next);
    next->next = head;
    head->next = nullptr;

    return head;
}

template<class T>
ListNode<int> *List<T>::GetHead() {
    return head;
}

template<class T>
ListNode<T> *List<T>::GetNthElementFromEnd_Counter(int n) {
    ListNode<T>* current = head;
    int cnt = 0;

    while (current != nullptr)
    {
        cnt++;
        current = current->next;
    }

    if (cnt < n)
        throw runtime_error("List has less elements than provided argument.");

    current = head;
    cnt = cnt - n;
    while (cnt > 0)
    {
        cnt--;
        current = current->next;
    }

    return current;
}

template<class T>
ListNode<T> *List<T>::GetNthElementFromEnd_TwoPtrs(int n) {
    ListNode<T> *ptr1 = head, *ptr2 = head;
    int cnt = 0;

    while (cnt++ < n)
    {
        if (ptr2 == nullptr)
            throw runtime_error("List has less elements than provided argument.");

        ptr2 = ptr2->next;
    }

    while (ptr2 != nullptr)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1;
}

template<class T>
int List<T>::CalculateLoopLength() {
    ListNode<T> *slow = head, *fast = head;

    while (slow != nullptr && fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow != fast)
        return 0;

    int cnt = 0;

    do
    {
        slow = slow->next;
        cnt++;
    } while (slow != fast);

    return cnt;
}

#endif //TESTGROUND_LINKED_LIST_HPP
