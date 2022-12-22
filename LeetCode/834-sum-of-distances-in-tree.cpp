///////////////////////////////////////////////////////////////////////////////////////////////
// hard
////////////////
// Time Complexity: O(N)
// Space Complexity: O(N)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<unordered_set<int>> tree;
    vector<int> res, count;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        tree.resize(N);
        res.assign(N, 0);
        // counts of all nodes in ith subtree (including ith node)
        // Note: root is 0th node
        count.assign(N, 1);
        for (auto e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        // only get total distance from bottom to top
        dfs(0, -1);
        // give the distance from l/r to r/l
        dfs2(0, -1);
        return res;
    }

    void dfs(int root, int pre) {
        // traverse all directly connected neighbors
        for (auto i : tree[root]) {
            // skip the node this root came from
            if (i == pre) continue;
            // this means from bottom to top
            dfs(i, root);
            // add counts of children node
            count[root] += count[i];
            // add sum to children node and counts to get the distance to this root node
            res[root] += res[i] + count[i];
        }
    }

    void dfs2(int root, int pre) {
        // traverse all directly connected neighbors (children)
        for (auto i : tree[root]) {
            // not the father node
            if (i == pre) continue;
            // count.size() - count[i]: counts of all other nodes except the nodes in ith subtree
            // res[root] - count[i]: distances except the edge from ith to this root
            res[i] = res[root] - count[i] + count.size() - count[i];
            dfs2(i, root);
        }
    }
};