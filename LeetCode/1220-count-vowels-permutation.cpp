///////////////////////////////////////////////////////////////////////////////////////////////
// easy dp
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n), can be further reduced
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countVowelPermutation(int n) {
        // dp[0][i]: ending by 'a' and length is i, max num
        vector<vector<long long>> dp(5, vector<long long>(n+1, 0));
        for (int i=0 ; i<5 ; i++) dp[i][1] = 1;
        int MOD = 1e9 + 7;
        
        for (int j=2 ; j<=n ; j++){
            for (int i=0 ; i<5 ; i++){
                if (i == 0){
                    dp[i][j] = (dp[1][j-1] + dp[2][j-1] + dp[4][j-1])%MOD;
                }else if (i == 1){
                    dp[i][j] = (dp[0][j-1] + dp[2][j-1])%MOD;
                }else if (i == 2){
                    dp[i][j] = (dp[1][j-1] + dp[3][j-1])%MOD;
                }else if (i == 3){
                    dp[i][j] = (dp[2][j-1])%MOD;
                }else if (i == 4){
                    dp[i][j] = (dp[2][j-1] + dp[3][j-1])%MOD;
                }
            }
        }
        return (dp[0][n] + dp[1][n] + dp[2][n] + dp[3][n] + dp[4][n])%MOD;
    }
};