/**
 * Created by qinbin on 2017/2/22.
 */
public class Divide2Int {
    public static int divide(int dividend, int divisor) {
        int total = 0;//计算结果
        boolean sign = (dividend < 0) ^ (divisor < 0);
        if (divisor == 0 || (dividend == Integer.MIN_VALUE && divisor == -1)) {
            return Integer.MAX_VALUE;
        }
        long div = Math.abs((long)dividend);
        long dis = Math.abs((long)divisor);
        while (div >= dis) {
            long mul_dis = dis;
            int i = 0;
            while (div >= (mul_dis << 1)) {
                ++i;
                mul_dis <<= 1;
            }
            div -= mul_dis;
            total += 1 << i;
        }
        return sign ? -total : total;
    }

    public static void main(String[] args) {
        System.out.println(divide(10, 3));
    }
}
