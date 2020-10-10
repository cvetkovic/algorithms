#include <chrono>
#include <iostream>

#include "collections/linked_list.hpp"

using namespace std;

int main() {
    List<int> list;

    ListNode<int>* t1 = new ListNode<int>(3);
    ListNode<int>* t2 = new ListNode<int>(6);
    ListNode<int>* t3 = new ListNode<int>(9);
    ListNode<int>* t4 = new ListNode<int>(15);
    ListNode<int>* t5 = new ListNode<int>(30);
    ListNode<int>* t6 = new ListNode<int>(10);

    List<int> l1, l2;
    l1.SetHead(t1);
    l2.SetHead(t6);

    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = nullptr;
    t6->next = t4;

    cout << "Intersection at node with value: " << List<int>::TwoListsIntersection(l1, l2)->item << endl;

    delete t1;
    delete t2;
    delete t3;
    delete t4;
    delete t5;
    delete t6;

    exit(0);
}
