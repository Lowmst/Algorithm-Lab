#include <vector>
#include "dp.h"

int knapsack(int W, std::vector<Item>& items, int n, std::vector<std::vector<int>>& dp) {
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = std::max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

void findItemsIncluded(int W, std::vector<Item>& items, int n, std::vector<std::vector<int>>& dp, std::vector<bool>& included) {
    int w = W;
    for (int i = n; i > 0 && w > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            included[i - 1] = true;
            w -= items[i - 1].weight;
        }
    }
}
