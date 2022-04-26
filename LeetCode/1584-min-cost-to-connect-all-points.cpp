///////////////////////////////////////////////////////////////////////////////////////////////
// kruskal exceeds time limit
////////////////
// Time Complexity: O(mlognm), m is num of edges
// Space Complexity: O(m)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    static bool compare_dis(vector<int>& a, vector<int>& b){
        return (a[2] < b[2]);
    }
    vector<int> father;
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        int dis;
        for (int i=0 ; i<points.size() ; i++){
            for (int j=i+1 ; j<points.size() ; j++){
                dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back(vector<int>{i,j,dis});
            }
        }
        // sort with manhattan distance
        sort(edges.begin(), edges.end(), compare_dis);
        // initialize union set
        for (int i=0 ; i<points.size() ; i++)
            father.push_back(i);
        
        int res = 0;
        int a, b, w, fa, fb;
        for (int i=0 ; i<edges.size() ; i++){
            a = edges[i][0];
            b = edges[i][1];
            w = edges[i][2];
            fa = find(a);
            fb = find(b);
            if (fa != fb){
                res += w;
                connect(a,b);
            }
        }
        return res;
    }
    int find(int x){
        if (father[x] != x)
            father[x] = find(father[x]);
        return father[x];
    }
    void connect(int a, int b){
        father[find(a)] = find(b);
    }
};

// prim algorithm, much better: O(n^2)
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges(points.size(), vector<int>(points.size(), INT_MAX));
        vector<int> dist(points.size(), INT_MAX);
        vector<int> st(points.size(), 0);
        
        for (int i=0 ; i<points.size() ; i++){
            for (int j=0 ; j<points.size() ; j++){
                edges[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            }
        }
        
        int res = 0;
        for (int i=0 ; i<points.size() ; i++){
            int t=-1;
            for (int j=0 ; j<points.size() ; j++){
                if (!st[j] && (t==-1 || dist[t] > dist[j]))
                    t = j;
            }
            if (i)
                res += dist[t];
            for (int j=0 ; j<points.size() ; j++)
                dist[j] = min(dist[j], edges[t][j]);
            st[t] = 1;
        }
        return res;
    }
};