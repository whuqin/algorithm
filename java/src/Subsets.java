import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * subset 1:
 * Given a set of distinct integers, S, return all possible subsets.
 * Note: Elements in a subset must be in non-descending order. The solution set must not contain duplicate subsets.
 * For example, If S = [1,2,3], a solution is:
 * [ [3], [1], [2], [1,2,3], [1,3], [2,3], [1,2], []]
 * subset 2:
 * Given a set of integers, S, s has duplicate elements
 * Created by qinbin on 2017/6/5.
 */
public class Subsets {
    public static List<List<Integer>> subset(int[] arr) {
        Arrays.sort(arr);
        List<List<Integer>> result = new ArrayList<>();
        subset2(arr, 0, new ArrayList<Integer>(), result);
        return result;
    }
    //no duplicate
    public static void subset(int[] arr, int idx, List<Integer> path, List<List<Integer>> result) {
        if (idx == arr.length) {
            result.add(new ArrayList<Integer>(path));
            return;
        }
        //不选当前值
        subset(arr, idx + 1, path, result);
        //选当前值
        path.add(arr[idx]);
        subset(arr, idx + 1, path, result);
        path.remove(path.size() - 1);
    }

    //has duplicate
    public static void subset2(int[] arr, int idx, List<Integer> path, List<List<Integer>> result) {
        result.add(new ArrayList<Integer>(path));
        for (int i = idx; i < arr.length; ++i) {
            if (i != idx && arr[i] == arr[i - 1]) continue;
            path.add(arr[i]);
            subset2(arr, i + 1, path, result);
            path.remove(path.size() - 1);
        }
    }

    public static void main(String[] args) {
        int[] arr = new int[] {1, 2, 3};
        List<List<Integer>> res = subset(arr);
        StringBuilder sb = new StringBuilder();
        System.out.println("size:" + res.size());
        for (List<Integer> list : res) {
            sb.delete(0, sb.length());
            sb.append("[");
            for (Integer i : list) {
                sb.append(i).append(",");
            }
            sb.append("]");
            System.out.println(sb.toString());
        }
    }
}