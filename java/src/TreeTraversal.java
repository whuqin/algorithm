import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * Created by qinbin on 2017/4/6.
 */
public class TreeTraversal {
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
    }
    public static List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        if (null == root) {
            return list;
        }
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode p = stack.pop();
            list.add(p.val);
            if (p.right != null) stack.push(p.right);
            if (p.left != null) stack.push(p.left);
        }
        return list;
    }

    public static List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode p = root;
        while (!stack.isEmpty() || p != null) {
            if (p != null) {
                stack.push(p);
                p = p.left;
            } else {
                p = stack.pop();
                list.add(p.val);
                p = p.right;
            }
        }
        return list;
    }

    //左右都访问完了再访问根节点
    public static void postOrderTraversal(TreeNode root, List<Integer> list) {
        if (root == null) {
            return;
        }
        postOrderTraversal(root.left, list);
        postOrderTraversal(root.right, list);
        list.add(root.val);
    }

    public static List<Integer> postOrderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode p = root;
        do {
            while (p != null) {
                stack.push(p);
                p = p.left;
            }
            TreeNode q = null;//记录刚访问过的节点
            while (!stack.isEmpty()) {
                p = stack.pop();
                if (p.right == q) {
                    //p可以出栈了
                    list.add(p.val);
                    q = p;
                } else {
                    //p的右节点还没有访问，归栈
                    stack.push(p);
                    //处理右子树
                    p = p.right;
                    break;
                }
            }
        } while (!stack.isEmpty());
        return list;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode();
        root.val = 1;
        root.left = new TreeNode();
        root.left.val = 2;
        root.right = new TreeNode();
        root.right.val = 3;
        root.left.right = new TreeNode();
        root.left.right.val = 4;
        List<Integer> list = new ArrayList<>();
        postOrderTraversal(root, list);
        for (Integer i : list) {
            System.out.println(i);
        }
        System.out.println("----------------");
        list = postOrderTraversal(root);
        for (Integer i : list) {
            System.out.println(i);
        }
    }


}
