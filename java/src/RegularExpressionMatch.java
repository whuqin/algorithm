/**
 * '.' Matches any single character.
 '*' Matches zero or more of the preceding element.

 The matching should cover the entire input string (not partial).

 The function prototype should be:
 bool isMatch(const char *s, const char *p)

 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "a*") → true
 isMatch("aa", ".*") → true
 isMatch("ab", ".*") → true
 isMatch("aab", "c*a*b") → true
 * Created by qinbin on 2017/3/9.
 */
public class RegularExpressionMatch {

    public static boolean isMatch(String str, String regex, int strIdx, int regexIdx) {
        if (null == str || null == regex) {
            return false;
        }
        if (regexIdx == regex.length()) return strIdx == str.length();
        if (regexIdx + 1 < regex.length() && regex.charAt(regexIdx + 1) == '*') {
            while (strIdx != str.length() &&
                    (regex.charAt(regexIdx) == '.' || regex.charAt(regexIdx) == str.charAt(strIdx))) {
                if (isMatch(str, regex, strIdx, regexIdx + 2)) return true;
                ++strIdx;
            }
            return isMatch(str, regex, strIdx, regexIdx + 2);
        } else if (strIdx != str.length() &&
                (regex.charAt(regexIdx) == '.' || regex.charAt(regexIdx) == str.charAt(strIdx))) {
            return isMatch(str, regex, ++strIdx, ++regexIdx);
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println(isMatch("a", ".", 0, 0));
    }
}
