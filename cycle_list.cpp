/***************************************************************************
 * 
 * Copyright (c) 2014. All Rights Reserved
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Follow up:
 * Can you solve it without using extra space?
 * 
 **************************************************************************/
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    if (head == NULL)
    {
        return NULL;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (fast->next == NULL || fast->next->next == NULL)
    {
        return NULL;
    }
    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}


















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
