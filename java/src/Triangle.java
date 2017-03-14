import java.util.ArrayList;
import java.util.List;

/**
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 For example, given the following triangle
 [
 [2],
 [3,4],
 [6,5,7],
 [4,1,8,3]
 ]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * Created by qinbin on 2017/3/14.
 */
public class Triangle {
    public static int shortestPath(List<List<Integer>> triangles) {
        if (null == triangles || triangles.size() == 0) {
            return Integer.MIN_VALUE;
        }
        int row = triangles.size();
        List<Integer> minPath = new ArrayList<Integer>(triangles.get(triangles.size() - 1));
        for (int i = row - 2; i >= 0; --i) {
            for (int j = 0; j < triangles.get(i).size(); ++j) {
                minPath.set(j, Math.min(minPath.get(j), minPath.get(j+1)) + triangles.get(i).get(j));
            }
        }
        return minPath.get(0);
    }
}
