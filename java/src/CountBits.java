/**
 * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
 Example:
 For num = 5 you should return [0,1,1,2,1,2].
 * Created by qinbin on 2017/3/16.
 */
public class CountBits {
    public static int countBits(int num) {
        int[] bits = new int[num + 1];
        bits[0] = 0;
        for (int i = 1; i <= num; ++i) {
            bits[i] = bits[(i >> 1)] + (i & 1);
        }
        int all = 0;
        for (int i = 0; i <= num; ++i) {
            all += bits[i];
        }
        return all;
    }

    public static void main(String[] args) {
        System.out.println(countBits(8));
    }
}
