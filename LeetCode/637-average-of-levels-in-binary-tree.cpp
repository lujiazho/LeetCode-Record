///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<TreeNode*> stack{root};
        while (!stack.empty()){
            vector<TreeNode*> nex;
            double cur = 0;
            for (int i=0 ; i<stack.size() ; i++){
                cur += stack[i]->val;
                if (stack[i]->left) nex.push_back(stack[i]->left);
                if (stack[i]->right) nex.push_back(stack[i]->right);
            }
            res.push_back(cur*1.0/stack.size());
            stack = nex;
        }
        return res;
    }
};