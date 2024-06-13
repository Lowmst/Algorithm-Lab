#include <iostream>
#include <vector>
#include "back_tracking.h"

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