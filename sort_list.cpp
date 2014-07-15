/***************************************************************************
 * 
 * Copyright (c) 2014 whuqin. All Rights Reserved
 * Sort a linked list in O(n log n) time using constant space complexity.
 **************************************************************************/
#include <iostream>
using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
};
//merge two list
ListNode* merge(ListNode* first, ListNode* second)
{
    ListNode* head = NULL;
    ListNode* cur = NULL;
    if (first->val <= second->val)
    {
        head = cur = first;
        first = first->next;
    }
    else
    {
        head = cur = second;
        second = second->next;
    }
    while (first != NULL && second != NULL)
    {
        if (first->val <= second->val)
        {
            cur->next = first;
            cur = first;
            first = first->next;
        }
        else
        {
            cur->next = second;
            cur = second;
            second = second->next;
        }
    }
    if (first != NULL)
    {
        cur->next = first;
    }
    if (second != NULL)
    {
        cur->next = second;
    }
    return head;
}

//merge sort
ListNode* sortList(ListNode *head) 
{
    if (NULL == head)
    {
        return NULL;
    }
    ListNode* first = head;
    ListNode* second = head;
    while (first->next != NULL && (second->next != NULL && second->next->next != NULL))
    {
        first = first->next;
        second = second->next->next;
    }
    if (first->next != NULL)
    {
        second = first->next;
        first->next = NULL;
        first = head;
    }
    else
    {
        return head;
    }
    return merge(sortList(first), sortList(second));
}


int main()
{
    ListNode node1;
    ListNode node2;
    ListNode node3;
    memset(&node1, 0, sizeof(ListNode));
    memset(&node2, 0, sizeof(ListNode));
    memset(&node3, 0, sizeof(ListNode));
    node1.val = 3;
    node2.val = 2;
    node3.val = 4;
    node1.next = &node2;
    node2.next = &node3;
    ListNode* head = sortList(&node1);
    while (head != NULL)
    {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
