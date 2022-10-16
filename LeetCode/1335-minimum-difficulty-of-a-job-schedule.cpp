///////////////////////////////////////////////////////////////////////////////////////////////
// really hard
////////////////
// Time Complexity: O(n*d)
// Space Complexity: O(n*d)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    const int INF = 10000000;
    int n;
    int dp[305][15];
    int dfs(int i,int d,vector <int> &jd) {
        // if all jobs done and no day left
        if(i==n && d==0) return 0;
        // not all jobs done but left day || no day left but some not done || not enough days
        if(i==n || d==0 || n-i<d) return INF;
        
        if(dp[i][d]!=-1) return dp[i][d];
        
        int ans=INF;
        int maxele=-INF;
        // traverse how many jobs should be done for this day
        for(int j=i;j<n;j++) {   
            maxele=max(maxele,jd[j]);            // max element from i to j
            ans=min(ans,maxele+dfs(j+1,d-1,jd)); // minimum of all possible answers
        }
        dp[i][d]=ans;
        return ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if(n<d) return -1;
        
        memset(dp,-1,sizeof(dp));
        
        return dfs(0,d,jobDifficulty);
    }
};