import java.util.ArrayList;
import java.util.List;

/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 Return all possible palindrome partitioning of s.
 For example, given s = "aab",
 Return
 [
 ["aa","b"],
 ["a","a","b"]
 ]
 * Created by qinbin on 2017/7/3.
 */
public class PalindromePartition {

    public List<List<String>> paldindromePartition(String str) {
        List<List<String>> result = new ArrayList<>();
        partition(str, new ArrayList<String>(), result, 0);
        return result;
    }

    private void partition(String str, List<String> path, List<List<String>> result, int start) {
        if (start == str.length()) {
            result.add(new ArrayList<String>(path));
            return;
        }
        for (int i = start; i < str.length(); ++i) {
            if (isPalindrome(str, start, i)) {
                path.add(str.substring(start, i + 1));
                partition(str, path, result, i + 1);
                path.remove(path.size() - 1);
            }
        }
    }

    //字符串str从i到j之间是否为回文串
    private boolean isPalindrome(String str, int i, int j) {
        while (i < j) {
            if (str.charAt(i) == str.charAt(j)) {
                ++i;
                --j;
            } else {
                break;
            }
        }
        return i>=j;
    }
}
