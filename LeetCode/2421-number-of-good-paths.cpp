///////////////////////////////////////////////////////////////////////////////////////////////
// hard, not fully understand this algo
////////////////
// Time Complexity: O(mlogm)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int find(vector<int>& parent, int a) {
        if (parent[a] != a) parent[a] = find(parent, parent[a]);
        return parent[a];
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<int> parent(n);
        // the count of elements in each connected component
        map<int, int> count;

        // initialize the parent vector and maps
        for(int i=0 ; i<n ; i++){
            parent[i] = i;
            count[i] = 1;
        }

        // sort the edges based on the maximum value of the vertices in the edge
        sort(edges.begin(), edges.end(), [&](const vector<int>& a, vector<int>& b)
        {
            int m = max(vals[a[0]], vals[a[1]]);
            int n = max(vals[b[0]], vals[b[1]]);
            return m<n;
        });

        int res = n; // each single node counts
        // for each edge, find the connected components of the vertices and union them
        for (auto edge : edges){
            int a = find(parent, edge[0]);
            int b = find(parent, edge[1]);
            // if cannot be a pair of start and end points, connect them
            if (vals[a] != vals[b]){
                // bigger one be the parent
                if (vals[a] > vals[b]) parent[b] = a;
                else parent[a] = b;
            } 
            // if could be a pair
            else {
                // a is less than b
                parent[a] = b;
                // the count is not the count of the union, but 
                res += count[a] * count[b];
                count[b] += count[a];
            }
        }

        return res;
    }
};