///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        int level = 0;
        queue<TreeNode*> q; // bfs stack
        q.push(root);  
        
        while (!q.empty()) {
            int sz = q.size();  
            vector<int> curr(sz); 
            
            for (int i = 0; i < sz; i++) {
                TreeNode* tmp = q.front();
                q.pop();

                if (level % 2 == 0) curr[i] = tmp->val;
                else curr[sz - i - 1] = tmp->val;
                
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            res.push_back(curr);
            level ++;
        }
        return res;
    }
};