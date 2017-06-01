/**
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent,
 * with the colors in the order red, white and blue.
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 * Created by qinbin on 2017/6/1.
 */
public class SortColor {
    public static void sortColor(int[] arr)  {
        int red = 0;
        int blue = arr.length - 1;
        for (int i = 0; i <= blue;) {
            if (arr[i] == 0) {
                int tmp = arr[i];
                arr[i] = arr[red];
                arr[red] = tmp;
                ++i;
                ++red;
            } else if(arr[i] == 2) {
                int tmp = arr[i];
                arr[i] = arr[blue];
                arr[blue] = tmp;
                --blue;
            } else {
                ++i;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {1,2,2,0,0,1};
        sortColor(arr);
        for (int tmp : arr) {
            System.out.println(tmp);
        }
    }
}
