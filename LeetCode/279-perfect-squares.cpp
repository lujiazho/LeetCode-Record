///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numSquares(int n) {
        // dp[i]: least number of perfect square numbers that sum to number i
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for (int i=1 ; i<n+1 ; i++) {
            for (int j=1 ; j*j <=i ; j++) {
                dp[i] = min(dp[i-j*j]+1, dp[i]);
            }
        }
        return dp[n];
    }
};