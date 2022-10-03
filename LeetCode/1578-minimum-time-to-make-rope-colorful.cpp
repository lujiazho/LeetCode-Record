///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0, max_cost = 0, sum_cost = 0, n = colors.size();
        
        
        for (int i = 0; i < n; ++i) {
            if (i > 0 && colors[i] != colors[i - 1]) {
                // end of last color, we take away all balloons that is not the most costful one
                res += sum_cost - max_cost;
                sum_cost = max_cost = 0;
            }
            // accumulate consecutive same-color cost
            sum_cost += neededTime[i];
            max_cost = max(max_cost, neededTime[i]);
        }
        res += sum_cost - max_cost;
        
        return res;
    }
};