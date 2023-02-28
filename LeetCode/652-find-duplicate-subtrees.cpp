///////////////////////////////////////////////////////////////////////////////////////////////
// serializing matching
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<TreeNode*> duplicates;
    string serializeSubtrees(TreeNode* node, unordered_map<string, int>& subtrees) {
        if (!node) return "#";
        
        string left = serializeSubtrees(node->left, subtrees);
        string right = serializeSubtrees(node->right, subtrees);
        
        string s = left + "," + right + "," + to_string(node->val); // Serialize the current subtree
        
        if (subtrees[s] == 1) duplicates.push_back(node); // If a duplicate subtree is found, add to the vector
        
        subtrees[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtrees; // Store serialized subtree and its frequency
        
        serializeSubtrees(root, subtrees);
        
        return duplicates;
    }
};