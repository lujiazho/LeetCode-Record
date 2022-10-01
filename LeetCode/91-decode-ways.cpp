///////////////////////////////////////////////////////////////////////////////////////////////
// classic dp
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numDecodings(string s) {
        if (!s.length()) return 0;
        if (s[0] == '0') return 0;
        
        // dp[i]: ways of decode with first i digits (must be used)
        vector<int> dp(s.length(), 0);

        dp[0] = 1;

        for (int i=1 ; i<s.length() ; i++) {
            int s1 = stoi(s.substr(i, 1));
            if (0 < s1) dp[i] += dp[i - 1];
            
            int s2 = stoi(s.substr(i-1, 2));
            if (10 <= s2 && s2 <= 26) dp[i] += i-2>=0?dp[i - 2]:1;
        }
            
        return dp.back();
    }
};