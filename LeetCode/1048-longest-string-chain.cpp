///////////////////////////////////////////////////////////////////////////////////////////////
// sort + dp + common subsequence
////////////////
// Time Complexity: O(n*n*max_length)
// Space Complexity: O(nlogn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    static bool comp(string &s1, string &s2)
    {
        return s1.length()<s2.length()?true:false;
    }
    bool ok(string s1, string s2){
        if (s1.length() - s2.length() != 1) return false;
        int i=0, j=0;
        while (i<s1.length()){
            if (s1[i] == s2[j]){
                i ++;
                j ++;
            }else
                i++;
            if (i - j > 1) break;
        }
        if (i == s1.length() && j == s2.length()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n+1, 1);
        
        int res = 1;
        for (int i=2 ; i<n+1 ; i++){
            for (int j=1 ; j<i ; j++){
                if (ok(words[i-1], words[j-1])) dp[i] = max(dp[i], dp[j]+1);
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};