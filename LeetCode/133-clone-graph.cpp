///////////////////////////////////////////////////////////////////////////////////////////////
// a bit interesting
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    unordered_map<int, Node*> m;
    Node* cloneGraph(Node* node) {
        return bfs(node);
    }
    Node* bfs(Node* node){
        if (node == NULL) return NULL;
        Node* res;
        if (m.find(node->val) == m.end()) res = new Node(node->val);
        else return m[node->val];
        m[node->val] = res;
        for (int i=0 ; i<node->neighbors.size() ; i++){
            res->neighbors.push_back(bfs(node->neighbors[i]));
        }
        return res;
    }
};