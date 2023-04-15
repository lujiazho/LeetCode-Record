///////////////////////////////////////////////////////////////////////////////////////////////
// classic dp
////////////////
// Time Complexity: O(n*k)
// Space Complexity: O(n*k)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    // return the max value by choosing from i-th to last one piles
    int func(int i, int k, vector<vector<int>>& piles, vector<vector<int>>& dp){
        if (dp[i][k] > 0) return dp[i][k];
        if (i == piles.size() || k == 0) return 0;
        // return the max value by choosing from (i+1)-th to last one piles
        int res = func(i + 1, k, piles, dp), cur = 0;
        for (int j = 0; j < piles[i].size() && j < k; ++j) {
            cur += piles[i][j];
            res = max(res, func(i + 1, k - j - 1, piles, dp) + cur);
        }
        dp[i][k] = res;
        return res;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int K) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(K + 1, 0));
        // return the max value by choosing from 0-th to last one piles
        return func(0, K, piles, dp);
    }
};