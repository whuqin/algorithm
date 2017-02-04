/**
 Jump Game II
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at that position.
 Your goal is to reach the last index in the minimum number of jumps.
 For example:
 Given array A = [2,3,1,1,4]
 The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 * Created by qinbin on 2017/2/4.
 */
public class JumpGame {
    public static int jump(int[] arr) {
        int step = 0;
        int canArrive = 0;
        int lastArrive = 0;
        for (int i = 0; i < arr.length; ++i) {
            if (i > lastArrive) {
                //i超过了上次跳动的最远距离，则更新到新最远距离
                ++step;
                lastArrive = canArrive;
            }
            canArrive = Math.max(canArrive, i + arr[i]);
        }
        return step;
    }
    public static void main(String[] args) {
        int[] arr = {2,3,1,1,4};
        System.out.println(jump(arr));
    }
}
