#pragma once
#include<vector>
#include "utils.h"
int knapsack(int W, std::vector<Item>& items, int n, std::vector<std::vector<int>>& dp); //��̬�滮����
void findItemsIncluded(int W, std::vector<Item>& items, int n, std::vector<std::vector<int>>& dp, std::vector<bool>& included); //ѡ����װ�����Ʒ