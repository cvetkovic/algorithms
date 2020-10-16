//
// Created by jugos000 on 10/8/2020.
//

#ifndef TESTGROUND_LINKED_LIST_HPP
#define TESTGROUND_LINKED_LIST_HPP

#include <iostream>
#include <stack>
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
    List() {}

    List(const List &list);

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

    ListNode<T> *ReverseList_Recursively(ListNode<T> *head);

    ListNode<T> *GetNthElementFromEnd_Counter(int n);

    ListNode<T> *GetNthElementFromEnd_TwoPtrs(int n);

    int CalculateLoopLength() const;

    bool IsPalindrome_Stack() const;

    bool IsPalindrome_MiddleTraversal();

    void RemoveDuplicatesFromSorted();

    void RemoveDuplicatedFromUnsorted_On2();

    void RemoveDuplicatedFromUnsorted_Set();

    void EvenOddSegregation();

    void ReverseGroups(int k);

    static ListNode<T> *TwoListsIntersection(const List<T> &list1, const List<T> &list2);

    static List<T> *MergeTwoListsInReverseOrder(List<T> &list1, List<T> &list2);

    static List<T> *AddTwoNumbers(const List<T> &num1, const List<T> &num2);

    void DeleteNodesWithGreaterValueOnRight();

    void Sort012s();

    friend bool operator==(const List &list1, const List &list2) {
        ListNode<T> *p1 = list1.head, *p2 = list2.head;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->item != p2->item)
                return false;

            p1 = p1->next;
            p2 = p2->next;
        }

        if (p1 != nullptr || p2 != nullptr)
            return false;
        else
            return true;
    }

    friend ostream &operator<<(ostream &ostream, const List<T> &list) {
        if (list.head != nullptr) {
            ListNode<T> *current = list.head;

            while (current != nullptr) {
                ostream << current->item << " ";
                current = current->next;
            }
        }

        return ostream;
    }

    ListNode<int> *GetHead();
};

template<class T>
List<T>::List(const List &list) {
    ListNode<T> *curr = list.head;

    ListNode<T> *newHead = nullptr;
    ListNode<T> *newTail = nullptr;

    while (curr != nullptr) {
        ListNode<T> *elem = new ListNode<T>(curr->item);

        if (newHead == nullptr)
            newHead = newTail = elem;
        else {
            newTail->next = elem;
            newTail = elem;
        }

        curr = curr->next;
    }

    head = newHead;
}

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
ListNode<T> *List<T>::ReverseList_Recursively(ListNode<T> *head) {
    if (head == nullptr)
        return nullptr;
    else if (head->next == nullptr) {
        this->head = head;
        return head;
    }

    ListNode<T> *next = ReverseList_Recursively(head->next);
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
    ListNode<T> *current = head;
    int cnt = 0;

    while (current != nullptr) {
        cnt++;
        current = current->next;
    }

    if (cnt < n)
        throw runtime_error("List has less elements than provided argument.");

    current = head;
    cnt = cnt - n;
    while (cnt > 0) {
        cnt--;
        current = current->next;
    }

    return current;
}

template<class T>
ListNode<T> *List<T>::GetNthElementFromEnd_TwoPtrs(int n) {
    ListNode<T> *ptr1 = head, *ptr2 = head;
    int cnt = 0;

    while (cnt++ < n) {
        if (ptr2 == nullptr)
            throw runtime_error("List has less elements than provided argument.");

        ptr2 = ptr2->next;
    }

    while (ptr2 != nullptr) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1;
}

template<class T>
int List<T>::CalculateLoopLength() const {
    ListNode<T> *slow = head, *fast = head;

    while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow != fast)
        return 0;

    int cnt = 0;

    do {
        slow = slow->next;
        cnt++;
    } while (slow != fast);

    return cnt;
}

template<class T>
bool List<T>::IsPalindrome_Stack() const {
    stack<T> elementStack;
    ListNode<T> *current = head;

    while (current != nullptr) {
        elementStack.push(current->item);
        current = current->next;
    }

    current = head;
    while (current != nullptr) {
        if (elementStack.top() != current->item)
            return false;

        elementStack.pop();
        current = current->next;
    }

    return true;
}

template<class T>
bool List<T>::IsPalindrome_MiddleTraversal() {
    // find mid element
    ListNode<T> *slow = head, *fast = head, *slowPrev;
    while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
        slowPrev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // if number of elements is odd then don't compare middle element
    ListNode<T> *middleOdd = nullptr;
    if (fast && fast->next == nullptr) {
        middleOdd = slow;
        slow = slow->next;
    }

    // reverse right half of the linked list
    ListNode<T> *prev = nullptr, *current = slow, *next;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    slowPrev->next = nullptr;

    // compare two halves of list element by element
    ListNode<T> *p1 = head, *p2 = prev;
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->item != p2->item)
            break;

        p1 = p1->next;
        p2 = p2->next;
    }

    // reconstruct the list
    current = prev;
    prev = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    if (fast && fast->next == nullptr) {
        middleOdd->next = prev;
        //slow->next = list.GetHead();
    } else {
        slowPrev->next = prev;
    }

    if (p1 == nullptr && p2 == nullptr)
        return true;
    else
        return false;
}

template<class T>
void List<T>::RemoveDuplicatesFromSorted() {
    ListNode<T> *current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->item == current->next->item) {
            ListNode<T> *next = current->next->next;
            delete current->next;
            current->next = next;
        } else
            current = current->next;
    }
}

template<class T>
void List<T>::RemoveDuplicatedFromUnsorted_On2() {
    for (ListNode<T> *p1 = head; p1 != nullptr && p1->next != nullptr; p1 = p1->next) {
        ListNode<T> *prev = p1;

        for (ListNode<T> *p2 = p1->next; p2 != nullptr;) {
            if (p1->item == p2->item) {
                ListNode<T> *next = p2->next;
                delete p2;
                prev->next = next;
                p2 = next;
            } else {
                prev = p2;
                p2 = p2->next;
            }
        }
    }
}

template<class T>
void List<T>::RemoveDuplicatedFromUnsorted_Set() {
    ListNode<T> *prev = nullptr, *current = head;
    unordered_set<int> elements;

    while (current != nullptr) {
        if (elements.find(current->item) == elements.end()) {
            elements.insert(current->item);
            prev = current;
            current = current->next;
        } else {
            ListNode<T> *next = current->next;
            delete current;
            prev->next = next;
            current = next;
        }
    }
}

template<class T>
void List<T>::EvenOddSegregation() {
    ListNode<T> *evenHead = nullptr, *evenTail = nullptr;
    ListNode<T> *oddHead = nullptr, *oddTail = nullptr;
    ListNode<T> *current = head;

    while (current != nullptr) {
        if (current->item % 2 == 0) {
            if (evenHead == nullptr)
                evenHead = evenTail = current;
            else {
                evenTail->next = current;
                evenTail = current;
            }
        } else {
            if (oddHead == nullptr)
                oddHead = oddTail = current;
            else {
                oddTail->next = current;
                oddTail = current;
            }
        }

        current = current->next;
    }

    if (evenTail != nullptr)
        evenTail->next = nullptr;
    if (oddTail != nullptr)
        oddTail->next == nullptr;

    if (evenHead == nullptr)
        head = oddHead;
    else if (oddHead == nullptr)
        head = evenHead;
    else {
        evenTail->next = oddHead;
        head = evenHead;
    }
}

template<class T>
ListNode<T> *List<T>::TwoListsIntersection(const List<T> &list1, const List<T> &list2) {
    int cnt1, cnt2;
    ListNode<T> *current1 = list1.head, *current2 = list2.head;

    while (current1 != nullptr) {
        cnt1++;
        current1 = current1->next;
    }
    while (current2 != nullptr) {
        cnt2++;
        current2 = current2->next;
    }

    current1 = list1.head;
    current2 = list2.head;
    if (cnt1 > cnt2)
        for (int i = 1; i <= abs(cnt2 - cnt1); i++)
            current1 = current1->next;
    else
        for (int i = 1; i <= abs(cnt2 - cnt1); i++)
            current2 = current2->next;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1 == current2)
            return current1;

        current1 = current1->next;
        current2 = current2->next;
    }

    return nullptr;
}

template<class T>
List<T> *List<T>::MergeTwoListsInReverseOrder(List<T> &list1, List<T> &list2) {
    List<T> *mergedList = new List<T>();

    ListNode<T> *p1 = list1.head;
    ListNode<T> *p2 = list2.head;
    ListNode<T> *current = nullptr;

    while (p1 != nullptr && p2 != nullptr) {
        ListNode<T> *next;

        if (p1->item < p2->item) {
            next = p1->next;
            p1->next = current;
            current = p1;
            p1 = next;
        } else if (p1->item > p2->item) {
            next = p2->next;
            p2->next = current;
            current = p2;
            p2 = next;
        } else {
            next = p1->next;
            p1->next = p2;
            p1 = next;

            next = p2->next;
            p2->next = current;
            current = p2;

            p2 = next;
        }
    }

    while (p1 != nullptr) {
        ListNode<T> *next = p1->next;
        p1->next = current;
        current = p1;
        p1 = next;
    }

    while (p2 != nullptr) {
        ListNode<T> *next = p2->next;
        p2->next = current;
        current = p2;
        p2 = next;
    }

    mergedList->head = current;

    return mergedList;
}

template<class T>
void List<T>::ReverseGroups(int k) {
    ListNode<T> *prev = nullptr, *curr = head, *next = nullptr;
    int cnt = 0;

    ListNode<T> *oldHead = head;
    bool first = true;
    while (curr != nullptr) {
        ListNode<T> *rem = next;
        prev = nullptr, next = nullptr;

        while (curr != nullptr && cnt < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

            cnt++;
        }

        cnt = 0;
        if (!first) {
            oldHead->next = prev;
            oldHead = rem;
        } else
            head = prev;
        first = false;
    }
}

template<class T>
void List<T>::DeleteNodesWithGreaterValueOnRight() {
    ListNode<T> *current = head;
    ListNode<T> *prev = nullptr;

    while (current != nullptr && current->next != nullptr) {
        if (current->item < current->next->item) {
            if (prev == nullptr) {
                head = current->next;

                ListNode<T> *next = current->next;
                delete current;
                current = next;
            } else {
                prev->next = current->next;

                ListNode<T> *next = current->next;
                delete current;
                current = next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

template<class T>
List<T> *List<T>::AddTwoNumbers(const List<T> &num1, const List<T> &num2) {
    ListNode<T> *p1 = num1.head;
    ListNode<T> *p2 = num2.head;

    List<T> *result = new List<T>();
    bool carry = false;

    while (p1 != nullptr && p2 != nullptr) {
        int sum = p1->item + p2->item + (carry ? 1 : 0);
        carry = (sum >= 10);

        result->AddToTail(sum % 10);

        p1 = p1->next;
        p2 = p2->next;
    }

    while (p1 != nullptr) {
        int sum = p1->item + (carry ? 1 : 0);
        carry = (sum >= 10);

        result->AddToTail(sum % 10);

        p1 = p1->next;
    }

    while (p2 != nullptr) {
        int sum = p2->item + (carry ? 1 : 0);
        carry = (sum >= 10);

        result->AddToTail(sum % 10);

        p2 = p2->next;
    }

    return result;
}

template<class T>
void List<T>::Sort012s() {
    ListNode<T> *current = head;

    ListNode<T> *zeros = nullptr, *zerosTail = nullptr;
    ListNode<T> *ones = nullptr, *onesTail = nullptr;
    ListNode<T> *twos = nullptr, *twosTail = nullptr;

    while (current != nullptr) {
        T item = current->item;

        ListNode<T> *next = current->next;

        if (item % 3 == 0) {
            if (zeros == nullptr) {
                zeros = zerosTail = current;
            } else {
                zerosTail->next = current;
                zerosTail = current;
            }
        } else if (item % 3 == 1) {
            if (ones == nullptr) {
                ones = onesTail = current;
            } else {
                onesTail->next = current;
                onesTail = current;
            }
        } else {
            if (twos == nullptr) {
                twos = twosTail = current;
            } else {
                twosTail->next = current;
                twosTail = current;
            }
        }

        current->next = nullptr;
        current = next;
    }

    if (zeros != nullptr) {
        head = zeros;
        if (ones == nullptr) {
            zerosTail->next = twos;
        } else {
            zerosTail->next = ones;
            onesTail->next = twos;
        }
    } else if (ones != nullptr) {
        head = ones;
        if (twos != nullptr)
            onesTail->next = twos;
    }
    else
        head = twos;
}

#endif //TESTGROUND_LINKED_LIST_HPP
