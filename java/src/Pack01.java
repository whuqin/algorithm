/**
 * 01背包问题，背包容量固定，选择背包能装的最大价值货物
 * Created by qinbin on 2017/2/27.
 */
public class Pack01 {
    private static int packVol = 100;
    private static int goodsNum = 5;
    private static int[] goodsVol = {77,22,29,50,99};
    private static int[] goodsVal = {92,22,87,46,90};
    private static int[][] maxValue = new int[packVol + 1][goodsNum];
    public static int getMaxValue(int volume, int goodsIdx) {
        if (volume <= 0 || goodsIdx < 0) {
            return 0;
        }
        if (volume < goodsVol[goodsIdx]) {
            return 0;
        }
        if (maxValue[volume][goodsIdx] > -1) {
            return maxValue[volume][goodsIdx];
        }
        int pack_not_goods = getMaxValue(volume, goodsIdx - 1);
        int pack_goods = getMaxValue(volume - goodsVol[goodsIdx], goodsIdx - 1) + goodsVal[goodsIdx];
        int max = Math.max(pack_goods, pack_not_goods);
        maxValue[volume][goodsIdx] = max;
        return max;
    }

    public static void main(String[] args) {
        for (int i = 0; i <= packVol; ++i) {
            for (int j = 0; j < goodsNum; ++j) {
                maxValue[i][j] = -1;
            }
        }
        System.out.println(getMaxValue(packVol, goodsNum - 1));
    }

}
