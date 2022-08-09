///////////////////////////////////////////////////////////////////////////////////////////////
// not so easy dp
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long res = 0;
        int MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());
        
        // dp[key]: let arr[key] as root, number of binary trees we can make
        unordered_map<int, long long> dp;
        for (int i=0 ; i<arr.size() ; i++){
            dp[arr[i]] = 1; // initialize, each value itself can be a tree
            for (int j=0 ; j<i ; j++){
                if (arr[i] % arr[j] == 0)
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]]*dp[arr[i]/arr[j]]) % MOD;
            }
            dp[arr[i]] %= MOD;
            res += dp[arr[i]];
        }
        return res % MOD;
    }
};