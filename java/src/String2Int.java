/**
 * Created by qinbin on 2017/2/21.
 */
public class String2Int {
    public static int atoi(String str) {
        if (str.isEmpty()) return 0;
        int i = 0, sign = 1;
        long base = 0;
        while (str.charAt(i) == ' ') ++i;
        if (str.charAt(i) == '-') {
            sign = -1;
            ++i;
        } else if (str.charAt(i) == '+') {
            ++i;
        }
        while (i < str.length() && str.charAt(i) >= '0' && str.charAt(i) <= '9') {
            base = base * 10 + (str.charAt(i) - '0');
            if (base > Integer.MAX_VALUE && sign == 1) return Integer.MAX_VALUE;
            if (base - 1 > Integer.MAX_VALUE && sign == -1) return Integer.MIN_VALUE;
            ++i;
        }
        return (int)base * sign;
    }
    public static void main(String[] args) {
        System.out.println(atoi("123"));
        System.out.println(atoi(" -+123"));
    }
}
