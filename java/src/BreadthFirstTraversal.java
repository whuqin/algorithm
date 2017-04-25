import java.util.ArrayList;
import java.util.List;

/**
 * Created by qinbin on 2017/4/25.
 */
public class BreadthFirstTraversal {
    //zigzag
    public void traversal(TreeNode node, int level, List<List<Integer>> result, boolean direction) {
        if (node == null) return;
        if (level > result.size()) {
            result.add(new ArrayList<Integer>());
        }

        if (direction) {
            result.get(level - 1).add(node.val);
        } else {
            result.get(level - 1).add(0, node.val);
        }
        traversal(node.left, level + 1, result, !direction);
        traversal(node.right, level + 1, result, !direction);

    }
}
