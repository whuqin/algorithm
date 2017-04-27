import java.util.Stack;

/**
 * Created by qinbin on 2017/4/27.
 */
public class FlattenBinaryTree {
    public void flatten(TreeNode root) {
        if (root == null) return;
        flatten(root.left);
        flatten(root.right);
        TreeNode node = root.left;
        while (node.right != null) node = node.right;
        node.right = root.right;
        root.right = node.left;
        root.left = null;
    }

    public void flatten1(TreeNode root) {
        if (root == null) return;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            if (node.right != null) stack.push(node.right);
            if (node.left != null) stack.push(node.left);
            node.left = null;
            if (!stack.isEmpty()) {
                node.right = stack.peek();
            }
        }
    }
}
