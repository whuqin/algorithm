/***************************************************************************
 * 
 * Copyright (c) 2014 whuqin. All Rights Reserved
 * Given a tree and two nodes, find the last common parent node of the two nodes
 * 
 **************************************************************************/
 
#include <list>
#include <iostream>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):value(x), left(NULL), right(NULL){}
};

bool findNodePath(TreeNode* root, TreeNode* node, list<TreeNode*>& path)
{
    if (root == node)
    {
        path.push_back(root);
        return true;
    }

    bool found = false;
    path.push_back(root);
    if (NULL != root->left)
    {
        found = findNodePath(root->left, node, path);
    }
    if (!found && NULL != root->right)
    {
        found = findNodePath(root->right, node, path);
    }
    if (!found)
    {
        path.pop_back();
    }
    return found;
}

TreeNode* lastCommonNode(list<TreeNode*> path1, list<TreeNode*> path2)
{
    list<TreeNode*>::iterator it1 = path1.begin();
    list<TreeNode*>::iterator it2 = path2.begin();
    TreeNode* common = NULL;
    while (it1 != path1.end() && it2 != path2.end())
    {
        if (*it1 == *it2)
        {
            common = *it1;
        }
        ++it1;
        ++it2;
    }
    return common;
}

TreeNode* lastParent(TreeNode* root, TreeNode* node1, TreeNode* node2)
{
    if (NULL == root || NULL == node1 || NULL == node2)
    {
        return NULL;
    }
    list<TreeNode*> path1;
    list<TreeNode*> path2;
    bool found1 = findNodePath(root, node1, path1);
    bool found2 = findNodePath(root, node2, path2);
    if (!found1 || !found2)
    {
        return NULL;
    }
    return lastCommonNode(path1, path2);
}

int main()
{
    TreeNode root(0);
    TreeNode left(1);
    TreeNode right(2);
    root.left = &left;
    root.right = &right;
    TreeNode node3(3);
    left.left = &node3;
    //TreeNode* node = lastParent(&root, &left, &right);
    TreeNode* node = lastParent(&root, &left, &node3);
    cout << node->value << endl;
}
/* vim: set ts=4 sw=4 sts=4 tw=100 */
