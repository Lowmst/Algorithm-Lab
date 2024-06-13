#include<iostream>
#include<string>
#include<vector>
#include "max_sum.h"
#include "lcs.h"

int main(void)
{
	//最大子段和
	int a[] = { -2,11,-4,13,-5,-2,6 };

	for (int i = 0; i < 7; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	int sum = max_sum(a, 7);
	
	std::cout << std::endl << "max sub sum is " << sum << std::endl;

	//LCS
    std::string X = "ABCBDAB";
    std::string Y = "BDCAB";

    int lcs_length = lcs(X, Y);
    std::cout << "最长公共子序列长度为: " << lcs_length << std::endl;

    std::vector<std::vector<int>> dp(X.length() + 1, std::vector<int>(Y.length() + 1, 0));
    for (int i = 1; i <= X.length(); ++i) {
        for (int j = 1; j <= Y.length(); ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::string lcs_str = getLCS(X, Y, dp);
    std::cout << "最长公共子序列为: " << lcs_str << std::endl;


	return 0;
}