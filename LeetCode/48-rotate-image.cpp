///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // up and down flip
        for (int i=0 ; i<n/2 ; i++)
            for (int j=0 ; j<n ; j++)
                swap(matrix[i][j], matrix[n-i-1][j]);
        // transpose flip
        for (int i=1 ; i<n ; i++)
            for (int j=0 ; j<i ; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};