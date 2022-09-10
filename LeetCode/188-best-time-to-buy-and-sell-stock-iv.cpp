///////////////////////////////////////////////////////////////////////////////////////////////
// very hard, we need two dp array for assisting state transition
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-iv-by-8xtkp/
////////////////
// Time Complexity: O(n*k)
// Space Complexity: O(n*k)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;

        int n = prices.size();
        k = min(k, n / 2); // we can only have n/2 transaction as most

        // buy[i][j]: in first i stocks, have exactly finished j transactions, and still got on stock in hand
        vector<vector<int>> buy(n, vector<int>(k + 1));
        // sell[i][j]: in first i stocks, have exactly finished j transactions, and got no stock in hand
        vector<vector<int>> sell(n, vector<int>(k + 1));

        // initialization
        buy[0][0] = -prices[0];
        sell[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            buy[0][i] = sell[0][i] = INT_MIN / 2;
        }

        for (int i = 1; i < n; ++i) {
            buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);   
            }
        }

        return *max_element(sell[n - 1].begin(), sell[n - 1].end());
    }
};