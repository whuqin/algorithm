/***************************************************************************
 * 
 * Copyright (c) 2014 whuqin. All Rights Reserved
 * A linked list is given such that each node contains an additional random pointer 
 * which could point to any node in the list or null.
 * Return a deep copy of the list.
 * 
 **************************************************************************/
#include <map>
using namespace std;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


 
RandomListNode *copyRandomList(RandomListNode *head) {
    if (NULL == head)
    {
        return NULL;
    }
    map<RandomListNode*, RandomListNode*> ptr_map;
    RandomListNode new_head(0);
    RandomListNode* new_cur = &new_head;
    RandomListNode* old_cur = head;
    while (old_cur != NULL)
    {
        RandomListNode* tmp = new RandomListNode(old_cur->label);
        tmp->random = old_cur->random;
        new_cur->next = tmp;
        ptr_map.insert(make_pair(old_cur, tmp));
        old_cur = old_cur->next;
        new_cur = new_cur->next;
    }
    //random ptr
    new_cur = new_head.next;
    while (new_cur != NULL)
    {
        if (new_cur->random != NULL)
        {
            new_cur->random = ptr_map.find(new_cur->random)->second;
        }
        new_cur = new_cur->next;
    }
    return new_head.next;
}




















/* vim: set ts=4 sw=4 sts=4 tw=100 */
