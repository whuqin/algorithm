import java.io.File;
/**
 * Created by qinbin on 2017/4/25.
 */
public class ValidBST {
    public static boolean isValid(TreeNode node, int lower, int upper) {
        if (node == null) return true;
        return node.val > lower && node.val < upper
                && isValid(node.left, lower, node.val)
                && isValid(node.right, node.val, upper);
    }
    public static void main(String[] args) {
        System.out.println(new File("").getAbsolutePath());
        System.out.println(System.getProperty("user.dir"));
    }
}
