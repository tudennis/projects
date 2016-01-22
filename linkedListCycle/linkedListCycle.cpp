/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.
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

bool hasCycle(ListNode * head)
{
    if (head == 0 || head->next == 0)
        return false;

    ListNode* slow(head);
    ListNode* fast(head);

    while (fast->next != 0 && fast->next->next != 0)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

ListNode * detectCycle(ListNode* head)
{
    if (head == 0 || head->next == 0)
        return 0;

    ListNode* slow(head);
    ListNode* fast(head);

    bool hasCycle(false);

    while (fast->next != 0 && fast->next->next != 0)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            hasCycle = true;
            break;
        }
    }

    if (hasCycle)
    {
        slow = head;    // reset slow pointer to head

        // Move slow and fast all at same pace till they meet, that's the point cycle starts
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char ** argv)
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    // printList(&n1);

    // printList(&n1);

    // Create a cycle
    n6.next = &n3;

    cout << hasCycle(&n1) << endl;

    ListNode* cycleStart = detectCycle(&n1);
    if (cycleStart != 0)
    {
        cout << "cycle starts at: " << cycleStart->val << endl;
    }
    return 0;
}
