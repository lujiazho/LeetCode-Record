///////////////////////////////////////////////////////////////////////////////////////////////
// not easy
////////////////
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // v[i][j]: first i elements in s1 and first j elements in s2 
        // True: can be formed by interleaving: first i+j in s3; False: cannot
        vector<vector<int>> v(s1.size()+1, vector<int>(s2.size()+1, false));
        v[0][0] = true;
        
        int n = s1.size(), m = s2.size(), t = s3.size();
        if (n + m != t) return false;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                int p = i + j - 1;
                
                if (i > 0) v[i][j] |= (v[i-1][j] && s1[i-1] == s3[p]);
                if (j > 0) v[i][j] |= (v[i][j-1] && s2[j-1] == s3[p]);
            }
        }

        return v[n][m];
    }
};