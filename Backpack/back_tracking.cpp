#include <iostream>
#include <vector>

// ��Ʒ�ṹ��
struct Item {
    int weight;
    int value;
};

// ���ݷ����01��������ĺ���
void knapsackBacktrack(int idx, int currentWeight, int currentValue, int& maxValue, const std::vector<Item>& items, int capacity) {
    // ���������Ʒ����������
    if (idx == items.size()) {
        // �������ֵ
        if (currentWeight <= capacity) {
            maxValue = std::max(maxValue, currentValue);
        }
        return;
    }

    // ��ѡ��ǰ��Ʒ
    knapsackBacktrack(idx + 1, currentWeight, currentValue, maxValue, items, capacity);

    // ѡ��ǰ��Ʒ
    if (currentWeight + items[idx].weight <= capacity) {
        knapsackBacktrack(idx + 1, currentWeight + items[idx].weight, currentValue + items[idx].value, maxValue, items, capacity);
    }
}

int main() {
    // ��Ʒ���飬ÿ����Ʒ��һ��������һ����ֵ
    std::vector<Item> items = {
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 8}
    };

    // ����������
    int capacity = 10;

    // ����ֵ
    int maxValue = 0;

    // ʹ�û��ݷ����01��������
    knapsackBacktrack(0, 0, 0, maxValue, items, capacity);

    // �������ֵ
    std::cout << "Maximum value: " << maxValue << std::endl;
    for (int i = 0; i < items.size(); i++)
        std::cout << "(" << items[i].value << "," << items[i].weight << ")" << "\n";
    return 0;
}
