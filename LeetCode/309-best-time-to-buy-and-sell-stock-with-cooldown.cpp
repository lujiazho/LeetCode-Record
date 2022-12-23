///////////////////////////////////////////////////////////////////////////////////////////////
// just need to define state of dp
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // after ith day, dp[0] has stock, dp[1] no stock and can buy, dp[2] no stock but cooldown
        vector<int> dp{-prices[0], 0, 0}, newdp{-1, -1, -1};
        for (int i=1 ; i<prices.size() ; i++) {
            newdp = {max(dp[0], dp[1] - prices[i]), max(dp[1], dp[2]), dp[0] + prices[i]};
            dp = newdp;
        }
        return max(dp[0], max(dp[1], dp[2]));
    }
};