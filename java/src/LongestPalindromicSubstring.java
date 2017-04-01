/**
 * Created by qinbin on 2017/2/14.
 */
public class LongestPalindromicSubstring {
    /**
     * l(0, n-1) = l(1, n-2) + 2
     * l(0, n-1) = max(l(0, n-2), l(1,n-1))
     * 最长回文子序列的长度
     */
    public static int longestPalindrome(String s, int i, int j) {
        if (i == j) {
            return 1;
        }
        if (i > j) {
            return 0;
        }
        if (s.charAt(i) == s.charAt(j)) {
            return longestPalindrome(s, ++i, --j) + 2;
        } else {
            return Math.max(longestPalindrome(s, i, j-1), longestPalindrome(s, i + 1, j));
        }
    }

    private static String expand(String s, int i, int j) {
        while (i >= 0 && j <= s.length() - 1) {
            if (s.charAt(i) == s.charAt(j)) {
                --i;
                ++j;
            } else {
                break;
            }
        }
        return s.substring(i + 1, j);
    }

    //最长回文子串
    public static String lps(String s) {
        String lps = "";
        if (s == null || s.length() == 1) {
            return s;
        }
        for (int i = 0; i < s.length() - 1; ++i) {
            String l = expand(s, i, i);
            if (l.length() > lps.length()) lps = l;
            l = expand(s, i, i + 1);
            if (l.length() > lps.length()) lps = l;
        }
        return lps;
    }



    public static void main(String[] args) {
        String s = "abccbaa";
        System.out.println(lps(s));
        System.out.println(longestPalindrome(s, 0, s.length() - 1));
    }
}
