///////////////////////////////////////////////////////////////////////////////////////////////
// classic linear dp from back to front
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(cost);

        for (int i=n-3 ; i>=0 ; i--){
            dp[i] += min(dp[i+1], dp[i+2]);
        }
        return min(dp[0], dp[1]);
    }
};