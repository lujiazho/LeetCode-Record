///////////////////////////////////////////////////////////////////////////////////////////////
// traverse two tree respectively, and use heap to store value
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> heap;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        dfs(root2);
        vector<int> res;
        while (heap.size()){
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
    void dfs(TreeNode* node){
        if (!node) return;
        heap.push(node->val);
        dfs(node->left);
        dfs(node->right);
    }
};