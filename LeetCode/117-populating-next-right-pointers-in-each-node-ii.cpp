///////////////////////////////////////////////////////////////////////////////////////////////
// classic breadth first search
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        vector<Node*> v;
        v.push_back(root);
        while (v.size()){
            vector<Node*> new_v;
            for (int i=0 ; i<v.size()-1 ; i++){
                v[i]->next = v[i+1];
                if (v[i]->left)
                    new_v.push_back(v[i]->left);
                if (v[i]->right)
                    new_v.push_back(v[i]->right);
            }
            v.back()->next = NULL;
            if (v.back()->left)
                new_v.push_back(v.back()->left);
            if (v.back()->right)
                new_v.push_back(v.back()->right);
            v = new_v;
        }
        return root;
    }
};