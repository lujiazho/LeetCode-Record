///////////////////////////////////////////////////////////////////////////////////////////////
// not really hard
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int s = matrix.size();

        // traverse each row
        for(int i = 1; i < s; i++) {
            for(int j = 0; j < s; j++) {
                // up
                int mn = matrix[i - 1][j];
                // left up
                if(j > 0) mn = min(mn, matrix[i - 1][j - 1]);
                // right up
                if(j < s - 1) mn = min(mn, matrix[i - 1][j + 1]);
                // add the minimum
                matrix[i][j] += mn;
            }
        }
        int res = INT_MAX;
        for(int j = 0; j < s; j++) res = min(res, matrix[s - 1][j]);
        return res;
    }
};