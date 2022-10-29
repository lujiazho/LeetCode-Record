///////////////////////////////////////////////////////////////////////////////////////////////
// greedy
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        // growTime larger first
        vector<pair<int, int>> times(n);
        // we plant the flower that has largest grow time first
        for (int i = 0; i < n; i++) {
            times[i].first = -growTime[i];
            times[i].second = plantTime[i];
        }
        sort(times.begin(), times.end());
        int res = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, cur + times[i].second - times[i].first);
            // jump to the second that this flower is planted already
            cur += times[i].second;
        }
        return res;
    }
};