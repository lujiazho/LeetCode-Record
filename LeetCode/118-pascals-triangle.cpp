///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(numRows^2)
// Space Complexity: O(numRows)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return vector<vector<int>>({{1}});
        vector<vector<int>> res{{1},{1,1}};
        
        while (res.back().size() < numRows){
            vector<int> v{1};
            for (int i=0 ; i<res.back().size()-1 ; i++){
                v.push_back(res.back()[i]+res.back()[i+1]);
            }
            v.push_back(1);
            res.push_back(v);
        }
        return res;
    }
};