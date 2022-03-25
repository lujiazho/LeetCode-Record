///////////////////////////////////////////////////////////////////////////////////////////////
// greedy method
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    static bool compare_2_vals(vector<int>& a, vector<int>& b){
        return (a[0]+1000-a[1] < b[0]+1000-b[1]); // we need a[0] as small and b[0] as big as possible
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), compare_2_vals);
        int res = 0, N = costs.size()/2;
        for (int i=0 ; i<costs.size() ; i++)
            res += i<N?costs[i][0]:costs[i][1];
        return res;
    }
};