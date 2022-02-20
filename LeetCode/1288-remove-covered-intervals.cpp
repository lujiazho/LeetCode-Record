///////////////////////////////////////////////////////////////////////////////////////////////
// happy brute force
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        unordered_set<pair<int,int>, pair_hash> s;
        int res = intervals.size();
        for (int i=0 ; i<intervals.size() ; i++){
            for (int j=0 ; j<intervals.size() ; j++){
                if (i != j && intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1]){
                    if (s.find(pair<int,int>(intervals[j][0], intervals[j][1])) == s.end()){
                        res -= 1;
                        s.insert(pair<int,int>(intervals[j][0], intervals[j][1]));
                    }
                }
            }
        }
        return res;
    }
};