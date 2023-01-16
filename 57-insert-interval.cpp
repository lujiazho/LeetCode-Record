///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        for(auto i:intervals){
            if(i[1] < newInterval[0]) res.push_back(i);
            else if(newInterval[1] < i[0]){
                res.push_back(newInterval);
                newInterval = i; // substitute
            }
            // merge i and newInterval
            else{
                newInterval[0] = min(newInterval[0], i[0]);
                newInterval[1] = max(newInterval[1], i[1]);
            }    
        }
        res.push_back(newInterval);
        return res;
    }
};