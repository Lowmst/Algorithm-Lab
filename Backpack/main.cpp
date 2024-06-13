#include<iostream>
#include<vector>
#include "dp.h"
#include "back_tracking.h"

int main(void)
{
    //动态规划
    int capacity = 10; // 背包容量
    std::vector<Item> items = { {2, 3}, {3, 4}, {4, 5}, {5, 6} }; // 物品重量和价值
    int n = items.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));
    int max_value = knapsack(capacity, items, n, dp);

    std::vector<bool> included(n, false);
    findItemsIncluded(capacity, items, n, dp, included);

    std::cout << "最大价值为: " << max_value << std::endl;
    std::cout << "背包组合为: ";
    for (int i = 0; i < n; ++i) {
        if (included[i]) {
            std::cout << i + 1 << " ";
        }
    }
    std::cout << std::endl << std::endl;




    //回溯

    int maxValue = 0;

    // 使用回溯法解决01背包问题
    knapsackBacktrack(0, 0, 0, maxValue, items, capacity);

    // 输出最大价值
    std::cout << "Maximum value: " << maxValue << std::endl;
    for (int i = 0; i < items.size(); i++)
        std::cout << "(" << items[i].weight << "," << items[i].value << ")" << "\n";
    return 0;
}