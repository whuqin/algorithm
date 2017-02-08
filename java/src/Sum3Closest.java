import java.util.Arrays;

/**
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * Created by qinbin on 2017/2/8.
 */
public class Sum3Closest {

    public static int closest(int[] arr, int target) {
        if (arr.length < 3) {
            return Integer.MAX_VALUE;
        }
        Arrays.sort(arr);
        int closet = arr[0] + arr[1] + arr[2];
        int diff = Math.abs(target - closet);
        for (int i = 0; i < arr.length - 2; ++i) {
            //两边逼近
            int left = i + 1;
            int right = arr.length - 1;
            while (left < right) {
                int tmp = arr[i] + arr[left] + arr[right];
                if (tmp == target) return target;
                if (tmp > target) --right;
                if (tmp < target) ++left;
                int tmpDiff = Math.abs(target - tmp);
                if ( tmpDiff < diff) {
                    closet = tmp;
                    diff = tmpDiff;
                }
            }
        }
        return closet;
    }

    public static void main(String[] args) {
        int[] arr = {-1, 2, 1, -4};
        System.out.println(closest(arr, 1));
    }
}
