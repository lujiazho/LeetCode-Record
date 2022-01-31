///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(mn)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for (int i=0 ; i<accounts.size() ; i++){
            int wealth = 0;
            for (int j=0 ; j<accounts[i].size() ; j++)
                wealth += accounts[i][j];
            if (wealth > res) res = wealth;
        }
        return res;
    }
};