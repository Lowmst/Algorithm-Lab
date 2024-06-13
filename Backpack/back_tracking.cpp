#include <iostream>
#include <vector>

// 物品结构体
struct Item {
    int weight;
    int value;
};

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

int main() {
    // 物品数组，每个物品有一个重量和一个价值
    std::vector<Item> items = {
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 8}
    };

    // 背包的容量
    int capacity = 10;

    // 最大价值
    int maxValue = 0;

    // 使用回溯法解决01背包问题
    knapsackBacktrack(0, 0, 0, maxValue, items, capacity);

    // 输出最大价值
    std::cout << "Maximum value: " << maxValue << std::endl;
    for (int i = 0; i < items.size(); i++)
        std::cout << "(" << items[i].value << "," << items[i].weight << ")" << "\n";
    return 0;
}
