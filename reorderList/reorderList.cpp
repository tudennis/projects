/*
Given a singly linked list L: L0->L1->...->Ln-1->Ln,
reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/


#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode * next;
    ListNode(int v): val(v), next(0) {}
};

void printList(ListNode * head)
{
    while(head != 0)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode * findMid(ListNode * head)
{
    ListNode *p1(head), *p2(head), *p(0);

    while (p1 != 0 && p2 != 0 && p2->next != 0)
    {
        p = p1;
        p1 = p1->next;
        p2 = p2->next->next;
    }

    if (p != 0)
        p->next = 0; // Break the linked list into two parts

    return p1;
}

ListNode* reverse(ListNode* head)
{
    ListNode * h(0), * p;

    while (head != 0)
    {
        p = head;
        head = head->next;
        p->next = h;
        h = p;
    }

    return h;
}

ListNode * merge(ListNode * h1, ListNode * h2)
{
    ListNode * p1(h1), * p2(h2), *p1nxt, *p2nxt;

    while(p1 != 0 && p2 != 0)
    {
        p1nxt = p1->next;
        p2nxt = p2->next;

        p1->next = p2;
        p2->next = p1nxt;

        if (p1nxt == 0)
        {
            p2->next = p2nxt;
            break;
        }

        p1 = p1nxt;
        p2 = p2nxt;
    }

    return h1;
}

void reorderList(ListNode* head)
{
    ListNode* mid = findMid(head);

    printList(head);

    printList(mid);

    mid = reverse(mid);

    printList(mid);

    head = merge(head, mid);
}

int main(int argc, char ** argv)
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    ListNode n7(7);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;

    printList(&n1);

    reorderList(&n1);

    printList(&n1);

    return 0;
}
