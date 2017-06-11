/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Print
 *
 * Created on June 8, 2017, 9:25 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */

struct ListNode {
    int m_val;
    ListNode * m_next;
    ListNode * m_down;
    
    ListNode(int val) : m_val(val), m_next(0), m_down(0){};
};

// Return the last node (node->m_next == 0)
ListNode * flatten(ListNode * head)
{
    if (head->m_next == 0)
    {
        if (head->m_down == 0)
            return head;
        else
        {
            head->m_next = head->m_down;
            head->m_down = 0;
            return flatten(head->m_next);
        }
    }
    else 
    {
        if (head->m_down == 0)
        {
            return flatten(head->m_next);
        }
        else
        {
            ListNode * cur = head;
            ListNode * curNext = head->m_next;
            
            cur->m_next = cur->m_down;
            cur->m_down = 0;
            
            flatten(cur->m_next)->m_next = curNext;
            
            return curNext;
        }
    }
}


/*
 * 
 * 1->2->3->7
 * |     |
 * 4->5  8
 *    |
 *    6
 * 
 * 1->4->5->6->2->3->8->7
 */

void printNext(ListNode * head)
{
    while (head)
    {
        std::cout << head->m_val << " ";
        head = head->m_next;
    }
    
    std::cout << std::endl;
}

int main(int argc, char** argv) {

    std::cout << "Main" << std::endl;
    
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    ListNode n7(7);
    ListNode n8(8);
    
    n1.m_next = &n2;
    n1.m_down = &n4;
    
    n4.m_next = &n5;
    n5.m_down = &n6;
    
    n2.m_next = &n3;
    
    n3.m_next = &n7;
    n3.m_down = &n8;
    
    ListNode * head = &n1;
    
    flatten(head);
    
    printNext(&n1);
    
    return 0;
}

