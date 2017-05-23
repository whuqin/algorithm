/**
 * Given an unsorted integer array, find the first missing positive integer.
 * For example,
 * Given [1,2,0] return 3, and [3,4,-1,1] return 2.
 * Your algorithm should run in O(n) time and uses constant space.
 * Created by qinbin on 2017/5/23.
 */
public class FirstMissingPositive {

    public int firstMissingPositive(int[] nums) {
        bucketSort(nums);
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.length + 1;
    }

    //bucket排序的目标就是A[i] = i + x; x是个常量，保证a存的数据随着i递增
    public void bucketSort(int[] arr) {
        for (int i = 0; i < arr.length; ++i) {
            while (arr[i] != i + 1) {
                if (arr[i] <= 0 || arr[i] > arr.length || arr[i] == arr[arr[i] - 1]) {
                    break;
                }
                int tmp = arr[arr[i] - 1];
                arr[arr[i] - 1] = arr[i];
                arr[i] = tmp;
            }
        }
    }

}
