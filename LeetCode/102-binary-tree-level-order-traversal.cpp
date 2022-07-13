///////////////////////////////////////////////////////////////////////////////////////////////
// classic bfs
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode*> cur;
        if (root) cur.push_back(root);
        while (cur.size()){
            vector<TreeNode*> tmp;
            vector<int> vals;
            for (int i=0 ; i<cur.size() ; i++){
                vals.push_back(cur[i]->val);
                if (cur[i]->left) tmp.push_back(cur[i]->left);
                if (cur[i]->right) tmp.push_back(cur[i]->right);
            }
            res.push_back(vals);
            cur = tmp;
        }
        return res;
    }
};