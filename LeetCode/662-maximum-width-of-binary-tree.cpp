///////////////////////////////////////////////////////////////////////////////////////////////
// a liitle hard because the time complexity is sky high and we need to use bfs and bit mask
////////////////
// Time Complexity: O(n*(2^n)), for each point, it has 2^n states
// Space Complexity: O(n*(2^n))
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(); // num of points
        int mask = (1<<n)-1; // bit masking
        vector<pair<int, int>> v; // for bfs <point, mask>
        unordered_set<string> s;
        for (int i=0 ; i<graph.size() ; i++){
            v.push_back(pair<int, int>(i, (1<<i)));
            s.insert(to_string(i)+" "+to_string(1<<i));
        }
        int res = 0;
        while (v.size()){
            vector<pair<int, int>> new_v;
            for (int i=0 ; i<v.size() ; i++){
                int cur_point = v[i].first;
                int cur_mask = v[i].second;
                if (cur_mask == mask){
                    return res;
                }
                for (int j=0 ; j<graph[cur_point].size() ; j++){
                    int nex = graph[cur_point][j];
                    int nex_mask = cur_mask | (1<<nex);
                    string hash = to_string(nex)+" "+to_string(nex_mask);
                    if (s.find(hash) == s.end()){
                        new_v.push_back(pair<int,int>(nex, nex_mask));
                        s.insert(hash);
                    }
                }
            }
            v = new_v;
            res += 1;
        }
        return res;
    }
};