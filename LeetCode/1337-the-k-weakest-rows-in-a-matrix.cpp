///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    static bool compare_2_vals(vector<int>& a, vector<int>& b){
        if (a[1] != b[1])
            return (a[1] < b[1]);
        return (a[0] < b[0]);
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> soldierNum;
        for (int i=0 ; i<mat.size() ; i++){
            int num = 0;
            for (int j=0 ; j<mat[0].size() ; j++){
                if (!mat[i][j]) break;
                num++;
            }
            soldierNum.push_back(vector<int>{i, num});
        }
        sort(soldierNum.begin(), soldierNum.end(), compare_2_vals);
        vector<int> res;
        for (int i=0 ; i<k ; i++){
            res.push_back(soldierNum[i][0]);
        }
        return res;
    }
};