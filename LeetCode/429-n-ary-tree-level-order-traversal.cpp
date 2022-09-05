///////////////////////////////////////////////////////////////////////////////////////////////
// easy bfs
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        vector<Node*> stack{root};
        while (!stack.empty()){
            vector<Node*> nex_stack;
            vector<int> cur;
            for (int i=0 ; i<stack.size() ; i++){
                cur.push_back(stack[i]->val);
                for (int j=0 ; j<(stack[i]->children).size() ; j++){
                    nex_stack.push_back(stack[i]->children[j]);
                }
            }
            stack = nex_stack;
            res.push_back(cur);
        }
        return res;
    }
};