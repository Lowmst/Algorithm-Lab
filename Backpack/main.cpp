#include<iostream>
#include<vector>
#include "dp.h"
#include "back_tracking.h"

int main(void)
{
    //��̬�滮
    int capacity = 10; // ��������
    std::vector<Item> items = { {2, 3}, {3, 4}, {4, 5}, {5, 6} }; // ��Ʒ�����ͼ�ֵ
    int n = items.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));
    int max_value = knapsack(capacity, items, n, dp);

    std::vector<bool> included(n, false);
    findItemsIncluded(capacity, items, n, dp, included);

    std::cout << "����ֵΪ: " << max_value << std::endl;
    std::cout << "�������Ϊ: ";
    for (int i = 0; i < n; ++i) {
        if (included[i]) {
            std::cout << i + 1 << " ";
        }
    }
    std::cout << std::endl << std::endl;




    //����

    int maxValue = 0;

    // ʹ�û��ݷ����01��������
    knapsackBacktrack(0, 0, 0, maxValue, items, capacity);

    // �������ֵ
    std::cout << "Maximum value: " << maxValue << std::endl;
    for (int i = 0; i < items.size(); i++)
        std::cout << "(" << items[i].weight << "," << items[i].value << ")" << "\n";
    return 0;
}