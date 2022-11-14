///////////////////////////////////////////////////////////////////////////////////////////////
// good solution without using union set, just use dfs to count the number of unions
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void dfs(vector<vector<int>>&stones,int idx,vector<bool>&visited,int&n){
        visited[idx]=true;
        for(int i=0;i<n;i++)
            if(!visited[i]&&(stones[i][0]==stones[idx][0]||stones[i][1]==stones[idx][1]))
                dfs(stones,i,visited,n);
        
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n,0);
        // count is the number of unconnected union
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]){continue;}
            // each dfs would set all stones in continuous place as visited
            dfs(stones,i,visited,n);
            count++;
        }
        // for each union, we have to left one stone that cannot be removed
        return n-count;
    }
};