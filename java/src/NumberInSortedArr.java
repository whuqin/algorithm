/**
 * Created by qinbin on 2017/3/13.
 */
public class NumberInSortedArr {
    public static int getNumInArr(int[] array, int num) {
        int max = getMaxIdx(array, num);
        int min = getMinIdx(array, num);
        if (-1 == max || -1 == min) {
            return 0;
        } else {
            return max - min + 1;
        }
    }

    //数num的最大索引
    public static int getMaxIdx(int[] array, int num) {
        if (array == null || array.length == 0) {
            return -1;
        }
        int low = 0, high = array.length - 1;
        while (low + 1 < high) {
            int mid = low + (high - low)/2;
            if (num >= array[mid]) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (array[low] == num) return low;
        else if (array[high] == num) return high;
        else return -1;
    }
    public static int getMinIdx(int[] array, int num) {
        if (array == null || array.length == 0) {
            return -1;
        }
        int low = 0, high = array.length - 1;
        while (low + 1 < high) {
            int mid = low + (high - low)/2;
            if (num <= array[mid]) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (array[low] == num) return low;
        else if (array[high] == num) return high;
        else return -1;
    }

    public static void main(String[] args) {
        int[] arr = {3, 4, 4, 4, 5};
        System.out.println(getNumInArr(arr, 4));
    }
}
