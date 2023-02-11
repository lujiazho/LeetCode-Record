///////////////////////////////////////////////////////////////////////////////////////////////
// complext
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n, -1), v1(n, 0), v2(n, 0);

        // global graph
        vector<vector<pair<int, int>>> graph(n);
        for(auto &it : redEdges) graph[it[0]].push_back({it[1], 1});
        for(auto &it : blueEdges) graph[it[0]].push_back({it[1], 2});

        res[0] = 0; // init the distance from 0 to 0
        v1[0] = 1;
        v2[0] = 1;
        int temp = 1; // accumulative distance in bfs

        queue<pair<int, int>> q; // bfs stack
        for(auto &it : graph[0]) {
            // starting from each point that is next to the point 0
            q.push(it);
            if(res[it.first] == -1) res[it.first] = temp; // update the shortest path
        }

        while (!q.empty()) {
            int len = q.size();
            temp ++;
            for(int i=0 ; i<len ; i++) {
                auto val = q.front();
                q.pop();
                // if it's red path
                if(val.second == 1) v1[val.first] = 1;
                // if it's blue path
                else v2[val.first] = 1;

                // iterate each next point
                for(auto &it : graph[val.first]) {
                    // if current is achieved by red
                    // then next cannot be achieved by blue, because that's circle
                    if(val.second == 1 && (v2[it.first] || it.second==1)) continue;
                    if(val.second == 2 && (v1[it.first] || it.second==2)) continue;

                    q.push(it);
                    // only keep the shortest distance
                    if(res[it.first] == -1) res[it.first] = temp;
                }
            }
        }
        return res;
    }
};