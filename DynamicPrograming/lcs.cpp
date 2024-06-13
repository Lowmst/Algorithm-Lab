#include<string>
#include<vector>

int lcs(const std::string& X, const std::string& Y) {
    int m = X.length();
    int n = Y.length();

    // Create a 2D vector to store the dp values
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Build the dp table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Return the length of LCS
    return dp[m][n];
}
std::string getLCS(const std::string& X, const std::string& Y, const std::vector<std::vector<int>>& dp) {
    int i = X.length();
    int j = Y.length();
    std::string lcs_str;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_str.push_back(X[i - 1]);
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        }
        else {
            --j;
        }
    }

    std::reverse(lcs_str.begin(), lcs_str.end());
    return lcs_str;
}