/***************************************************************************
 * 
 * Copyright (c) 2014 whuqin, All Rights Reserved
 * Given a singly linked list L: L0 -> L1 -> L2 -> ... -> Ln-1 -> Ln
 * reorder it to: L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 **************************************************************************/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head)
{
    ListNode* p1 = NULL;
    ListNode* p2 = head;
    while (p2 != NULL)
    {
        ListNode* tmp = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = tmp;
    }
    return p1;
}

void reorderList(ListNode *head) {
    if (NULL == head || NULL == head->next) {
        return;
    }
    //split
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* tail = slow->next;
    slow->next = NULL;
    //reverse tail
    tail = reverseList(tail);
    //merge head tail
    ListNode* h = head;
    ListNode* t = tail;
    while (h != NULL && t != NULL)
    {
        ListNode* tmp = h->next;
        h->next = t;
        t = t->next;
        h->next->next = tmp;
        h = tmp;
    }
    if (t != NULL)
    {
        h->next = t;
    }
}















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
