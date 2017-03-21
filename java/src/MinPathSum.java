/**
 * Created by qinbin on 2017/3/21.
 */
public class MinPathSum {
    public static int minPath(int[][] grid) {
        if (null == grid || 0 == grid.length) {
            return 0;
        }
        int row = grid.length;
        int col = grid[0].length;

        int[] minPath = new int[col + 1];
        for (int i = 0; i <= col; ++i) {
            minPath[i] = Integer.MAX_VALUE;
        }
        minPath[1] = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 1; j <= col; ++j) {
                minPath[j] = Math.min(minPath[j - 1], minPath[j]) + grid[i][j - 1];
            }
        }
        return minPath[col];
    }
}
