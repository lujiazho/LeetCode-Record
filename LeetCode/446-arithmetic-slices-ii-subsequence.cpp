///////////////////////////////////////////////////////////////////////////////////////////////
// not really easy, this is my second time doing it
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // dp[i][j]: the number of sub-sequence which is ending at ith number with difference of j
        vector<unordered_map<long long, int>> dp(n);
        for (int i = 1; i < n; i++) { // for each numebr 
            for (int j = 0; j < i; j++) { // traverse each previous number
                // get difference
                long long diff = (long long) nums[i] - nums[j];
                // get accumulated number of subsequence
                int cnt = dp[j].count(diff) ? dp[j][diff] : 0;
                // add it
                ans += cnt;
                // add a new potential subsequence which is formed by jth and ith
                dp[i][diff] += cnt + 1;
            }
        }
        return ans;
    }
};