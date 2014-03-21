/***************************************************************************
 * 
 * Copyright (c) 2014. All Rights Reserved
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the
 * following operations: get and set.
 *
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache,
 * otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present. When the cache
 * reached its capacity, it should invalidate the least recently used item before inserting a new
 * item.
 **************************************************************************/
 
#include <ext/hash_map>
#include <iostream>
using namespace std;
using namespace __gnu_cxx;

//node for one entry
typedef struct _node
{
    int key;
    int value;
    _node* pre;
    _node* next;
} node;

//LRUcache
class LRUCache
{
public:
    LRUCache(int capacity);
    ~LRUCache();
    int get(int key);
    void set(int key, int value);
private:
    hash_map<int, node*> index;
    node* head;
    node* tail;
    int capacity;
    int size;
};

LRUCache::LRUCache(int capacity):capacity(capacity), size(0)
{
    head = new node;
    tail = new node;
    head->key = head->value = -1;
    tail->key = tail->value = -1;
    head->next = tail;
    head->pre = NULL;
    tail->pre = head;
    tail->next = NULL;
}

LRUCache::~LRUCache()
{
    while (head != NULL)
    {
        node* tmp = head->next;
        delete head;
        head = tmp;
    }
}

void LRUCache::set(int key, int value)
{
    if (capacity == 0)
    {
        return;
    }
    node* tmp = NULL;
    hash_map<int, node*>::iterator it = index.find(key);
    if (it != index.end())
    {
        tmp = it->second;
        tmp->value = value;
        //contact list
        tmp->pre->next = tmp->next;
        tmp->next->pre = tmp->pre;
    }
    else if (index.size() == capacity)
    {
        tmp = tail->pre;
        tail->pre = tmp->pre;
        tmp->pre->next = tail;
        index.erase(tmp->key); 
        tmp->key = key;
        tmp->value = value;
        index.insert(make_pair(key, tmp));
    }
    else
    {
        tmp = new node;
        tmp->key = key;
        tmp->value = value;
        index.insert(make_pair(key, tmp));
    }
    //mv tmp to head
    tmp->next = head->next;
    head->next = tmp;
    tmp->next->pre = tmp;
    tmp->pre = head;
}

int LRUCache::get(int key)
{
    hash_map<int, node*>::iterator it = index.find(key);
    if (it == index.end())
    {
        return -1;
    }
    node* tmp = it->second;
    tmp->pre->next = tmp->next;
    tmp->next->pre = tmp->pre;
    tmp->next = head->next;
    head->next = tmp;
    tmp->next->pre = tmp;
    tmp->pre = head;
    return tmp->value;
}

int main()
{
    LRUCache cache(1);
    cache.set(2, 1);
    cout << cache.get(2) << endl;
    cout << cache.get(1) << endl;
    cache.set(3, 2);
    cout << cache.get(3) << endl;
    cout << cache.get(2) << endl;
    return 0;
}














/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
