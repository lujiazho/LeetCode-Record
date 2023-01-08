///////////////////////////////////////////////////////////////////////////////////////////////
// interesting
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxPoints(vector<vector<int>>& pt) {
        int res = 1; 
        int n = pt.size();
        // slope of every point with selected point
        for (int i=0 ; i<n-1 ; i++) {
            map<double,int> mp;
            for (int j=i+1 ; j<n ; j++) {
                // slope
                double x = (double)(pt[j][1]-pt[i][1])/(double)(pt[j][0]-pt[i][0]);
                // infinite slope for Perpendicular line: inf or -inf
                if (pt[j][0]-pt[i][0] == 0) mp[abs(x)]++;
                else mp[x]++;
            }
            // same slope w.r.t. current selected point
            int temp = 0;
            for (auto it:mp) temp = max(temp, it.second+1); // +1 for the current point
            res = max(temp, res);
        }
        return res;
    }
};