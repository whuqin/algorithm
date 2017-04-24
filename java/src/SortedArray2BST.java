import java.util.List;

/**
 * Created by qinbin on 2017/4/24.
 */
public class SortedArray2BST {
    public static TreeNode sorted2BST(int[] array, int start, int end) {
        if (start > end) {
            return null;
        }
        int mid = start + (end - start) / 2;
        TreeNode left = sorted2BST(array, start, mid - 1);
        TreeNode right = sorted2BST(array, mid + 1, end);
        TreeNode root = new TreeNode(array[mid]);
        root.left = left;
        root.right = right;
        return root;
    }

    public static void main(String[] args) {
        int[] array = new int[]{0, 1, 2, 3, 4, 5};
        TreeNode root = sorted2BST(array, 0, array.length - 1);
        List<Integer> list = TreeTraversal.inorderTraversal(root);
        for (Integer i : list) {
            System.out.println(i);
        }
    }
}
