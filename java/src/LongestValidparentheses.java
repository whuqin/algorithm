import java.util.Stack;

/**
 * Given a string containing just the characters '(' and ')',
 * find the length of the longest valid (well-formed) parentheses substring.
 For "(()", the longest valid parentheses substring is "()", which has length = 2.
 Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 * Created by qinbin on 2017/4/5
 */
public class LongestValidparentheses {
    public static int longest(String str) {
        if (null == str || str.length() == 0) {
            return 0;
        }
        int last = -1;//最后一个无效的)
        int maxLen = 0;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < str.length(); ++i) {
            if (str.charAt(i) == '(') {
                stack.push(i);
            } else {
                if (stack.isEmpty()) {
                    last = i;
                    continue;
                }
                int idx = stack.pop();
                if (stack.isEmpty()) {
                    maxLen = Math.max(maxLen, i - last);
                } else {
                    maxLen = Math.max(maxLen, i - stack.peek());
                }
            }
        }
        return maxLen;
    }
    public static void main(String[] args) {
        String str = "()()";
        System.out.println(longest(str));
    }
}
