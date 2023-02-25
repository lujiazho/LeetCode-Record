///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[prices.size()][2]; // in this day's end, i,0: hold a stock; i,1: not hold
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i=1 ; i<prices.size() ; i++){
            dp[i][0] = max(dp[i-1][0], -prices[i]); // if buy, then discard before's stock
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);
        }
        // we cannot achieve maximum profit if we hold a stock
        return dp[prices.size()-1][1];
    }
};
