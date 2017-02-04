/**
 * 01背包问题, 不需要具体的选择方案，只求最优值
 * 
 * pack01.in文件介绍
 * 第一行：背包总容量，商品总个数
 * 后续每行：第i个商品的体积，价值
 * 
 * 动态规划问题的特征
 * 1.最优结构：子问题最优时，当前问题也能获得最优结果
 * 2.子问题重叠：母问题可以拆分成子问题，子问题和母问题间是相类似的问题
 * 3.子问题独立：问题间互不影响
 * 4.有边界：问题不会无限拆分和循环下去
 * 5.引入备忘录：记录子问题的答案，避免重复计算
 *
 */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int MAX_PACK_VOLUME = 200;
const int MAX_GOODS_NUM = 100;
int packVolume;   //背包容量
int goodsNum;     //商品个数
int goodsVolume[MAX_GOODS_NUM]; //各商品的体积
int goodsValue[MAX_GOODS_NUM];  //各商品的价值
int maxValue[MAX_PACK_VOLUME][MAX_GOODS_NUM];   //记录各子问题的最优值，背包容量为i/商品个数为j，存放商品的最大价值

void init() {
    ifstream ifile("pack01.in", ifstream::in);
    ifile >> packVolume >> goodsNum;
    cout << packVolume << ":" << goodsNum << endl;
    for (int i = 0; i < goodsNum; ++i) {
        ifile >> goodsVolume[i] >> goodsValue[i]; 
        cout << goodsVolume[i] << ":" << goodsValue[i] << endl;
    }
    for (int i = 0; i <= packVolume; ++i) {
        for (int j = 0; j <= goodsNum; ++j) {
            maxValue[i][j] = -1;
        }
    }
}

int getMaxValue(int packVolume, int goodsNum) {
    //动态规划的边界
    if (goodsNum <= 0 || packVolume <= 0) {
        return 0;
    }
    if (packVolume < goodsVolume[goodsNum - 1]) {
        return 0;
    } else if (maxValue[packVolume][goodsNum] > -1) {
        return maxValue[packVolume][goodsNum];
    } else {
        //对每个商品都有2个选择：取或者不取
        int value_not_pack = getMaxValue(packVolume, goodsNum - 1);
        int value_pack = getMaxValue(packVolume - goodsVolume[goodsNum - 1], goodsNum - 1) + goodsValue[goodsNum-1];
        //目标是取最大值
        int value = max(value_not_pack, value_pack);
        //记录下子问题的最优解，避免重复计算
        maxValue[packVolume][goodsNum] = value;
        return value;
    }
}

int main(int argc, char** argv) {
    init();
    int value = getMaxValue(packVolume, goodsNum);
    cout << value << endl;
}
