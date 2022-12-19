///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int find(vector<int> &father, int i) {
        if (father[i] != i) father[i] = find(father, father[i]);
        return father[i];
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> father(n, 0);
        for (int i=0 ; i<n ; i++) father[i] = i;
        for (int i=0 ; i<edges.size() ; i++) {
            int fa=find(father, edges[i][0]);
            int fb=find(father, edges[i][1]);
            if (fa != fb) father[fa] = fb;
        }
        for (int i=0 ; i<n ; i++) cout << i << " " << father[i] << endl;
        return find(father, source) == find(father, destination);
    }
};
