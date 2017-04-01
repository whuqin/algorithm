import java.util.Arrays;
import java.util.Stack;

/**
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
 * find the area of largest rectangle in the histogram.
 * Created by qinbin on 2017/4/1.
 */
public class LargestRectangle {
    public static int largestRecInHistogram(int[] heights) {
        if (null == heights || heights.length == 0) {
            return 0;
        }
        int[] newHeights = Arrays.copyOf(heights, heights.length + 1);
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0;
        for (int i = 0; i < newHeights.length;) {
            if (stack.isEmpty() || newHeights[i] >= newHeights[stack.peek()]) {
                stack.push(i++);
            } else {
                int tmp = stack.pop();
                int area = stack.isEmpty() ? newHeights[tmp] * i : newHeights[tmp] * (i - stack.peek() - 1);
                maxArea = Math.max(area, maxArea);
            }
        }
        return maxArea;
    }

    public static void main(String[] args) {
        int[] heights = new int[]{2, 1, 5, 6, 2, 3};
        System.out.println(largestRecInHistogram(heights));
    }
}
