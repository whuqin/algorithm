/**
 * given a binary tree, find the max path sum
 * Created by qinbin on 2017/5/9.
 */
public class MaxPathOfBinaryTree {
    public static int maxSum = 0;

    public static int maxPath(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int leftPath = maxPath(root.left);
        int rightPath = maxPath(root.right);
        int sum = root.val;
        if (leftPath > 0)  sum += leftPath;
        if (rightPath > 0) sum += rightPath;
        maxSum = Math.max(maxSum, sum);
        return Math.max(leftPath, rightPath) > 0 ? Math.max(leftPath, rightPath) + root.val : root.val;
    }
}
