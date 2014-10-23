/*Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sum;
void sumNumbers(TreeNode* root, int cur_sum) {
    cur_sum = cur_sum * 10 + root->val;
    if (NULL == root->left && NULL == root->right) {
        sum += cur_sum;
        return;
    }

    if (NULL != root->left) {
        sumNumbers(root->left, cur_sum);
    }

    if (NULL != root->right) {
        sumNumbers(root->right, cur_sum);
    }
}

int sumNumbers(TreeNode *root) {
    sum = 0;
    if (NULL == root) {
        return 0;
    }
    sumNumbers(root, 0);
    return sum;
}

int main() {
    TreeNode node(9);
    cout << sumNumbers(&node) << endl;
}
