import java.util.Arrays;

/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 How many possible unique paths are there?
 * Created by qinbin on 2017/7/5.
 */
public class UniqPaths {
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) {
            return 0;
        }
        if (m == 1 || n == 1) {
            return 1;
        }
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }

    int uniquePaths1(int m, int n) {
        int[] array = new int[n + 1];
        Arrays.fill(array, 0);
        array[1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                array[j] = array[j] + array[j - 1];
            }
        }
        return array[n];
    }

}
