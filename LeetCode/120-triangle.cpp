///////////////////////////////////////////////////////////////////////////////////////////////
// linear dp
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle);
        for (int i=1 ; i<dp.size() ; i++){
            for (int j=0 ; j<=i ; j++){
                if (j == 0)
                    dp[i][j] += dp[i-1][j];
                else if (j == i)
                    dp[i][j] += dp[i-1][j-1];
                else
                    dp[i][j] += min(dp[i-1][j-1], dp[i-1][j]);
            }
        }
        int res = INT_MAX;
        for (int i=0 ; i<dp.back().size() ; i++) res = min(res, dp.back()[i]);
        return res;
    }
};