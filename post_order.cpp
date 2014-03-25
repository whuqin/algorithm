/***************************************************************************
 * 
 * Copyright (c) 2014 whuqin. All Rights Reserved
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * For example:
 * Given binary tree {1,#,2,3},
 * 1
 *  \
 *   2
 *  /
 *  3
 * return [3,2,1].
 * Note: Recursive solution is trivial, could you do it iteratively?
 *
 **************************************************************************/
 
#include <vector>
#include <stack>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode*> node_stack;
    if (NULL == root)
    {
        return result;
    }
    if (root != NULL)
    {
        node_stack.push(root);
    }
    if (root->right != NULL)
    {
        node_stack.push(root->right);
    }
    if (root->left != NULL)
    {
        node_stack.push(root->left);
    }
    root->left = root->right = NULL;
    while (!node_stack.empty())
    {
        TreeNode* tmp = node_stack.top();
        node_stack.pop();
        if (NULL == tmp->left && NULL == tmp->right)
        {
            result.push_back(tmp->val);
            continue;
        }
        node_stack.push(tmp);
        if (tmp->right != NULL)
        {
            node_stack.push(tmp->right);
        }
        if (tmp->left != NULL)
        {
            node_stack.push(tmp->left);
        }
        tmp->left = NULL;
        tmp->right = NULL;
    }
    return result; 
}

int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node1.left = NULL;
    node1.right = &node2;
    node2.left = &node3;
    node2.right = NULL;
    node3.left = node3.right = NULL;
    vector<int> res = postorderTraversal(&node1);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
    return 0;
}
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
