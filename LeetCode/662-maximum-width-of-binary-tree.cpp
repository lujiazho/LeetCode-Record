///////////////////////////////////////////////////////////////////////////////////////////////
// not so hard, the only trick is that I have to use long long
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<TreeNode*, long long>> v; // node:idx
        v.push_back(pair<TreeNode*, long long>(root, 0));
        long long res = 0;
        while (v.size()){
            res = max(res, (v[v.size()-1].second-v[0].second+1));
            vector<pair<TreeNode*, long long>> newv;
            for (int i=0 ; i<v.size() ; i++){
                if (v[i].first->left) newv.push_back(pair<TreeNode*, long long>(v[i].first->left, (v[i].second-v[0].second)*2+1));
                if (v[i].first->right) newv.push_back(pair<TreeNode*, long long>(v[i].first->right, (v[i].second-v[0].second)*2+2));
            }
            v = newv;
        }
        return res;
    }
};
