///////////////////////////////////////////////////////////////////////////////////////////////
// easy bfs
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        vector<TreeNode*> v;
        v.push_back(root);
        
        int res = 0;
        while (v.size()){
            vector<TreeNode*> new_v;
            for (int i=0 ; i<v.size() ; i++){
                if (v[i]->left) new_v.push_back(v[i]->left);
                if (v[i]->right) new_v.push_back(v[i]->right);
            }
            if (new_v.size())
                v = new_v;
            else{
                for (int i=0 ; i<v.size() ; i++)
                    res += v[i]->val;
                return res;
            }
        }
        return -1;
    }
};