///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(mn)
// Space Complexity: O(mn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(), n=text2.size();
        // dp[i][j]: first i of text1, first j of text2, the len of longest common subsequence
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // dp[0][j] and dp[i][0] are 0 in default
        for (int i=1 ; i<m+1 ; i++) {
            for (int j=1 ; j<n+1 ; j++) {
                if (text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]));
            }
        } 
        return dp[m][n];
    }
};