///////////////////////////////////////////////////////////////////////////////////////////////
// hard, ordered map for binary search and fast access
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // num of jobs
        int n = startTime.size();
        vector<vector<int>> jobs;
        
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        // sort by endTime
        sort(jobs.begin(), jobs.end());
        // dp[i]: within i duration, the profit can be made as most
        map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            // find the near time before this job's start time, add the total profit
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            // if the total profit is higher than the highest profit, then we do it
            // dp.rbegin() must point to the highest profit
            if (cur > dp.rbegin()->second) dp[job[0]] = cur;
        }
        // return the highest profit
        return dp.rbegin()->second;
    }
};