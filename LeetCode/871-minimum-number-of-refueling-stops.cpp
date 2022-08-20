///////////////////////////////////////////////////////////////////////////////////////////////
// other's method, not easy to understand because this is actually improved version imo.
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // dp[i]: farest distance can be achieved when only fuel i times
        long dp[501] = {startFuel};
        
        for (int i=0 ; i<stations.size() ; i++) { // traverse each station
            for (int t=i ; t>=0 && dp[t]>=stations[i][0] ; t--) {
                // if previous calculated farest distance reached this station
                dp[t + 1] = max(dp[t + 1], dp[t] + stations[i][1]);
            }
        }
        
        for (int t = 0; t <= stations.size(); t++) if (dp[t] >= target) return t;
        return -1;
    }
};


// originally it should look like
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // dp[i][j]: farest distance can be achieved when fuel exactly j times from front i stations
        // i >= j
        vector<vector<long>> dp(501, vector<long>(501, 0));
        for (int i=0 ; i<=stations.size() ; i++) dp[i][0] = startFuel;
        
        for (int i=1 ; i<=stations.size() ; i++) {
            for (int j=1 ; j<=i ; j++) {
                dp[i][j] = dp[i-1][j]; // choose to not fuel in this station
                if (dp[i-1][j-1] >= stations[i-1][0]) // only fuel when station can be touch
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + stations[i-1][1]);
            }
        }
        
        for (int j=0; j<=stations.size(); j++) if (dp[stations.size()][j] >= target) return j;
        return -1;
    }
};