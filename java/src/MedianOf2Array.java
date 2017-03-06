/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 Example 1:
 nums1 = [1, 3]
 nums2 = [2]
 The median is 2.0
 Example 2:
 nums1 = [1, 2]
 nums2 = [3, 4]
 The median is (2 + 3)/2 = 2.5
 * Created by qinbin on 2017/3/3.
 */
public class MedianOf2Array {
    public static double getMedOf2SortedArr(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        if (n > m) {
            return getMedOf2SortedArr(nums2, nums1);
        }
        if (n == 0)  {
            return getMedOfArray(nums2);
        }
        if (m == 0) {
            return getMedOfArray(nums1);
        }
        int cut1, cut2, L1 = 0, R1 = 0, L2 = 0, R2 = 0;
        int low = 0, high = 2 * nums1.length;
        while (low <= high) {
            cut1 = (low + high) / 2;
            cut2 = m + n - cut1;
            L1 = cut1 == 0 ? Integer.MIN_VALUE : nums1[(cut1 - 1) / 2];
            R1 = cut1 == 2 * nums1.length ? Integer.MAX_VALUE : nums1[cut1 / 2];
            L2 = cut2 == 0 ? Integer.MIN_VALUE : nums2[(cut2 - 1) / 2];
            R2 = cut2 == 2 * nums2.length ? Integer.MAX_VALUE : nums2[cut2 / 2];
            if (L1 > R2) {
               high = cut1 - 1;
            } else if (L2 > R1) {
                low = cut1 + 1;
            } else {
                break;
            }
        }
        return (Math.max(L1, L2) + Math.min(R1, R2)) / 2.0;
    }

    public static double getMedOfArray(int[] arr) {
        if (arr.length == 0) {
            return 0;
        }
        return (arr[arr.length / 2] + arr[(arr.length - 1) / 2]) / 2.0;
    }

    public static void main(String[] args) {
        System.out.println(getMedOf2SortedArr(new int[] {1, 2, 3, 5}, new int[]{4, 5, 6}));
    }
}
