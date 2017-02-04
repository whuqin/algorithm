/**
 * Given a binary tree, find the maximum path sum.
 * For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child 
 * connections. The path does not need to go through the root.
 * For example:
 * Given the below binary tree,
 *        1
 *       / \
 *      2   3
 * Return 6.
 */
#include <iostream>
using namespace std;

int MIN_INT = 1 << 31;
int sum = MIN_INT;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
    TreeNode(int x, TreeNode* l, TreeNode* r):val(x), left(l), right(r){}
};

/**
 * 递归函数，从子节点往上考虑。
 * 返回的过程中，记录下可能的最大路径；
 * 并返回该树的包含root的最大左路径或右路经，用于和root上面的路径连接
 **/
int traverse(TreeNode* root) {
    if (NULL == root) {
        return 0;
    }
    //左子树包含根节点的最大路径
    int leftRootPath = max(traverse(root->left), 0);
    //右字数包含根节点的最大路径
    int rightRootPath = max(traverse(root->right), 0);

    //比较替换最大路径
    sum = max(leftRootPath + rightRootPath + root->val, sum);
    //返回连接root的最大路径供后续判断
    return max(leftRootPath, rightRootPath) + root->val;
}

int maxSum(TreeNode* root) {
    if (NULL == root) {
        return 0;
    }
    traverse(root);
    return sum;
}

int main(int argc, char** argv) {
    TreeNode t1(2);
    TreeNode t2(3);
    TreeNode root(1, &t1, &t2);
    cout << maxSum(&root) << endl;
    return 0;
}
