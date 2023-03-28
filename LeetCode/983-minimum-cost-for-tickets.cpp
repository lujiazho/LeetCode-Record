///////////////////////////////////////////////////////////////////////////////////////////////
// classic dp
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // dp[i]: minimum cost for travel fee in the first i days
        int dp[366] = {0};

        unordered_set<int> travelDays;
        for (int day : days) travelDays.insert(day);

        for (int i = 1; i <= 365; i++) {
            if (travelDays.find(i) == travelDays.end()) dp[i] = dp[i-1];
            else {
                int buy1day = dp[i-1] + costs[0];
                int buy7day = dp[max(0, i-7)] + costs[1];
                int buy30day = dp[max(0, i-30)] + costs[2];
                dp[i] = min(buy1day, min(buy7day, buy30day));
            }
        }
        return dp[365];
    }
};