///////////////////////////////////////////////////////////////////////////////////////////////
// easy, just 2-d binary search
////////////////
// Time Complexity: O(logn)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st = 0, ed = matrix.size()*matrix[0].size()-1, mid;
        int x,y;
        while (st<ed){
            mid = (st + ed) >> 1;
            x = mid/matrix[0].size();
            y = mid%matrix[0].size();
            if (matrix[x][y] < target)
                st = mid + 1;
            else
                ed = mid;
        }
        if (matrix[ed/matrix[0].size()][ed%matrix[0].size()] == target)
            return true;
        return false;
    }
};