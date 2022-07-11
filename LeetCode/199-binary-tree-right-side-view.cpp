///////////////////////////////////////////////////////////////////////////////////////////////
// easy bfs
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    
    vector<int> rightSideView(TreeNode* root) {
        vector<TreeNode*> v;
        vector<int> res;
        if (root) v.push_back(root);
        while (v.size()){
            res.push_back(v.back()->val);
            vector<TreeNode*> cur;
            for (int i=0 ; i<v.size() ; i++){
                if (v[i]->left)
                    cur.push_back(v[i]->left);
                if (v[i]->right)
                    cur.push_back(v[i]->right);
            }
            v = cur;
        }
        
        return res;
    }
};