#include <iostream>
#include <vector>
#include "back_tracking.h"

// 回溯法解决01背包问题的函数
void knapsackBacktrack(int idx, int currentWeight, int currentValue, int& maxValue, const std::vector<Item>& items, int capacity) {
    // 如果所有物品都处理完了
    if (idx == items.size()) {
        // 更新最大值
        if (currentWeight <= capacity) {
            maxValue = std::max(maxValue, currentValue);
        }
        return;
    }

    // 不选择当前物品
    knapsackBacktrack(idx + 1, currentWeight, currentValue, maxValue, items, capacity);

    // 选择当前物品
    if (currentWeight + items[idx].weight <= capacity) {
        knapsackBacktrack(idx + 1, currentWeight + items[idx].weight, currentValue + items[idx].value, maxValue, items, capacity);
    }
}