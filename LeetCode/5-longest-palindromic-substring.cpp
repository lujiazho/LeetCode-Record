///////////////////////////////////////////////////////////////////////////////////////////////
// classic interval dp
////////////////
// Time Complexity: O(n*n)
// Space Complexity: O(n*n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1) return s;
        string res = s.substr(0, 1);
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        for (int i=0 ; i<s.length() ; i++) dp[i][i] = true;
        
        for (int i=2 ; i<=s.length() ; i++){ // length
            for (int j=0 ; j<s.length()-i+1 ; j++){
                if (s[j] == s[j+i-1]){
                    if (j+1 <= j+i-2)
                        dp[j][j+i-1] = dp[j+1][j+i-2];
                    else
                        dp[j][j+i-1] = true;
                    if (dp[j][j+i-1] and i > res.length())
                        res = s.substr(j, i);
                }
            }
        }
        return res;
    }
};