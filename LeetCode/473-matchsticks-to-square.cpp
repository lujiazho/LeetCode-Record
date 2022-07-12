///////////////////////////////////////////////////////////////////////////////////////////////
// brute force, if not reverse sorted, it will run into TLE
////////////////
// Time Complexity: O(4^n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4) return false;
        int length = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (length % 4) return false;
        
        int edge = length / 4;
        for (int i=0 ; i<matchsticks.size() ; i++)
            if (matchsticks[i] > edge) return false;
        
        // c++ reverse sort
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        return dfs(edge, matchsticks, 0, 0, 0, 0, 0);
    }
    int dfs(int edge, vector<int>& matchsticks, int a, int b, int c, int d, int idx){
        if (a == edge && b == edge && c == edge && d == edge)
            return true;
        if (idx == matchsticks.size()) return false;
        if (a > edge || b > edge || c > edge || d > edge) return false;
        
        if (dfs(edge, matchsticks, a+matchsticks[idx], b, c, d, idx+1)) return true;
        if (dfs(edge, matchsticks, a, b+matchsticks[idx], c, d, idx+1)) return true;
        if (dfs(edge, matchsticks, a, b, c+matchsticks[idx], d, idx+1)) return true;
        if (dfs(edge, matchsticks, a, b, c, d+matchsticks[idx], idx+1)) return true;
        
        return false;
    }
};