#pragma once
#include<vector>
#include "utils.h"
int knapsack(int W, std::vector<Item>& items, int n, std::vector<std::vector<int>>& dp); //动态规划过程
void findItemsIncluded(int W, std::vector<Item>& items, int n, std::vector<std::vector<int>>& dp, std::vector<bool>& included); //选出被装入的物品