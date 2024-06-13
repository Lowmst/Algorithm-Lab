#pragma once
#include<string>
#include<vector>
int lcs(const std::string& X, const std::string& Y);
std::string getLCS(const std::string& X, const std::string& Y, const std::vector<std::vector<int>>& dp);