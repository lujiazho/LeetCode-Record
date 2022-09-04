///////////////////////////////////////////////////////////////////////////////////////////////
// hard, this solution used map and set, which have ordering by default
// if python, it's hard to use this method
////////////////
// Time Complexity: O(nlogn), logn is for map and set ordering
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map & set is in increasing order by default
        // unordered_map & unordered_set have no ordering
        map<int, map<int, multiset<int>>> nodes;
        traverse(root, 0, 0, nodes);
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                // vector.insert: push_back multi-elements at once
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
    void traverse(TreeNode* root, int x, int y, map<int, map<int, multiset<int>>>& nodes) {
        if (root) {
            nodes[x][y].insert(root -> val);
            traverse(root -> left, x - 1, y + 1, nodes);
            traverse(root -> right, x + 1, y + 1, nodes);
        }
    }
};