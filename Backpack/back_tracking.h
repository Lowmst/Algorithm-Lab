#pragma once
#include<vector>
#include "utils.h"

void knapsackBacktrack(int idx, int currentWeight, int currentValue, int& maxValue, const std::vector<Item>& items, int capacity);
